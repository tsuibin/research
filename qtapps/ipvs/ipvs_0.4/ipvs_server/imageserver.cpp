#include "imageserver.h"
#include "ui_imageserver.h"

ImageServer::ImageServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageServer)
{
    ui->setupUi(this);
}

ImageServer::~ImageServer()
{
    delete ui;
}

void ImageServer::on_pushButton_clicked()
{
    if ( m_tcpServer.listen(QHostAddress::Any,8763) == true ){
        qDebug() << "Listen 8763";
    }else{
        qDebug() << "Listen Error!";
    }

    connect(&m_tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnect()));
}

void ImageServer::acceptConnect()
{
    qDebug() << "connected!";
    m_tcpSocket = m_tcpServer.nextPendingConnection();
    connect(m_tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    size = 0;
    width = 0;
    height = 0;
    data.clear();
}

void ImageServer::readData()
{
    if ( size == 0 ){
        m_tcpSocket->read((char *)&size,sizeof(qint64));
        m_tcpSocket->read((char *)&width,sizeof(qint64));
        m_tcpSocket->read((char *)&height,sizeof(qint64));
        //qDebug() << "package size:" << size<<" width:"<< width
                //<< " height:"<< height;
        if(width >0 && width < 924 && height < 668 && height > 0){
            ui->label->resize(width,height);//调整label大小
            this->resize(width+100,height+100);//调整窗口大小
            image = new QImage(width,height, QImage::Format_RGB32);
        }
    }

    data += m_tcpSocket->readAll();
    m_tcpSocket->flush();
   // qDebug() << "data size" << data.size() << "size" <<size;

    if (size == data.size() || size < data.size()){
        //qDebug() <<"read over! size is " << data.size();

        //QImage tmpImage((uchar *)data.data(),width,height,QImage::Format_RGB32);

        ui->label->setPixmap(QPixmap::fromImage(*(imageFromMat(data))));

        data.clear();
        qint64 i = 1;
        m_tcpSocket->write((char *)&i,sizeof(qint64));
    }

}

QImage * ImageServer::imageFromMat(QByteArray data)
{
    const unsigned char* src = (unsigned char* )data.data();
    unsigned char * des = image->bits();
    unsigned long count = width * height;
    for (unsigned long i = 0; i < count; ++i)
    {
       // *des++ = *src++; //r
//        *des++ = *src++; //g
//        *des++ = *src++; //b
        *des++ = 0; //g
        *des++ = *src++;
        *des++ = 0; //b
        *des++ = 0;//0xff; //255
    }
    return image;
}

