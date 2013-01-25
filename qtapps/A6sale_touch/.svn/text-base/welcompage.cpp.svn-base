#include <QKeyEvent>
#include <QDebug>

#include "welcompage.h"
#include "emenuenv.h"

WelcomPage::WelcomPage(QGraphicsItem *parent) :
        AGraphicsRectObject(parent)
{
    this->setFlag(QGraphicsItem::ItemIsFocusable,true);
    this->setVisible(false);
    this->setRect(0,0,EmenuEnv::resolutionWidth,EmenuEnv::resolutionHeight);

    this->m_welcomPic = new QGraphicsPixmapItem(this);
}

WelcomPage::~WelcomPage()
{
}

void WelcomPage::showWelcomPage()
{
    this->setVisible(true);
    this->setFocus();
}

void WelcomPage::setWelcomPic(const QString &picPath)
{    
    this->m_welcomPic->setPixmap(QPixmap(picPath));
}

void WelcomPage::keyPressEvent(QKeyEvent * event)
{
    switch (event->key()) {
    case Qt::Key_Return:
        emit this->enter();
        this->setVisible(false);
        break;

    default:
        break;
    }
}

void WelcomPage::mousePressEvent(QGraphicsSceneMouseEvent */*event*/)
{
    emit this->enter();
    this->setVisible(false);
}
