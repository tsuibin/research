#ifndef HEALTHKINDITEM_H
#define HEALTHKINDITEM_H

#include "agraphicsselectitem.h"

class HealthKindItem : public AGraphicsSelectItem
{
    Q_OBJECT

public:
    HealthKindItem(QGraphicsItem *parent = 0);
    ~HealthKindItem();

    void setData(const QString &text);

protected:
    void updateStatus();

private:
    QGraphicsPixmapItem *m_background;
    QGraphicsTextItem *m_text;
};

#endif // HEALTHKINDITEM_H
