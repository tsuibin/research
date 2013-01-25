#include <QStyleOptionGraphicsItem>
#include <QPainter>

#include "acontrolbutton.h"

AControlButton::AControlButton(const QString &picPath,const QString &dpicPath, QGraphicsItem *parent) :
               QGraphicsObject(parent),_picPath(picPath),_dpicPath(dpicPath)
{
    this->setAcceptHoverEvents(true);
    this->setCacheMode(DeviceCoordinateCache);

    QPixmap pixmap(this->_picPath);
    this->_picHeight = pixmap.height();
    this->_picWidth = pixmap.width();
    this->_text.clear();
}

QRectF AControlButton::boundingRect() const
{
    return QRectF(0, 0, this->_picWidth, this->_picHeight);
}

QPainterPath AControlButton::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void AControlButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    bool down = option->state & QStyle::State_Sunken;
    if (down) {
        painter->drawPixmap(0, 0, QPixmap(_dpicPath));
        painter->setPen(this->d_textColor);
    } else {
        painter->drawPixmap(0, 0, QPixmap(_picPath));
        painter->setPen(this->textColor);
    }
    QRectF textRect = this->boundingRect();
    textRect.setTopLeft(QPointF(2, 2));
    textRect.setBottomRight(QPointF(this->_picWidth - 2, this->_picHeight - 2));
    painter->drawText(textRect, Qt::AlignCenter | Qt::TextWordWrap, this->_text);
}

void AControlButton::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    update();
}

void AControlButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    emit clicked();
    update();
}

QString AControlButton::text()
{
    return this->_text;
}

void AControlButton::setText(const QString &text)
{
    this->_text = text;
    this->update();
}

void AControlButton::setTextColor(const QColor &n_color,const QColor &d_color)
{
    this->textColor = n_color;
    this->d_textColor = d_color;
    this->update();
}
