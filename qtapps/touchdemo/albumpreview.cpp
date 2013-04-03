#include "albumpreview.h"
#include "ui_albumpreview.h"

AlbumPreview::AlbumPreview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlbumPreview)
{
    ui->setupUi(this);
}

AlbumPreview::~AlbumPreview()
{
    delete ui;
}
