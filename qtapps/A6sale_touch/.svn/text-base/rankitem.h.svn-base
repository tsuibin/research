#ifndef RANKITEM_H
#define RANKITEM_H

#include "agraphicsselectitem.h"

class RankItem : public AGraphicsSelectItem
{
    Q_OBJECT

public:
    RankItem(int rankNo, QGraphicsItem *parent = 0);
    ~RankItem();

    void setData(const QString &text, bool fall = false);

protected:
    void updateStatus();

private:
    QGraphicsPixmapItem *m_background;
    QGraphicsPixmapItem *m_active;
    QGraphicsTextItem *m_rankNo;
    QGraphicsTextItem *m_text;
    QGraphicsPixmapItem *m_icon;
};

#endif // RANKITEM_H
