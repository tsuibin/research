#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlRecord>

#include "emenudata.h"
#include "emenuenv.h"

EmenuData::EmenuData()
{
}

void EmenuData::loadData()
{
    this->m_dataBase = QSqlDatabase::addDatabase("QSQLITE");
    this->m_dataBase.setDatabaseName(EmenuEnv::dataBasePath);
    if (this->m_dataBase.open() == false) {
        qDebug() << "EmenuData::loadData: the localdb open error!";
        return;
    }

    this->clearData();

    QSqlQuery localQuery;

    DishData *dishData = 0;
    localQuery.exec("select dishid, dishname, kindid, price, info, picurl, speciality, pinyin, alias from dish where valid = '1'");
    while (localQuery.next()) {
        dishData = new DishData();
        dishData->dishId = localQuery.value(0).toInt();
        dishData->name = localQuery.value(1).toString();
        dishData->kindId = localQuery.value(2).toInt();
        dishData->price = localQuery.value(3).toString();
        dishData->info = localQuery.value(4).toString();
        dishData->pic = localQuery.value(5).toString();
        dishData->speciality = localQuery.value(6).toString();
        this->m_dishDataList.append(dishData);
        this->m_dishIdMap.insert(dishData->dishId,dishData);
    }

    DiscountData *discountData  = 0;
    localQuery.exec("select  priceoffid, seq, oldprice, dishid from priceoff");
    while (localQuery.next()) {
        discountData = new DiscountData();
        discountData->discountId = localQuery.value(0).toInt();
        discountData->seq = localQuery.value(1).toInt();
        discountData->oldPrice = localQuery.value(2).toString();
        discountData->dishId = localQuery.value(3).toInt();
        discountData->dishData = this->m_dishIdMap.value(discountData->dishId);
        this->m_discountDataList.append(discountData);
    }

    RankData *rankData = 0;
    localQuery.exec("select  toptenid, seq, dishid, upordown from topten order by seq");
    while (localQuery.next()) {
        rankData = new RankData();
        rankData->rankId = localQuery.value(0).toInt();
        rankData->seq = localQuery.value(1).toInt();
        rankData->dishId = localQuery.value(2).toInt();
        rankData->isUp = localQuery.value(3).toBool();
        rankData->dishData = this->m_dishIdMap.value(rankData->dishId);
        this->m_rankDataList.append(rankData);
    }

    RecommendationData *recommendationData = 0;
    localQuery.exec("select  recommondationid, seq, staffid, recommondation, dishid from recommondation order by seq");
    while (localQuery.next()) {
        recommendationData = new RecommendationData();
        recommendationData->recommendationId = localQuery.value(0).toInt();
        recommendationData->seq = localQuery.value(1).toInt();
        recommendationData->staffid = localQuery.value(2).toInt();
        recommendationData->recommendation = localQuery.value(3).toString();
        recommendationData->dishId = localQuery.value(4).toInt();
        recommendationData->dishData = this->m_dishIdMap.value(recommendationData->dishId);
        this->m_recommendationDataList.append(recommendationData);
    }


    StoryData *storyData = 0;
    localQuery.exec("select storyid, story, seq, dishid from story order by seq");
    while (localQuery.next()) {
        storyData = new StoryData();
        storyData->storyId = localQuery.value(0).toInt();
        storyData->story = localQuery.value(1).toString();
        storyData->seq = localQuery.value(2).toInt();
        storyData->dishId = localQuery.value(3).toInt();
        storyData->dishData = this->m_dishIdMap.value(storyData->dishId);
        this->m_storyDataList.append(storyData);
    }

    int id;
    int dishId;
    HealthData *healthData = 0;
    localQuery.exec("select hk.healthkindid, hk.healthkindname, h.healthrank, h.dishid,h.seq, h.healthinfo from health as h left join healthkind as hk on h.healthkindid=hk.healthkindid order by h.seq");
    while (localQuery.next()) {
        id = localQuery.value(0).toInt();
        if (this->m_healthDataMap.keys().contains(id) == false) {
            healthData = new HealthData();
            healthData->healthKindId = id;
            healthData->healthKindname = localQuery.value(1).toString();
            healthData->rankList.append(localQuery.value(2).toInt());
            healthData->dishIdList.append(localQuery.value(3).toInt());
            healthData->seqList.append(localQuery.value(4).toInt());
            healthData->infoList.append(localQuery.value(5).toString());
            healthData->dishDataList.append(this->m_dishIdMap.value(id));
            this->m_healthDataMap.insert(id,healthData);
        } else {
            this->m_healthDataMap.value(id)->rankList.append(localQuery.value(2).toInt());
            this->m_healthDataMap.value(id)->dishIdList.append(localQuery.value(3).toInt());
            this->m_healthDataMap.value(id)->seqList.append(localQuery.value(4).toInt());
            this->m_healthDataMap.value(id)->infoList.append(localQuery.value(5).toString());
            this->m_healthDataMap.value(id)->dishDataList.append(this->m_dishIdMap.value(id));
        }
    }

    CategoryData *categoryData = 0;
    id = 0;
    dishId = 0;
    localQuery.exec("select c.id,c.pid,c.name,dc.did from category as c left join dishcategory as dc on dc.cid=c.id where did");
    while (localQuery.next()) {
        id = localQuery.value(0).toInt();
        dishId = localQuery.value(3).toInt();
        if (this->m_categoryIdMap.keys().contains(id) == false) {
            categoryData = new CategoryData();
            categoryData->categoryId = id;
            categoryData->pid = localQuery.value(1).toInt();
            categoryData->name = localQuery.value(2).toString();
            categoryData->dishIdList.append( dishId );
            categoryData->dishDataList.append(this->m_dishIdMap.value( dishId ));
            this->m_categoryIdMap.insert(id,categoryData);
        } else {
             this->m_categoryIdMap.value(id)->dishIdList.append( dishId );
             this->m_categoryIdMap.value(id)->dishDataList.append( this->m_dishIdMap.value( dishId ));
        }
    }
}

