#ifndef EMENUDATA_H
#define EMENUDATA_H

#include <QList>
#include <QMap>
#include <QSqlDatabase>

#include "dishdata.h"

class EmenuData
{
public:
    EmenuData();
    void loadData();

    const QList <const DishData *> * getDishDataList();
    const QMap <int, const DishData *> * getDishDataMap();
    const QMap <int, CategoryData *> * getCategoryDataMap();
    const QMap <int, HealthData *> * getHealthDataMap();

    const QList <const DiscountData *> * getDiscountData();
    const QList <const RankData *> * getRankDataList();
    const QList <const RecommendationData *> * getRecommendationDataList();
    const QList <const StoryData *> * getStoryDataList();
    const QList <const HealthData *> * getHealthDataList();

private:
    void clearData();

    QSqlDatabase m_dataBase;

    QList <const DishData *> m_dishDataList;
    QMap <int, const DishData *> m_dishIdMap;
    QMap <int,CategoryData *> m_categoryIdMap;
    QMap <int,HealthData *> m_healthDataMap;

    QList <const DiscountData *> m_discountDataList;
    QList <const RankData *> m_rankDataList;
    QList <const RecommendationData *> m_recommendationDataList;
    QList <const StoryData *> m_storyDataList;
//    QList <const HealthData *> m_healthDataList;
};

#endif // EMENUDATA_H
