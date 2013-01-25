#ifndef COMMONDETAIL_H
#define COMMONDETAIL_H

#include "agraphicsrectobject.h"

class DishData;

class CommonDetail : public AGraphicsRectObject
{
    Q_OBJECT

public:
    CommonDetail(QGraphicsItem *parent = 0);
    ~CommonDetail();

    void setData(const DishData *dishData);

private:
    void initDetailDish();
    void initDetailInfo();
    void initDetailIcons();

private:
    AGraphicsRectObject *m_detailDish;
    QGraphicsPixmapItem *m_dishPic;
    QGraphicsTextItem *m_dishName;
    AGraphicsRectObject *m_detailInfo;
    QGraphicsTextItem *m_dishInfo;
    AGraphicsRectObject *m_icons;
    QList <QGraphicsPixmapItem *> m_iconList;
};

#endif // COMMONDETAIL_H
