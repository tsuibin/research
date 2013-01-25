#ifndef AGRAPHICSSELECTITEM_H
#define AGRAPHICSSELECTITEM_H

#include "agraphicsrectobject.h"

class AGraphicsSelectItem : public AGraphicsRectObject
{
    Q_OBJECT

public:
    AGraphicsSelectItem(QGraphicsItem *parent = 0);

    enum Status {
        Normal,
        Active,
        Disabled
    };

    Status status();
    void setStatus(Status status);
    void setId(int id);
    int getId();

signals:
    void clicked(int id);
    void pressed(int id);
    void active(int id);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void updateStatus();

    int m_id;
    Status m_currentStatus;
};

#endif // AGRAPHICSSELECTITEM_H
