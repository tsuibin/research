#ifndef TOPMENU_H
#define TOPMENU_H

#include <QWidget>

namespace Ui {
class TopMenu;
}

class TopMenu : public QWidget
{
    Q_OBJECT
    
public:
    explicit TopMenu(QWidget *parent = 0);
    ~TopMenu();
    
private:
    Ui::TopMenu *ui;
};

#endif // TOPMENU_H
