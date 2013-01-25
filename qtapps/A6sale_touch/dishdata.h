#ifndef DISHDATA_H
#define DISHDATA_H

#include <QString>

class DishData
{
public:
    DishData() :
        dishId(-1),kindId(-1)
    {}

    int dishId;
    QString name;        //菜品名称
    int kindId;
//    double price;
    QString price;       //价格
    QString info;        //信息
    QString pic;         //图片名
    QString speciality;
//    QString pingyin;
//    QString alias;
};

class DiscountData
{
public:
    DiscountData() :
            discountId(-1),seq(-1),dishId(-1)
    {}

    int discountId;
    int seq;
    QString oldPrice;
    int dishId;
    const DishData *dishData;
};

class RecommendationData
{
public:
    RecommendationData() :
           recommendationId(-1),seq(-1),staffid(-1),dishId(-1)
    {}

    int recommendationId;
    int seq;
    QString recommendation;
    int staffid;
    int dishId;
    const DishData *dishData;
};

class StoryData
{
public:
    StoryData() :
            storyId(-1),seq(-1),dishId(-1)
    {}

    int storyId;
    int seq;
    QString story;
    int dishId;
    const DishData *dishData;
};

class HealthData
{
public:
    HealthData() :
            healthKindId(-1)
    {}

    int healthKindId;
    QString healthKindname;
    QList<QString> infoList;
    QList<int> rankList;
    QList<int> seqList;
    QList<int> dishIdList;
    QList<const DishData *> dishDataList;
};


class RankData
{
public:
    RankData() :
            rankId(-1),seq(-1),dishId(-1)
    {}

    int rankId;
    int seq;
    int dishId;
    bool isUp;
    const DishData *dishData;
};


class CategoryData
{
public:
    CategoryData() :
            categoryId(-1)
    {}

    int categoryId;
    int pid;
    QString name;
    QList<int> dishIdList;
    QList<const DishData *> dishDataList;
};

#endif // DISHDATA_H
