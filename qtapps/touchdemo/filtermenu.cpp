#include "filtermenu.h"
#include "ui_filtermenu.h"

FilterMenu::FilterMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterMenu)
{
    ui->setupUi(this);
}

FilterMenu::~FilterMenu()
{
    delete ui;
}