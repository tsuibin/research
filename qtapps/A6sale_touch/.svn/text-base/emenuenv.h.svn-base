#ifndef EMENUENV_H
#define EMENUENV_H

#include <QString>
#include <QColor>

class EmenuEnv
{
public:
    EmenuEnv(){}

    enum Resolution {
        R_640_480,
        R_1280_768
    };

    static void loadEnv();

    static int fullScreen;
    static Resolution currentResolution;
    static int resolutionWidth;
    static int resolutionHeight;

    static QString dataBasePath;
    static QString dishPicDir;
    static QString themeDir;

    static QString fontFamily;
    static QColor textNormalColor;
    static QColor textActiveColor;
    static QColor textHeadingColor;
    static QColor textHeadingActiveColor;
    static QColor textHeadingActiveColor_dish;
    static QColor textDetailColor;

    static int animationLevel; // 0 no animation; 1 animation on
    static int smoothRender; // 0 no render; 1 smooth and antialiasing; 2 smooth and high antialiasing 
};

#endif // EMENUENV_H
