#ifndef HEALTHITEM_H
#define HEALTHITEM_H

#include "agraphicsselectitem.h"

class HealthItem : public AGraphicsSelectItem
{
    Q_OBJECT

public:
    HealthItem(QGraphicsItem *parent = 0);
    ~HealthItem();

    void setData(const QString &pic, const QString &name, const QString &price,
                             const int &level, const QString &info);

protected:
    void updateStatus();

private:
    QGraphicsPixmapItem *m_background;
    QGraphicsPixmapItem *m_pic;
    QGraphicsTextItem *m_name;
    QGraphicsTextItem *m_info;
    QList <QGraphicsPixmapItem *> m_stars;
};

#endif // HEALTHITEM_H
