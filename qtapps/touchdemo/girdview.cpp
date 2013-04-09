#include "girdview.h"
#include "ui_girdview.h"

#include "imglabel.h"
#include "appenv.h"

 GirdView::GirdView(QWidget * parent):
QWidget(parent), ui(new Ui::GirdView)
{
	ui->setupUi(this);

	this->setStyleSheet(QString::fromUtf8("QLabel {\n"
					      "border-width:10px;\n"
					      "border-style: solid;\n"
					      "border-color: #676767;\n"
					      " }\n" ""));

	initImg();

}

GirdView::~GirdView()
{
	delete ui;
}

void GirdView::initImg()
{

	QDir pdir;
	pdir.setPath("/home/tsuibin/Pictures/deepin-wallpapers/");
	QFileInfoList t = pdir.entryInfoList(QDir::Files);

	int col = 0;
	int row = 0;
	int count = 1;
	int imgX = 0;
	int imgY = 0;
	int max = 12;

	m_imgCount = t.size();
	if (t.size() < 12) {
		max = t.size();

	}

	for (int i = 0; i < max; i++) {

		m_imgList.append(t.at(i).absoluteFilePath());
		QPixmap tmp =
		    QPixmap(t.at(i).absoluteFilePath()).scaled(290, 197);

		// qDebug() << row << col;
		imgX = 44 + tmp.width() * col + 10;
		imgY = 78 + tmp.height() * row + 10;

		if (count % 4 == 0)
			row++;
		col++;

		if (col == 4)
			col = 0;

		ImgLabel *label = new ImgLabel(this);
		label->setImgPath(t.at(i).absoluteFilePath());
		label->setPixmap(tmp);
		label->m_index = i;
		label->move(imgX, imgY);
		label->show();
		count++;
		connect(label, SIGNAL(clicked()), this,
			SLOT(sendImgClickSignal()));

	}
}

void GirdView::sendImgClickSignal()
{

	ImgLabel *label = qobject_cast < ImgLabel * >(sender());

	AppEnv::currentImg = label->getImgPath();
	AppEnv::currentImageIndex = label->m_index;
	qDebug() << "test";

	emit imgClicked();
}
