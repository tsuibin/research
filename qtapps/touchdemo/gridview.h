#ifndef GIRDVIEW_H
#define GIRDVIEW_H

#include <QWidget>
#include <QDebug>
#include <QDir>
#include <QFileInfoList>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <QMap>
#include <QtCore>

namespace Ui {
class GirdView;
}

class ImgLabel;

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
    void nextPage();
    void prevPage();

protected:
    void mouseMoveEvent ( QMouseEvent * event );
    void mousePressEvent ( QMouseEvent * event );
    void mouseReleaseEvent ( QMouseEvent * event );
    bool event( QEvent * event );

private:
    Ui::GirdView *ui;

    QStringList m_imgList;
    int m_imgCount;
    int m_currentPage;
    QMap<int, ImgLabel*> m_imgLabelmap;
};

#endif // GIRDVIEW_H
