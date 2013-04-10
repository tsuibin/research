#include "touchdemo.h"
#include "ui_touchdemo.h"

#include "topmenu.h"
#include "girdview.h"
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
	this->setWindowTitle("深度看图");
	this->setMaximumSize(1280, 800);
	this->setMinimumSize(1280, 800);

	QStringList imgList = AppEnv::initImgList();

	QString picPath = "images/bg.jpg";
	ui->label->setPixmap(QPixmap(picPath));

	//   getImgList("/usr/share/wallpapers/kdeepin");

	m_preview = new Preview(this);
	m_preview->show();

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

void TouchDemo::mouseMoveEvent ( QMouseEvent * event )
{
    int x = event->x() - m_mouseOldPosX;


    m_movingDistance += x;
    m_mouseOldPosX = event->x();

    qDebug() << "m_movingDistance" << m_movingDistance;

}

void TouchDemo::mousePressEvent ( QMouseEvent * event )
{
    qDebug() << "m_movingDistance" << m_movingDistance;
    m_movingDistance = 0;
    m_mouseOldPosX = event->x();

}

void TouchDemo::mouseReleaseEvent ( QMouseEvent * event )
{
    qDebug() << "m_movingDistance" << m_movingDistance;

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
    automaticPage(pageDirection);

    qDebug() <<"+-" << pageDirection;
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
