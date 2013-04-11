#ifndef PREVIEW_H
#define PREVIEW_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>



namespace Ui {
class Preview;
}

class Preview : public QWidget
{
    Q_OBJECT
    
public:
    explicit Preview(QWidget *parent = 0);
    ~Preview();
    void setImagePath(QString path);

public slots:

    void test();
    void nextImage();
    void prevImage();

protected:

    bool event ( QEvent * event );

private:
    Ui::Preview *ui;
    QString m_imgPath;
    QLabel *m_imageLabel;
};

#endif // PREVIEW_H
