/**************************************************************************
**   
**   Special keywords: tsuibin 10/28/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#include <QtGui/QApplication>

#include "capture.h"





#include "framework.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Framework w;
    //Capture w;
    //w.show();

    //w.showImage();

    return a.exec();
}
