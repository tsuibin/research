#include <QStyleOptionGraphicsItem>
#include <QPainter>

#include "discountpriceitem.h"
#include "emenuenv.h"

DiscountPriceItem::DiscountPriceItem(QGraphicsItem *parent) :
        QGraphicsObject (parent)
{
}


QRectF DiscountPriceItem::boundingRect() const
{
    QRectF rect;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        rect.setRect(-(this->m_priceWidth + 21 + 15),-49,this->m_priceWidth + 21 + 15,49);
        break;

    case EmenuEnv::R_640_480:
    default:
        rect.setRect(-(this->m_priceWidth + 15 + 13),-43,this->m_priceWidth + 15 + 13,43);
        break;
    }
    return rect;
}

QPainterPath DiscountPriceItem::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void DiscountPriceItem::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget *)
{
    QFont font = painter->font();

    QRectF unitRect = this->boundingRect();
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        unitRect.setLeft(-15);
        font.setPixelSize(19);
        break;
    case EmenuEnv::R_640_480:
    default:
        unitRect.setLeft(-13);
        font.setPixelSize(12);
        break;
    }
    painter->setPen(EmenuEnv::textHeadingActiveColor_dish);
    painter->setFont(font);
    painter->drawText(unitRect, Qt::AlignCenter | Qt::TextWordWrap, tr("元"));

    QRectF tipRect;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        tipRect.setRect(-(this->m_priceWidth + 21 + 15),-49,21,49);
        break;
    case EmenuEnv::R_640_480:
    default:
        tipRect.setRect(-(this->m_priceWidth + 15 + 13),-43,13,43);
        break;
    }
    QPixmap pixmap(EmenuEnv::themeDir + "/dis_pricetip.png");
    painter->drawPixmap(tipRect, pixmap, pixmap.rect());

    QRectF priceRect = this->boundingRect();
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        priceRect.setRight(-15);
        priceRect.setLeft(-(this->m_priceWidth + 15));
        font.setPixelSize(51);
        break;
    case EmenuEnv::R_640_480:
    default:
        priceRect.setRight(-13);
        priceRect.setLeft(-(this->m_priceWidth + 13));
        font.setPixelSize(30);
        break;
    }
    painter->setPen(EmenuEnv::textHeadingActiveColor_dish);
    painter->setFont(font);
    painter->drawText(priceRect, Qt::AlignCenter, this->m_price);
}

void DiscountPriceItem::setPrice(const QString &price)
{
    this->m_price = price;
    QFont font;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        font.setPixelSize(51);
        break;
    case EmenuEnv::R_640_480:
    default:
        font.setPixelSize(30);
        break;
    }
    QFontMetricsF fontMetricsF(font);
    this->m_priceWidth = fontMetricsF.width(price) + 4;
    this->update();
}
