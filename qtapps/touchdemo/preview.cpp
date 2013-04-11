#include "preview.h"
#include "ui_preview.h"

#include "appenv.h"

#include "imglabel.h"

 Preview::Preview(QWidget * parent):
QWidget(parent), ui(new Ui::Preview)
{
	ui->setupUi(this);
	m_imageLabel = new QLabel(this);
	m_imageLabel->resize(1280, 752);

}

Preview::~Preview()
{
	delete ui;
}

void
 Preview::setImagePath(QString path)
{
	m_imgPath = path;

}

void Preview::test()
{

	qDebug() << AppEnv::currentImg;
	QString fileName = AppEnv::currentImg;
	QImage image(fileName);

	if (image.isNull()) {
		QMessageBox::information(this, tr("Image Viewer"),
					 tr("Cannot load %1.").arg(fileName));
		return;
	}

	QPixmap scaledImg = QPixmap::fromImage(image).scaled(1280, 752);
	m_imageLabel->setPixmap(scaledImg);
	m_imageLabel->move(0, 48);

}

void Preview::nextImage()
{

    if (AppEnv::currentImageIndex >= AppEnv::imgCount-1)
    {
        AppEnv::currentImageIndex = AppEnv::imgCount-1;
        return;
    }
     AppEnv::currentImageIndex++;
    int no =  AppEnv::currentImageIndex;
    qDebug() << "di" << no;
	QString fileName =
        AppEnv::imgPath + AppEnv::imgList.at(no);

	qDebug() << fileName;

	QImage image(fileName);

	if (image.isNull()) {
		QMessageBox::information(this, tr("Image Viewer"),
					 tr("Cannot load %1.").arg(fileName));
		return;
	}
	QPixmap scaledImg = QPixmap::fromImage(image).scaled(1280, 752);
	m_imageLabel->setPixmap(scaledImg);
	m_imageLabel->move(0, 48);

}

void Preview::prevImage()
{

    if (AppEnv::currentImageIndex <= 0)
    {
        AppEnv::currentImageIndex = 0;
		return;
    }

    AppEnv::currentImageIndex--;

	QString fileName =
        AppEnv::imgPath + AppEnv::imgList.at(AppEnv::currentImageIndex);

	qDebug() << fileName;

	QImage image(fileName);

	if (image.isNull()) {
		QMessageBox::information(this, tr("Image Viewer"),
					 tr("Cannot load %1.").arg(fileName));
		return;
	}

	QPixmap scaledImg = QPixmap::fromImage(image).scaled(1280, 752);
	m_imageLabel->setPixmap(scaledImg);
	m_imageLabel->move(0, 48);

}


bool Preview::event( QEvent * event )
{
    if ( event->type() == QEvent::TouchEnd )
    {
        qDebug() << "check touch event";


    }

    QWidget::event(event);
}
