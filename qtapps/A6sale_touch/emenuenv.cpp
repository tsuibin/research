#include <QCoreApplication>
#include <QSettings>

#include "emenuenv.h"

QString EmenuEnv::themeDir = "./etc/themes/default";
QString EmenuEnv::dataBasePath = "./etc/localdb";
QString EmenuEnv::dishPicDir = "./etc/dish_pic";

int EmenuEnv::fullScreen = 1;
EmenuEnv::Resolution EmenuEnv::currentResolution = EmenuEnv::R_640_480;
int EmenuEnv::resolutionWidth = 640;
int EmenuEnv::resolutionHeight = 480;

int EmenuEnv::animationLevel = 0;
int EmenuEnv::smoothRender = 1;

QString EmenuEnv::fontFamily = QString::fromUtf8("Microsoft JhengHei");
QColor EmenuEnv::textNormalColor = QColor(128,79,33,255);
QColor EmenuEnv::textActiveColor = QColor(255,200,0,255);
QColor EmenuEnv::textDetailColor = QColor(230,56,40,255);
QColor EmenuEnv::textHeadingColor = QColor(64,33,15,255);
QColor EmenuEnv::textHeadingActiveColor = QColor(255,255,240,255);
QColor EmenuEnv::textHeadingActiveColor_dish = QColor(194,13,35,255);

void EmenuEnv::loadEnv()
{
    QSettings setting(QCoreApplication::applicationDirPath() + "/etc/setting.ini",QSettings::IniFormat);

    EmenuEnv::dataBasePath = QCoreApplication::applicationDirPath() + "/etc/localdb";
    EmenuEnv::dishPicDir = QCoreApplication::applicationDirPath() + "/etc/" + setting.value("DISHPICDIR","dish_pic").toString();
    EmenuEnv::themeDir = QCoreApplication::applicationDirPath() + "/etc/themes/" + setting.value("THEME","default").toString();

    EmenuEnv::fullScreen = setting.value("FULLSCREEN",1).toInt();
    switch (setting.value("RESOLUTION",0).toInt()) {
    case 0:
        EmenuEnv::currentResolution = EmenuEnv::R_640_480;
        EmenuEnv::resolutionWidth = 640;
        EmenuEnv::resolutionHeight = 480;
        break;

    case 1:
        EmenuEnv::currentResolution = EmenuEnv::R_1280_768;
        EmenuEnv::resolutionWidth = 1280;
        EmenuEnv::resolutionHeight = 768;
        break;

    default:
        break;
    }
    EmenuEnv::animationLevel  = setting.value("ANIMATION",0).toInt();
    EmenuEnv::smoothRender = setting.value("SMOOTH",1).toInt();

    QSettings themeSetting(EmenuEnv::themeDir + "info.ini",QSettings::IniFormat);
    EmenuEnv::fontFamily = themeSetting.value("FontFamily",QString::fromUtf8("Microsoft JhengHei")).toString();
    EmenuEnv::textNormalColor = themeSetting.value("TextNormalColor",QColor(128,79,33,255)).value<QColor>();
    EmenuEnv::textActiveColor = themeSetting.value("TextActiveColor",QColor(255,200,0,255)).value<QColor>();
    EmenuEnv::textDetailColor = themeSetting.value("TextDetailColor",QColor(230,56,40,255)).value<QColor>();
    EmenuEnv::textHeadingColor = themeSetting.value("TextHeadingColor",QColor(64,33,15,255)).value<QColor>();
    EmenuEnv::textHeadingActiveColor = themeSetting.value("TextHeadingActiveColor",QColor(255,255,240,255)).value<QColor>();
    EmenuEnv::textHeadingActiveColor_dish = themeSetting.value("TextHeadingActiveColorDish",QColor(194,13,35,255)).value<QColor>();
}
