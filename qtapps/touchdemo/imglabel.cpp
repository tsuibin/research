#include "imglabel.h"

#include <QDebug>


ImgLabel::ImgLabel(QWidget *parent) :
    QLabel(parent)
{
}


void ImgLabel::mousePressEvent(QMouseEvent *event)

{
    //如果单击了就触发clicked信号
    if (event->button() == Qt::LeftButton) {
        //触发clicked信号
        emit clicked();
    }
    //将该事件传给父类处理
    QLabel::mousePressEvent(event);

    qDebug() << "click";
}
