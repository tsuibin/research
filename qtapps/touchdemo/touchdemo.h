#ifndef TOUCHDEMO_H
#define TOUCHDEMO_H

#include <QWidget>

namespace Ui {
class TouchDemo;
}

class TouchDemo : public QWidget
{
    Q_OBJECT
    
public:
    explicit TouchDemo(QWidget *parent = 0);
    ~TouchDemo();
    
private:
    Ui::TouchDemo *ui;
};

#endif // TOUCHDEMO_H
