#include "topmenu.h"
#include "ui_topmenu.h"
#include "imglabel.h"

 TopMenu::TopMenu(QWidget * parent):
QWidget(parent), ui(new Ui::TopMenu)
{

	ui->setupUi(this);

	QString picPath = "images/menu_bg.jpg";

	ui->label->setPixmap(QPixmap(picPath));

	QString editPicPath = "images/edit.png";
	ui->label_edit->setPixmap(QPixmap(editPicPath));

	QString createPicPath = "images/create.png";
	ui->label_create->setPixmap(QPixmap(createPicPath));

	QString retPicPath = "images/ret.png";

	ImgLabel *label_ret = new ImgLabel(this);
	label_ret->move(1076, 0);
	label_ret->setPixmap(QPixmap(retPicPath));
	label_ret->m_activeImg = "images/ret_active.png";
	label_ret->m_normalImg = "images/ret.png";

	connect(label_ret, SIGNAL(clicked()), this, SIGNAL(retSignal()));

}

TopMenu::~TopMenu()
{
	delete ui;
}
