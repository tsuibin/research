#ifndef MAP_H
#define MAP_H

#include <QWidget>

namespace Ui {
    class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = 0);
    ~Map();

private:
    Ui::Map *ui;
};

#endif // MAP_H
