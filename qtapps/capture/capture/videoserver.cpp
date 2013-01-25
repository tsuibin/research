/**************************************************************************
**   
**   Special keywords: tsuibin 10/29/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#include "videoserver.h"

VideoServer::VideoServer(QObject *parent) :
    QObject(parent)
{
    createServer();
}

VideoServer::~VideoServer()
{
    delete m_tcpServer;
}


void VideoServer::createServer()
{
    qDebug() << "createServer";
    m_tcpServer = new QTcpServer(this);
    m_tcpServer->listen(QHostAddress::Any, 8763);
    connect(m_tcpServer,SIGNAL(newConnection()),this,SLOT(initServer()));
}

void VideoServer::createClient()
{
    qDebug() << "createClient";
    m_clientTcpSocket = new QTcpSocket(this);
    connect(m_clientTcpSocket, SIGNAL(readyRead()), this, SLOT(receiveData()));
    connect(m_clientTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error()));
    m_clientTcpSocket->connectToHost(QHostAddress::LocalHost, 8763);
    client_flag =1;
}


void VideoServer::initServer()
{
    qDebug()<<"init";
    m_serverTcpSocket = m_tcpServer->nextPendingConnection();
    connect(m_serverTcpSocket, SIGNAL(readyRead()), this, SLOT(receiveData()));
    connect(m_serverTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error()));
    connect(m_serverTcpSocket, SIGNAL(disconnected()), m_serverTcpSocket, SLOT(deleteLater()));
}

void VideoServer::sendData(IplImage image)
{
    if (!client_flag ) createClient();
   // QTextStream out(m_clientTcpSocket);

    //out << image << endl;
    m_clientTcpSocket->write((const char *)&image,sizeof(IplImage));
}

void VideoServer::receiveData()
{
    if (!m_serverTcpSocket->canReadLine()) return;
    IplImage image;
    char *data;

    qDebug()<<"Video from:"<<m_serverTcpSocket->peerAddress().toString();

    //QString responseLine;
    //QTextCodec *codec =QTextCodec::codecForName("UTF-8");


    //QByteArray qba;
    do {

        m_serverTcpSocket->read(data,sizeof(IplImage));
        memcpy((void *)&image,data,sizeof(IplImage));

        emit videoDataReady(image);
            //qba += m_serverTcpSocket->readLine();
            //responseLine += codec->toUnicode(qba);
    } while (m_serverTcpSocket->canReadLine());

    //qba = qba.trimmed();
    //qDebug() << "qba.trimmed()" << qba;
    //responseLine = responseLine.trimmed();



    //qDebug() << qba.count();
    //qDebug() << qba.size();

}

void VideoServer::error()
{
        qDebug()<<"socket error";//<<m_tcpSocket->errorString();
        //m_tcpSocket->close();
}

