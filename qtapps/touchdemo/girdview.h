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

signals:
    void imgClicked();

public slots:
    void initImg();
    void sendImgClickSignal();
    
private:
    Ui::GirdView *ui;

    QStringList m_imgList;
    int m_imgCount;
};

#endif // GIRDVIEW_H
