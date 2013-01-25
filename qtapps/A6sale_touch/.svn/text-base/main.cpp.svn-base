#include <QtGui/QApplication>
#include <QTextCodec>

#include "emenu.h"
#include "emenuenv.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //load the environment
    EmenuEnv::loadEnv();

    if (EmenuEnv::fullScreen == true) {
        app.setOverrideCursor(Qt::BlankCursor);
    }

    //init codec for tr
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));

    // init the default font of application
    QFont font = app.font();
    font.setFamily(EmenuEnv::fontFamily);
    app.setFont(font);

    Emenu emenu;
    emenu.start();

    return app.exec();
}
