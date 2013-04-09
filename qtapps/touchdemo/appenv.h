#ifndef APPENV_H
#define APPENV_H

#include <QString>
#include <QDir>
#include <QDebug>

class AppEnv
{
public:
    AppEnv();
    static QStringList imgList;
    static QStringList initImgList();

    static QString currentImg;
    static QString imgPath;
    static int currentImageIndex;
    static int imgCount;
};

#endif // APPENV_H
