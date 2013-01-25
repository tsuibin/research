#ifndef FEATUREQUERYITEM_H
#define FEATUREQUERYITEM_H

#include "agraphicsselectitem.h"

class FeatureQueryItem : public AGraphicsSelectItem
{
    Q_OBJECT

public:
    FeatureQueryItem(QGraphicsItem *parent = 0);
    ~FeatureQueryItem();

    void setData(const QString &text);

protected:
    void updateStatus();

private:
    QGraphicsPixmapItem *m_background;
    QGraphicsTextItem *m_text;
};

#endif // FEATUREQUERYITEM_H
