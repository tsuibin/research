#include "topmenu.h"
#include "ui_topmenu.h"

TopMenu::TopMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TopMenu)
{
    ui->setupUi(this);
}

TopMenu::~TopMenu()
{
    delete ui;
}
