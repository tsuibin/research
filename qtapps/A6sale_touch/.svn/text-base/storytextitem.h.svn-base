#ifndef STORYTEXTITEM_H
#define STORYTEXTITEM_H

#include <QGraphicsPixmapItem>

#include "agraphicsrectobject.h"

class StoryTextItem : public AGraphicsRectObject
{
public:
    StoryTextItem(QGraphicsItem * parent = 0);
    void setItemData(const QString &picPath, const QString &text = QString());

private:
    QGraphicsPixmapItem *m_titleIconLeft;
    QGraphicsPixmapItem *m_titleIconRight;
    QGraphicsTextItem *m_title;

    QGraphicsTextItem *m_text;
    QGraphicsPixmapItem *m_pic;
};

#endif // STORYTEXTITEM_H