void EmenuData::clearData()
{
    for (int i = 0; i < this->m_dishDataList.size(); i++) {
        delete this->m_dishDataList.at(i);
    }
    this->m_dishDataList.clear();
    this->m_dishIdMap.clear();

    for (int i = 0; i < this->m_discountDataList.size(); i++) {
        delete this->m_discountDataList.at(i);
    }
    this->m_discountDataList.clear();

    for (int i = 0; i < this->m_rankDataList.size(); i++) {
        delete this->m_rankDataList.at(i);
    }
    this->m_rankDataList.clear();

    for (int i = 0; i < this->m_recommendationDataList.size(); i++) {
        delete this->m_recommendationDataList.at(i);
    }
    this->m_recommendationDataList.clear();

    for (int i = 0; i < this->m_storyDataList.size(); i++) {
        delete this->m_storyDataList.at(i);
    }
    this->m_storyDataList.clear();

}

const QList <const DishData *> * EmenuData::getDishDataList()
{
    return &this->m_dishDataList;
}

const QMap <int, const DishData *> * EmenuData::getDishDataMap()
{
    return &this->m_dishIdMap;
}

const QMap <int, CategoryData *> * EmenuData::getCategoryDataMap()
{
    return &this->m_categoryIdMap;
}

const QMap <int, HealthData *> * EmenuData::getHealthDataMap()
{
    return &this->m_healthDataMap;
}

const QList <const DiscountData *> * EmenuData::getDiscountData()
{
    return &this->m_discountDataList;
}

const QList <const RankData *> * EmenuData::getRankDataList()
{
    return &this->m_rankDataList;
}

const QList <const RecommendationData *> * EmenuData::getRecommendationDataList()
{
    return &this->m_recommendationDataList;
}

const QList <const StoryData *> * EmenuData::getStoryDataList()
{
    return &this->m_storyDataList;
}

//const QList <const HealthData *> * EmenuData::getHealthDataList()
//{
//    return &this->m_healthDataList;
//}
