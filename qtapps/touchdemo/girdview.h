#ifndef GIRDVIEW_H
#define GIRDVIEW_H

#include <QWidget>
#include <QDebug>
#include <QDir>
#include <QFileInfoList>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class GirdView;
}

class GirdView : public QWidget
{
    Q_OBJECT
    
public:
    explicit GirdView(QWidget *parent = 0);
    ~GirdView();

public slots:
    void initImg();
    
private:
    Ui::GirdView *ui;

    QStringList m_imgList;
};

#endif // GIRDVIEW_H
