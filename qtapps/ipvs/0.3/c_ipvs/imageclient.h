#ifndef IMAGECLIENT_H
#define IMAGECLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QDebug>


#include <opencv/highgui.h>

namespace Ui {
    class ImageClient;
}

class ImageClient : public QWidget
{
    Q_OBJECT

public:
    explicit ImageClient(QWidget *parent = 0);
    ~ImageClient();

    QTcpSocket m_clientSocket;

private:
    Ui::ImageClient *ui;
    QByteArray data;
    bool flag;
    CvCapture* capture;
    IplImage * frame;

private slots:
    void initCapture();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void mystateChanged(QAbstractSocket::SocketState  e);
    void sendFrame();
};

#endif // IMAGECLIENT_H
