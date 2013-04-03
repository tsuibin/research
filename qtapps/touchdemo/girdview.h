#ifndef GIRDVIEW_H
#define GIRDVIEW_H

#include <QWidget>

namespace Ui {
class GirdView;
}

class GirdView : public QWidget
{
    Q_OBJECT
    
public:
    explicit GirdView(QWidget *parent = 0);
    ~GirdView();
    
private:
    Ui::GirdView *ui;
};

#endif // GIRDVIEW_H
