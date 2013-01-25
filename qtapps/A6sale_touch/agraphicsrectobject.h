#ifndef AGRAPHICSRECTOBJECT_H
#define AGRAPHICSRECTOBJECT_H

#include <QObject>
#include <QGraphicsRectItem>

class AGraphicsRectObject: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

    Q_PROPERTY(QGraphicsObject * parent READ parentObject WRITE setParentItem NOTIFY parentChanged DESIGNABLE false)
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity NOTIFY opacityChanged FINAL)
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)
    Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibleChanged FINAL)
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(qreal y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(qreal z READ zValue WRITE setZValue NOTIFY zChanged)
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation NOTIFY rotationChanged)
    Q_PROPERTY(qreal scale READ scale WRITE setScale NOTIFY scaleChanged)
    Q_PROPERTY(QPointF transformOriginPoint READ transformOriginPoint WRITE setTransformOriginPoint)
    Q_PROPERTY(QRectF rect READ rect WRITE setRect) //extra

public:
    AGraphicsRectObject(QGraphicsItem * parent = 0) :
            QGraphicsRectItem(parent)
    {
    }


    AGraphicsRectObject ( const QRectF & rect, QGraphicsItem * parent = 0 ) :
            QGraphicsRectItem(rect, parent)
    {
    }

    AGraphicsRectObject ( qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = 0 ) :
            QGraphicsRectItem(x, y, width, height, parent)
    {
    }
};


#endif // AGRAPHICSRECTOBJECT_H
