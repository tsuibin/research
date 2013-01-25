#include <QPen>
#include <QDebug>

#include "agraphicsselectitem.h"

AGraphicsSelectItem::AGraphicsSelectItem(QGraphicsItem *parent) :
        AGraphicsRectObject(parent),m_id(-1),m_currentStatus(AGraphicsSelectItem::Normal)
{
    this->setPen(QPen(Qt::transparent));
}

AGraphicsSelectItem::Status AGraphicsSelectItem::status()
{
    return this->m_currentStatus;
}

void AGraphicsSelectItem::setStatus(Status status)
{
    if (status != this->m_currentStatus) {
        this->m_currentStatus = status;
        if (this->m_currentStatus) {
            emit this->active(this->m_id);
        }
        this->updateStatus();
    }
}

void AGraphicsSelectItem::setId(int id)
{
    this->m_id = id;
}

int AGraphicsSelectItem::getId()
{
    return this->m_id;
}

void AGraphicsSelectItem::mousePressEvent(QGraphicsSceneMouseEvent */*event*/)
{
    if (this->m_currentStatus != AGraphicsSelectItem::Disabled) {
        emit this->pressed(this->m_id);
    }
}

void AGraphicsSelectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent */*event*/)
{
    if (this->m_currentStatus != AGraphicsSelectItem::Disabled) {
        emit this->clicked(this->m_id);
    }
}

void AGraphicsSelectItem::updateStatus()
{
    switch (this->m_currentStatus) {
    case AGraphicsSelectItem::Normal:
        break;

    case AGraphicsSelectItem::Active:
        break;

    case AGraphicsSelectItem::Disabled:
        break;

    default:
        break;
    }
}
