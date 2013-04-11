#include "imglabel.h"
#include "appenv.h"

#include <QDebug>

QString AppEnv::currentImg;

 ImgLabel::ImgLabel(QWidget * parent):
QLabel(parent)
{

     setAttribute(Qt::WA_AcceptTouchEvents);
	m_activeImg = "";
	m_normalImg = "";
}

void ImgLabel::mousePressEvent(QMouseEvent * event)
{
    /*鼠标按下*/
    m_movingDistance = 0;
    m_mouseOldPosX = event->x();

	if (event->button() == Qt::LeftButton) {

		if (!m_activeImg.isEmpty())
			this->setPixmap(QPixmap(m_activeImg));

		emit pressed();
	}

	QLabel::mousePressEvent(event);

}

void ImgLabel::mouseMoveEvent ( QMouseEvent * event )
{
    int x = event->x() - m_mouseOldPosX;


    m_movingDistance += x;
    m_mouseOldPosX = event->x();


    QLabel::mouseMoveEvent(event);

}

void ImgLabel::mouseReleaseEvent(QMouseEvent * event)
{

    if (!m_normalImg.isEmpty())
        this->setPixmap(QPixmap(m_normalImg));

    qDebug() << "mouseOldPosX" <<m_mouseOldPosX
             <<"movingDistance"<<m_movingDistance;

    pageDirection = 0;
    if (m_movingDistance > 200)
    {
        pageDirection = 1;
    }
    else if (m_movingDistance < (-200))
    {
        pageDirection = -1;
    }


    if (event->button() == Qt::LeftButton && pageDirection == 0)
    {

		emit released();
		emit clicked();

	}

    QLabel::mouseReleaseEvent(event);

}

QString ImgLabel::getImgPath()
{
	return this->m_imgPath;
}

void ImgLabel::setImgPath(QString path)
{

	this->m_imgPath = path;
}

//bool ImgLabel::event( QEvent * event )
//{
//    QWidget::event(event);
//}
void ImgLabel::test()
{

	//sence
	QGraphicsScene *scene = new QGraphicsScene(0, 0, 1280, 800);	//x y width height

	//item
	QPixmap *img = new QPixmap(m_imgPath);

	Pixmap *item = new Pixmap(*img);

	item->setOffset(0, 0);

	scene->addItem(item);

	// Ui
	View *view = new View(scene);
	view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Deepin See"));
	view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	// view->setBackgroundBrush(bgPix);
	view->setCacheMode(QGraphicsView::CacheBackground);
	view->
	    setRenderHints(QPainter::Antialiasing | QPainter::
			   SmoothPixmapTransform);

	view->show();

}
