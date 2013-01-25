#ifndef DISCOUNTITEM_H
#define DISCOUNTITEM_H

#include "agraphicsselectitem.h"

class DiscountItem : public AGraphicsSelectItem
{
    Q_OBJECT

public:
    DiscountItem(QGraphicsItem *parent = 0);
    ~DiscountItem();

    void setData(const QString &picPath, const QString &dishName, const QString &price);

protected:
    void updateStatus();

private:
    QGraphicsPixmapItem *m_background;
    QGraphicsPixmapItem *m_pic;
    QGraphicsTextItem *m_text;
};

#endif // DISCOUNTITEM_H
