#include "imageclient.h"
#include "ui_imageclient.h"



ImageClient::ImageClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageClient)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    flag = true;
    connect(&m_clientSocket,SIGNAL(readyRead()),this,SLOT(sendFrame()));

    capture = cvCreateCameraCapture( -1 );

    if( !capture ) return;

}


ImageClient::~ImageClient()
{
    cvReleaseCapture( &capture );
    delete ui;
}

void ImageClient::sendFrame()
{
    qint64 sig;
    m_clientSocket.read((char *)&sig, sizeof(qint64));
    if (sig == 1){
        initCapture();
    }
}

void ImageClient::initCapture()
{

    frame = cvQueryFrame( capture );
    if (!frame) return;
    qint64 size = frame->imageSize;
    qint64 wid = frame->width;
    qint64 hei = frame->height;

   // while( frame ) {
            //if ( !frame ) break;

    const unsigned char * src = (unsigned char *)frame->imageData;
    size = size /3;
    unsigned char * ptr = (unsigned char *)malloc(size);
    for (int i =0; i < size; i++)
    {
        src++;
        *(ptr+i) = *src++;
        src++;
    }

    //data.append((char *)frame->imageData,size);
     data.append((char *)ptr,size);
     free(ptr);

    //打印data大小 ，看看是否等于图片的大小
   // qDebug() << "data size is:" <<data.size();

    //使用tcpsocket将 图像的大小 发出,这个socket发出的数据长度为64位
    //(可自定义数据类型只要能保存图像长度即可,讲图像长度告知对方)
    m_clientSocket.write((char *)&size,sizeof(qint64));

    //发送图片的宽度

    m_clientSocket.write((char *)&wid,sizeof(qint64));
    //发送图片的高度
    m_clientSocket.write((char *)&hei,sizeof(qint64));

    //开始写图像的数据
    m_clientSocket.write(data);
    //如果有错误则打印错误提示，-1参数 为 永不超时
    if ( !m_clientSocket.waitForBytesWritten(-1) ){
        qDebug() << "write data error!";
    }
    m_clientSocket.flush(); //强制入到socket,清空缓冲区
   // qDebug() << "send over";//(调试信息)
    data.clear();

}

void ImageClient::on_pushButton_clicked()
{
    m_clientSocket.connectToHost(ui->lineEdit->text(),8763);
    connect(&m_clientSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(mystateChanged(QAbstractSocket::SocketState)));
}

void ImageClient::mystateChanged(QAbstractSocket::SocketState  e)
{
    qDebug() << e << m_clientSocket.errorString();
}

void ImageClient::on_pushButton_2_clicked()
{

    initCapture();
    return;
    QImage image("yilai.png"); //读取一个图片
    qDebug() << image.byteCount() << image.size(); //打印图片大小(调试)
    qint64 size = image.byteCount(); //获取图像大小

    //将图像数据转换为char *类型 然后加入到data变量
    data.append((char *)image.bits(),image.byteCount());

    //打印data大小 ，看看是否等于图片的大小
    qDebug() << "data size is:" <<data.size();

    //使用tcpsocket将 图像的大小 发出,这个socket发出的数据长度为64位
    //(可自定义数据类型只要能保存图像长度即可,讲图像长度告知对方)
    m_clientSocket.write((char *)&size,sizeof(qint64));

    //发送图片的宽度
	qint64 wid,hei;
	wid = image.width();
	hei = image.height();
    m_clientSocket.write((char *)&wid,sizeof(qint64));
    //发送图片的高度
    m_clientSocket.write((char *)&hei,sizeof(qint64));

    //开始写图像的数据
    m_clientSocket.write(data);
    //如果有错误则打印错误提示，-1参数 为 永不超时
    if ( !m_clientSocket.waitForBytesWritten(-1) ){
        qDebug() << "write data error!";
        this->close();
    }
    m_clientSocket.flush(); //强制入到socket,清空缓冲区
    qDebug() << "send over";//(调试信息)
    data.clear();
}
