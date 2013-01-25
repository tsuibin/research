#ifndef COMMONMENUITEM_H
#define COMMONMENUITEM_H

#include "agraphicsselectitem.h"

class CommonMenuItem : public AGraphicsSelectItem
{
    Q_OBJECT

public:
    CommonMenuItem(QGraphicsItem *parent = 0);
    ~CommonMenuItem();

    void setData(const QString &pic, const QString &name, const QString &price);

protected:
    void updateStatus();

private:
    QGraphicsPixmapItem *m_background;
    QGraphicsPixmapItem *m_pic;
    QGraphicsTextItem *m_text;
};

#endif // COMMONMENUITEM_H
