#include <QTimer>
#include <QKeyEvent>
#include <QDebug>

#include "aanimationpage.h"

AAnimationPage::AAnimationPage(QGraphicsItem *parent) :
    AGraphicsRectObject(parent)
{
    this->setFlag(QGraphicsItem::ItemIsFocusable,true);
    this->setVisible(false);
    this->m_wallpaper = 0;
}

void AAnimationPage::setWallPaper(QString wallpic)
{
    if (this->m_wallpaper) {
        this->m_wallpaper->setPixmap(QPixmap(wallpic));
    } else {
        this->m_wallpaper = new QGraphicsPixmapItem(wallpic, this);
        this->m_wallpaper->setZValue(0);
        this->m_wallpaper->setPos(0,0);
    }
}

void AAnimationPage::showPage()
{
    this->setVisible(true);
    this->setFocus();
    this->resetPage();
    QTimer::singleShot(500,this,SIGNAL(start()));
}

void AAnimationPage::hidePage()
{
    this->setVisible(false);
    emit this->quitPage();
}

void AAnimationPage::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Escape:
        this->keyEscape_handler();
        break;

    case Qt::Key_Return:
        this->keyReturn_handler();
        break;

    case Qt::Key_Up:
        this->keyUp_handler();
        break;

    case Qt::Key_Down:
        this->keyDown_handler();
        break;

    case Qt::Key_Left:
        this->keyLeft_handler();
        break;

    case Qt::Key_Right:
        this->keyRight_handler();
        break;

    default:
        break;
    }
}

void AAnimationPage::keyEscape_handler()
{

}

void AAnimationPage::keyReturn_handler()
{

}

void AAnimationPage::keyUp_handler()
{

}

void AAnimationPage::keyDown_handler()
{

}

void AAnimationPage::keyLeft_handler()
{

}

void AAnimationPage::keyRight_handler()
{

}

void AAnimationPage::resetPage()
{

}
