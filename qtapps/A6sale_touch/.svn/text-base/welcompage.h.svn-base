#ifndef WELCOMPAGE_H
#define WELCOMPAGE_H

#include "agraphicsrectobject.h"

class WelcomPage : public AGraphicsRectObject
{
    Q_OBJECT

public:
    WelcomPage(QGraphicsItem *parent = 0);
    ~WelcomPage();

    void setWelcomPic(const QString &picPath);

public slots:
    void showWelcomPage();

signals:
    void enter();

protected:
    void keyPressEvent(QKeyEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsPixmapItem *m_welcomPic;
};

#endif // WELCOMPAGE_H
