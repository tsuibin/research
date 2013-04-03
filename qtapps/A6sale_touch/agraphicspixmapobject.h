#ifndef AGRAPHICSPIXMAPOBJECT_H
#define AGRAPHICSPIXMAPOBJECT_H

#include <QObject>
#include <QGraphicsPixmapItem>

class AGraphicsPixmapObject :  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    //Q_PROPERTY(QGraphicsObject * parent READ parentObject WRITE setParentItem NOTIFY parentChanged DESIGNABLE false)
    //Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity NOTIFY opacityChanged FINAL)
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)
    Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibleChanged FINAL)
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(qreal y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(qreal z READ zValue WRITE setZValue NOTIFY zChanged)
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation NOTIFY rotationChanged)
    Q_PROPERTY(qreal scale READ scale WRITE setScale NOTIFY scaleChanged)
    Q_PROPERTY(QPointF transformOriginPoint READ transformOriginPoint WRITE setTransformOriginPoint)

public:
    AGraphicsPixmapObject(QGraphicsItem * parent = 0) :
            QGraphicsPixmapItem(parent)
    {
    }


    AGraphicsPixmapObject (const QPixmap & pixmap, QGraphicsItem * parent = 0) :
            QGraphicsPixmapItem(pixmap, parent)
    {
    }
};

#endif // AGRAPHICSPIXMAPOBJECT_H
