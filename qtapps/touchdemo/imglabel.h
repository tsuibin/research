#ifndef IMGLABEL_H
#define IMGLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>


class Pixmap : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    Pixmap(const QPixmap &pix)
        : QObject(), QGraphicsPixmapItem(pix)
    {
        setCacheMode(DeviceCoordinateCache);
    }
};

class View : public QGraphicsView
{
public:
    View(QGraphicsScene *scene) : QGraphicsView(scene) { }

protected:
    void resizeEvent(QResizeEvent *event)
    {
        QGraphicsView::resizeEvent(event);
        fitInView(sceneRect(), Qt::KeepAspectRatio);
    }
};


class ImgLabel : public QLabel
{
    Q_OBJECT
public:

    enum Status {
        Normal,
        Active,
        Disabled
    };

    explicit ImgLabel(QWidget *parent = 0);
    void setImgPath(QString path);
    QString getImgPath();
    void test();
    int m_index;
    QString m_activeImg;
    QString m_normalImg;
    
signals:
    void clicked();
    void pressed();
    void released();
    
public slots:

   protected:

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent ( QMouseEvent * event );
   // bool event( QEvent * event );


private:
    QString m_imgPath;

    int m_mouseOldPosX;
    int m_movingDistance;
    int pageDirection;
    bool m_preview;


    
};

#endif // IMGLABEL_H
