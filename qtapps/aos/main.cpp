#include "common.h"
#include "desktop.h"

int main(int argc, char *argv[])
{

    /* 设置随机数种子 */
    qsrand(time(NULL));

    /* 打印当前时间 */
    QDateTime abc;
    qDebug()  << abc.currentDateTime().toString();

    /* 启动线程调度循环 */
    QApplication a(argc, argv);

    /* 显示桌面 */
    Desktop d;
    d.show();

    return a.exec();
}
