/**************************************************************************
**   
**   Special keywords: tsuibin 10/29/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#include "framework.h"
#include <QMetaType>

Framework::Framework(QObject *parent) :
    QObject(parent)
{

//    m_captureThread = new CaptureThread();
//    m_captureThread->start();
    m_capture = new Capture();
    //m_capture->start();
   // m_sender = new VideoServer(this);
    //qRegisterMetaType<IplImage>("IplImage");

   // connect(this->m_capture,SIGNAL(sendVideoData(IplImage)),this->m_sender,SLOT(sendData(IplImage)));
   // connect(this->m_sender,SIGNAL(videoDataReady(IplImage)),this->m_capture,SLOT(showImage(IplImage)));

}
