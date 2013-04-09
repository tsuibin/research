#include "createalbum.h"
#include "ui_createalbum.h"

 CreateAlbum::CreateAlbum(QWidget * parent):
QWidget(parent), ui(new Ui::CreateAlbum)
{
	ui->setupUi(this);
}

CreateAlbum::~CreateAlbum()
{
	delete ui;
}
