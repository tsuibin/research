#ifndef RECOMMENDATIONITEM_H
#define RECOMMENDATIONITEM_H

#include "agraphicsselectitem.h"

class RecommendationItem : public AGraphicsSelectItem
{
public:
    RecommendationItem(QGraphicsItem *parent = 0);
    ~RecommendationItem();

    void setData(const QString &pic,const QString &text);

protected:
    void updateStatus();

private:
    QGraphicsPixmapItem *m_picBg;
    QGraphicsPixmapItem *m_pic;
    QGraphicsTextItem *m_text;
    QGraphicsPixmapItem *m_recommendationIcon;
};

#endif // RECOMMENDATIONITEM_H
