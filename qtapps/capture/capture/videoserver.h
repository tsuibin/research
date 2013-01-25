/**************************************************************************
**   
**   Special keywords: tsuibin 10/29/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#ifndef VIDEOSERVER_H
#define VIDEOSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <cv.h>

class VideoServer : public QObject
{
    Q_OBJECT
public:
    explicit VideoServer(QObject *parent = 0);
    ~VideoServer();
    void createServer();
    void createClient();
    int client_flag;

signals:
    void videoDataReady(IplImage);

public slots:
    void initServer();
    void sendData(IplImage);
    void receiveData();
    void error();


private:
    //static int m_flag;
    QTcpServer *m_tcpServer;
    QTcpSocket *m_clientTcpSocket;
    QTcpSocket *m_serverTcpSocket;


};

#endif // VIDEOSERVER_H
