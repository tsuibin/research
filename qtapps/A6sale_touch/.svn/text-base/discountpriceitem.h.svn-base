#ifndef DISCOUNTPRICEITEM_H
#define DISCOUNTPRICEITEM_H

#include <QGraphicsObject>

class DiscountPriceItem : public QGraphicsObject
{
    Q_OBJECT

public:
    DiscountPriceItem(QGraphicsItem * parent = 0);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *);

    void setPrice(const QString &price);

private:
    QString m_price;
    qreal m_priceWidth;
};

#endif // DISCOUNTPRICEITEM_H
