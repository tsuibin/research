#include "girdview.h"
#include "ui_girdview.h"

#include "imglabel.h"

GirdView::GirdView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GirdView)
{
    ui->setupUi(this);

    this->setStyleSheet( QString::fromUtf8("QLabel {\n"
                        "border-width:10px;\n"
                        "border-style: solid;\n"
                        "border-color: #676767;\n"
                        " }\n"
                        ""));

}

GirdView::~GirdView()
{
    delete ui;
}


void GirdView::initImg()
{

    QDir pdir;
    pdir.setPath("/usr/share/wallpapers/kdeepin/");
    QFileInfoList t = pdir.entryInfoList();

    int col = 0;
    int row = 0;
    int count = 1;
    int imgX = 0;
    int imgY = 0;

    for (int i = 0; i< t.size(); i++)
    {
          if (t.at(i).fileName()[0] != '.'){

            m_imgList.append(t.at(i).absoluteFilePath());
            QPixmap tmp = QPixmap(t.at(i).absoluteFilePath()).scaled(290,197);

           // qDebug() << row << col;
            imgX = 44+tmp.width()*col + 10;
            imgY = 78+tmp.height()*row + 10;

            if(count%4 ==0) row++;
            col++;

            if (col == 4) col = 0;

            ImgLabel *label = new ImgLabel(this);

            label->setPixmap(tmp);
            label->move(imgX, imgY);
            label->show();
            count++;

          }
    }
}


