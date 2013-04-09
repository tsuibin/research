#ifndef TOUCHDEMO_H
#define TOUCHDEMO_H

#include <QWidget>
#include <QStringList>
#include <QDir>
#include <QKeyEvent>
#include <QImage>
#include <QMessageBox>

namespace Ui {
class TouchDemo;
}


class TopMenu;
class GirdView;
class Preview;

class TouchDemo : public QWidget
{
    Q_OBJECT
    
public:
    explicit TouchDemo(QWidget *parent = 0);
    ~TouchDemo();


    QStringList getImgList(QString path);
signals:
    void pressESC();
    
private slots:
    void test();

protected:
    void keyPressEvent ( QKeyEvent * event );

private:
    Ui::TouchDemo *ui;
    TopMenu *m_topMenu;
    GirdView *m_girdView;
    Preview *m_preview;
};

#endif // TOUCHDEMO_H
