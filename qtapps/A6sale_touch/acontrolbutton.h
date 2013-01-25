#ifndef ACONTROLBUTTON_H
#define ACONTROLBUTTON_H

#include <QGraphicsObject>
class QStyleOptionGraphicsItem;

class AControlButton : public QGraphicsObject
{

    Q_OBJECT

public:
    AControlButton(const QString &picPath,const QString &dpicPath, QGraphicsItem *parent = 0);
    QString text();
    void setText(const QString &text);
    void setTextColor(const QColor &n_color,const QColor &d_color);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *);

signals:
    void clicked();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);

private:
    QString _text;
    QColor textColor;
    QColor d_textColor;
    QString _picPath;
    QString _dpicPath;
    qreal _picWidth;
    qreal _picHeight;
};

#endif // ACONTROLBUTTON_H
