#ifndef STORYSELECTITEM_H
#define STORYSELECTITEM_H

#include "agraphicsselectitem.h"

class StorySelectItem : public AGraphicsSelectItem
{
    Q_OBJECT

public:
    StorySelectItem(QGraphicsItem *parent = 0);
    ~StorySelectItem();

    void setData(int id, const QString &text);

protected:
    void updateStatus();

private:
    QGraphicsPixmapItem *m_background;
    QGraphicsTextItem *m_text;
};

#endif // STORYSELECTITEM_H
