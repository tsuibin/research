#include "touchdemo.h"
#include "ui_touchdemo.h"

#include "topmenu.h"
#include "gridview.h"
#include "preview.h"
#include "imglabel.h"
#include "appenv.h"


#define PREVIOUS_PAGE   1
#define NEXT_PAGE       -1
#define CURRENT_PAGE    0


 TouchDemo::TouchDemo(QWidget * parent):
QWidget(parent), ui(new Ui::TouchDemo)
{
	ui->setupUi(this);
    this->setWindowTitle("看图 Demo");
	this->setMaximumSize(1280, 800);
	this->setMinimumSize(1280, 800);

    setAttribute(Qt::WA_AcceptTouchEvents);//add touch device support


	QStringList imgList = AppEnv::initImgList();

	QString picPath = "images/bg.jpg";
	ui->label->setPixmap(QPixmap(picPath));


	m_preview = new Preview(this);
    m_preview->hide();

	m_girdView = new GirdView(this);
	m_girdView->show();

	m_topMenu = new TopMenu(this);
	m_topMenu->show();

	connect(m_girdView, SIGNAL(imgClicked()), m_preview, SLOT(test()));
	connect(m_girdView, SIGNAL(imgClicked()), m_preview, SLOT(show()));

	connect(m_girdView, SIGNAL(imgClicked()), m_girdView, SLOT(hide()));

	connect(m_topMenu, SIGNAL(retSignal()), m_girdView, SLOT(show()));
	connect(m_topMenu, SIGNAL(retSignal()), m_preview, SLOT(hide()));

	connect(this, SIGNAL(pressESC()), m_preview, SLOT(hide()));
	connect(this, SIGNAL(pressESC()), m_girdView, SLOT(show()));

}

TouchDemo::~TouchDemo()
{
	delete m_topMenu;
	delete m_girdView;
	delete ui;
}

void TouchDemo::previousPage()
{
    qDebug() << __func__;
    if(m_girdView->isVisible())
    {
        m_girdView->prevPage();

    }
}
void TouchDemo::nextPage()
{
	qDebug() << __func__;
    if(m_girdView->isVisible())
    {
        qDebug() << "can do next";
        m_girdView->nextPage();

    }
}

void TouchDemo::returnCurrentPage()
{


}

void TouchDemo::touchBegin(QEvent * event)
{
    QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
    m_touchPoints = touchEvent->touchPoints();
    if (m_touchPoints.count() == 2)
    {
        const QTouchEvent::TouchPoint &touchPoint0 = m_touchPoints.first();
        const QTouchEvent::TouchPoint &touchPoint1 = m_touchPoints.last();

        qDebug() <<"2 touch press";
        qDebug() << touchPoint0.pos();
    }


}
bool TouchDemo::event( QEvent * event )
{

   return QWidget::event(event);
}

void TouchDemo::mouseMoveEvent ( QMouseEvent * event )
{
    if (m_mouseOldPosX == 0)
    {
        m_mouseOldPosX = event->x();

    }
    int x = event->x() - m_mouseOldPosX;
    qDebug() << "event->x()" << event->x() << "m_mouseOldPosX" << m_mouseOldPosX <<"x" << x;

    m_movingDistance += x;
    m_mouseOldPosX = event->x();


}

void TouchDemo::mousePressEvent ( QMouseEvent * event )
{


    m_movingDistance = 0;
    m_mouseOldPosX = event->x();

    qDebug() << "press" << m_mouseOldPosX <<"event->x()" << event->x();


}

void TouchDemo::mouseReleaseEvent ( QMouseEvent * event )
{

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
    if(m_girdView->isVisible())
    {
        automaticPage(pageDirection);
    }
    if(m_preview->isVisible())
    {
        automaticImg(pageDirection);
    }
    qDebug() <<"+-" << pageDirection;
    QWidget::mouseReleaseEvent(event);
}

void TouchDemo::keyPressEvent(QKeyEvent * event)
{

	switch (event->key()) {

	case Qt::Key_Up:
		qDebug() << "up";
		m_preview->prevImage();
		break;

	case Qt::Key_Down:
		qDebug() << "down";
		m_preview->nextImage();
		break;

	case Qt::Key_Left:
		qDebug() << "left";
		m_preview->prevImage();
		break;

	case Qt::Key_Right:
		qDebug() << "right";
		m_preview->nextImage();
		break;

	case Qt::Key_Escape:
		qDebug() << "esc";
		emit pressESC();
		break;
    case Qt::Key_PageUp:
        qDebug() << "prev";
        previousPage();
        break;

    case Qt::Key_PageDown:
        qDebug() << "down";
        nextPage();
        break;

	default:
		qDebug() << "unknow";
		break;

	}

}



void TouchDemo::automaticImg(int direction)
{
    qDebug()<<"direction"<<direction;
    switch(direction)
    {
    case 1:
        m_preview->prevImage();
        break;
    case -1:
        m_preview->nextImage();
        break;
    case 0:
        break;
    default:
        break;

    }

}



void TouchDemo::automaticPage(int direction)
{
    qDebug()<<"direction"<<direction;
    switch(direction)
    {
    case 1:
        previousPage();
        break;
    case -1:
        nextPage();
        break;
    case 0:
        returnCurrentPage();
        break;
    default:
        break;

    }

}
