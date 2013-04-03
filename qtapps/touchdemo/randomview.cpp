#include "randomview.h"
#include "ui_randomview.h"

RandomView::RandomView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RandomView)
{
    ui->setupUi(this);
}

RandomView::~RandomView()
{
    delete ui;
}
