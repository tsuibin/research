#ifndef TOPMENU_H
#define TOPMENU_H

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>

namespace Ui {
class TopMenu;
}

class TopMenu : public QWidget
{
    Q_OBJECT
    
public:
    explicit TopMenu(QWidget *parent = 0);
    ~TopMenu();
    
signals:
    void testImg();

private slots:

private:
    Ui::TopMenu *ui;
};

#endif // TOPMENU_H
