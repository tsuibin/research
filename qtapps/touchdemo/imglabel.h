#ifndef IMGLABEL_H
#define IMGLABEL_H

#include <QLabel>
#include <QMouseEvent>

class ImgLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ImgLabel(QWidget *parent = 0);
    
signals:
    void clicked();
    
public slots:

   protected:

    void mousePressEvent(QMouseEvent *event);
    
};

#endif // IMGLABEL_H
