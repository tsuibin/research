#include <QtGui/QApplication>
#include "tuan.h"
#include "goods.h"

int Goods::count = 6;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));

    Tuan w;
    w.show();

    return a.exec();
}
