#include "imglabel.h"
#include "appenv.h"

#include <QDebug>

QString AppEnv::currentImg;

 ImgLabel::ImgLabel(QWidget * parent):
QLabel(parent)
{
	m_activeImg = "";
	m_normalImg = "";
}

void ImgLabel::mousePressEvent(QMouseEvent * event)
{

	if (event->button() == Qt::LeftButton) {

		if (!m_activeImg.isEmpty())
			this->setPixmap(QPixmap(m_activeImg));

		emit pressed();
	}

	QLabel::mousePressEvent(event);

}

void ImgLabel::mouseReleaseEvent(QMouseEvent * event)
{
	//如果单击了就触发clicked信号
	if (event->button() == Qt::LeftButton) {

		if (!m_normalImg.isEmpty())
			this->setPixmap(QPixmap(m_normalImg));

		//触发clicked信号
		emit released();
		emit clicked();
		//AppEnv::currentImg = m_imgPath;
		//  test();
	}
	//将该事件传给父类处理
	QLabel::mouseReleaseEvent(event);

	qDebug() << "click" << m_imgPath << m_index;
	qDebug() << "env" << AppEnv::imgPath +
	    AppEnv::imgList.
	    at(AppEnv::currentImageIndex) << AppEnv::currentImageIndex;

}

QString ImgLabel::getImgPath()
{
	return this->m_imgPath;
}

void ImgLabel::setImgPath(QString path)
{

	this->m_imgPath = path;
}

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
