#ifndef RANDOMVIEW_H
#define RANDOMVIEW_H

#include <QWidget>

namespace Ui {
class RandomView;
}

class RandomView : public QWidget
{
    Q_OBJECT
    
public:
    explicit RandomView(QWidget *parent = 0);
    ~RandomView();
    
private:
    Ui::RandomView *ui;
};

#endif // RANDOMVIEW_H
