#ifndef TOUCHDEMO_H
#define TOUCHDEMO_H

#include <QWidget>
#include <QStringList>
#include <QDir>

namespace Ui {
class TouchDemo;
}


class TopMenu;
class GirdView;

class TouchDemo : public QWidget
{
    Q_OBJECT
    
public:
    explicit TouchDemo(QWidget *parent = 0);
    ~TouchDemo();


    QStringList getImgList(QString path);
    
private slots:


private:
    Ui::TouchDemo *ui;
    TopMenu *m_topMenu;
    GirdView *m_girdView;
};

#endif // TOUCHDEMO_H
