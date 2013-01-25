/**************************************************************************
**   
**   Special keywords: tsuibin 10/29/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#include "capturethread.h"

CaptureThread::CaptureThread(QObject *parent) :
    QThread(parent)
{
}


void CaptureThread::run()
{
    qDebug() << "renning!";
}
