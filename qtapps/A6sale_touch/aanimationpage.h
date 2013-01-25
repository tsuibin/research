#ifndef AANIMATIONPAGE_H
#define AANIMATIONPAGE_H

#include "agraphicsrectobject.h"

class AAnimationPage : public AGraphicsRectObject
{
    Q_OBJECT
public:
    AAnimationPage(QGraphicsItem *parent = 0);
    void setWallPaper(QString wallpic);

public slots:
    void showPage();

protected:
    void keyPressEvent(QKeyEvent * event);
    void hidePage();
    virtual void setupUI() = 0;
    virtual void resetPage();

protected slots:
    virtual void keyEscape_handler();
    virtual void keyReturn_handler();
    virtual void keyUp_handler();
    virtual void keyDown_handler();
    virtual void keyLeft_handler();
    virtual void keyRight_handler();


signals:
    void start();
    void quitPage();

private:
    QGraphicsPixmapItem *m_wallpaper;
};

#endif // AANIMATIONPAGE_H
