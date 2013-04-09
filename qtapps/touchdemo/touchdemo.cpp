#include "touchdemo.h"
#include "ui_touchdemo.h"

#include "topmenu.h"
#include "girdview.h"
#include "preview.h"
#include "imglabel.h"
#include "appenv.h"

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

//void TouchDemo::getImgList()
//{

//    QDir pdir;
//    pdir.setPath("/home/tsuibin/Pictures/deepin-wallpapers/");
//    QFileInfoList t = pdir.entryInfoList(QDir::Files);
//}
void TouchDemo::test()
{
	qDebug() << __func__;

//        //sence
//        QGraphicsScene *scene = new QGraphicsScene(0, 0, 1280, 800); //x y width height

//        Pixmap *item = new Pixmap(QPixmap("/home/tsuibin/Pictures/deepin-wallpapers/butterfly-1.jpg").scaled(1280,752));

//        item->setOffset(0, 48);

//        scene->addItem(item);

//        // Ui
//        View *view = new View(scene);
//       // view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "深度看图"));
//        view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
//       // view->setBackgroundBrush(scaledImg);
//        view->setCacheMode(QGraphicsView::CacheBackground);
//        view->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

//        view->show();

//    QString fileName = "/home/tsuibin/Pictures/deepin-wallpapers/butterfly-1.jpg";
//    QImage image(fileName);

//    if (image.isNull()) {
//        QMessageBox::information(this, tr("Image Viewer"),
//                                 tr("Cannot load %1.").arg(fileName));
//        return;
//    }
////将名为fileName的图片显示到imageLabel上
//    QLabel *imageLabel = new QLabel(this);
//    imageLabel->resize(1280,752);
//    QPixmap scaledImg = QPixmap::fromImage(image).scaled(1280,752);
//    imageLabel->setPixmap(scaledImg);
//    imageLabel->move(0,48);

}

void TouchDemo::keyPressEvent(QKeyEvent * event)
{

/*
Qt::Key_Left	0x01000012
Qt::Key_Up	0x01000013
Qt::Key_Right	0x01000014
Qt::Key_Down	0x01000015
*/

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

	default:
		qDebug() << "unknow";
		break;

	}

}
