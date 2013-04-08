#include "topmenu.h"
#include "ui_topmenu.h"



TopMenu::TopMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TopMenu)
{

    ui->setupUi(this);


    QString picPath = "images/menu_bg.jpg";


    ui->label->setPixmap(QPixmap(picPath));

    QString editPicPath = "images/edit.png";
    ui->label_edit->setPixmap(QPixmap(editPicPath));

    QString createPicPath = "images/create.png";
    ui->label_create->setPixmap(QPixmap(createPicPath));



}

TopMenu::~TopMenu()
{
    delete ui;
}

