/**************************************************************************
**   
**   Special keywords: tsuibin 10/30/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#include "mana.h"
#include "ui_mana.h"

#include <QHostAddress>



Mana::Mana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mana)
{
     ui->setupUi(this);
     m_canSendMsg = false;
     m_server = new QTcpServer(this);
     quint16 prot = 8763;
     m_server->listen(QHostAddress::Any,prot);
    connect(this->m_server,SIGNAL(newConnection()),this,SLOT(newConnect()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(sendMsg()));

    tcpSocket = new QTcpSocket();

}

Mana::~Mana()
{
    delete ui;
}


void Mana::newConnect()
{
    m_tcpSocket =  this->m_server->nextPendingConnection();
    connect(this->m_tcpSocket,SIGNAL(readyRead()),this,SLOT(recvMsg()));
    m_canSendMsg = true;
    qDebug() << m_tcpSocket->peerAddress().toString();
}

void Mana::recvMsg()
{
    QByteArray buf;
    buf.append(ui->textEdit->toPlainText());
    do{
        buf += this->m_tcpSocket->readLine();
    }while(this->m_tcpSocket->canReadLine());
    buf += '\n';
    qDebug() <<"收到消息" << buf ;
    ui->textEdit->setText(buf);
}


void Mana::sendMsg()
{
    qDebug() << "sendmsg";

    QString IP;
    IP = m_tcpSocket->peerAddress().toString();
    QByteArray buf;
    buf.append(ui->lineEdit->text());

        tcpSocket->connectToHost(IP,8763);
        qDebug() <<"2" << buf;

        tcpSocket->write(buf);
    QString sbuf = ui->textEdit->toPlainText();

        ui->textEdit->setText(sbuf + ui->lineEdit->text()+ '\n');
        ui->lineEdit->clear();
}
