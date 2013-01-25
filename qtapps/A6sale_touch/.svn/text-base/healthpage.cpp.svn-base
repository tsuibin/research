#include <QPropertyAnimation>
#include <QSignalTransition>
#include <QKeyEvent>
#include <QFont>
#include <QDebug>

#include "healthpage.h"
#include "healthitem.h"
#include "healthkinditem.h"
#include "emenuenv.h"
#include "agraphicspixmapobject.h"
#include "agraphicsrectobject.h"

HealthPage::HealthPage(QGraphicsItem *parent) :
        AAnimationPage(parent)
{
    this->setupUI();
}

void HealthPage::setupUI()
{
    this->setWallPaper(EmenuEnv::themeDir + "/bg.jpg");

    this->setupRootItems();
    this->setupDetailItems();
    this->setupItemAnimations();
    this->setupDetailItemAnimation();
}

void HealthPage::showHealthPage()
{
    this->m_stateMachine->start();
    this->setVisible(true);
    this->setFocus();
}

void HealthPage::hideHealthPage()
{
    this->m_stateMachine->stop();
    this->setVisible(false);
    emit this->quitPage();
}

void HealthPage::setupRootItems()
{
    this->m_rootPage = new AGraphicsRectObject(this);
    this->m_rootPage->setPos(0,0);

    this->m_naviBar = new AGraphicsPixmapObject(this->m_rootPage);
    this->m_naviBar->setPixmap(QPixmap(EmenuEnv::themeDir + "/hea_kindbg.png"));
    this->m_naviBar->setPos(19,35);
    this->m_naviBar->setZValue(1);

//    this->m_cursor = new AGraphicsPixmapObject(this->m_rootPage);
//    this->m_cursor->setPixmap(QPixmap(EmenuEnv::themeDir + "/hea_cursor.png"));
//    this->m_cursor->setZValue(2);

    AGraphicsPixmapObject *item = 0;
    for (int i = 0; i < 6; i++) {
        item = new AGraphicsPixmapObject(this->m_rootPage);
//        item->setPixmap(QPixmap("./tmp/icon.png"));
        item->setPos(i * 60 + 100, 426);
        this->m_kindItems.append(item);
        item->setZValue(3);
    }

    HealthItem *r_item = 0;
    QList <HealthItem*> *itemList = 0;
    for (int i = 0; i < 6; i++) {
        itemList = new QList <HealthItem*>;
        for (int j = 0; j < 5; j++) {
            r_item = new HealthItem(this->m_rootPage);
            itemList->append(r_item);
        }
        itemList->at(0)->setStatus(AGraphicsSelectItem::Active);
        this->m_dishList.append(itemList);
    }

}

void HealthPage::setupItemAnimations()
{
    QState *state = 0;
    for (int i = 0; i < 6; i++) {
        state = new QState();
//        state->assignProperty(this->m_wallpaper,"pos",QPointF(- 50 * i, 0));
//        state->assignProperty(this->m_cursor,"pos",QPointF(100 * i + 21, 37.5));

        for (int k = 0; k < this->m_dishList.size(); k++) {
            if (k < i) {
                for (int j = 0; j < this->m_dishList.at(k)->size(); j++) {
                    state->assignProperty(this->m_dishList.at(k)->at(j),"pos",QPointF(-700,73 * j + 85));
                    state->assignProperty(this->m_dishList.at(k)->at(j),"visible",false);
                }
            } else if (k == i) {
                for (int j = 0; j < this->m_dishList.at(k)->size(); j++) {
                    state->assignProperty(this->m_dishList.at(k)->at(j),"pos",QPointF(17,73 * j + 85));
                    state->assignProperty(this->m_dishList.at(k)->at(j),"visible",true);
                }
            } else {
                for (int j = 0; j < this->m_dishList.at(k)->size(); j++) {
                    state->assignProperty(this->m_dishList.at(k)->at(j),"pos",QPointF(700,73 * j + 85));
                    state->assignProperty(this->m_dishList.at(k)->at(j),"visible",false);
                }
            }
        }
        this->m_states.append(state);
    }

    this->m_group = new QParallelAnimationGroup(this);
    QPropertyAnimation *anim = 0;
//    anim = new QPropertyAnimation(this->m_wallpaper, "pos", this);
//    anim->setDuration(500);
//    anim->setEasingCurve(QEasingCurve::OutExpo);
//    this->m_group->addAnimation(anim);

//    anim = new QPropertyAnimation(this->m_cursor, "pos", this);
//    anim->setDuration(500);
//    anim->setEasingCurve(QEasingCurve::OutExpo);
//    this->m_group->addAnimation(anim);

    for (int i = 0; i < this->m_dishList.size(); i++) {
        for (int j = 0; j < this->m_dishList.at(i)->size(); j++) {
            anim = new QPropertyAnimation(this->m_dishList.at(i)->at(j), "pos", this);
            anim->setDuration(500);
            anim->setEasingCurve(QEasingCurve::OutExpo);
            this->m_group->addAnimation(anim);
        }
    }

    this->m_stateMachine = new QStateMachine(this);
    for (int i = 0; i < this->m_states.size(); i++) {
        this->m_stateMachine->addState(this->m_states.at(i));

        if (i != 0) {
            QSignalTransition *trans = this->m_states.at(i)->addTransition(this,SIGNAL(left()),this->m_states.at(i - 1));
            trans->addAnimation(this->m_group);
        }

        if (i != this->m_states.size() - 1) {
            QSignalTransition *trans = this->m_states.at(i)->addTransition(this,SIGNAL(right()),this->m_states.at(i + 1));
            trans->addAnimation(this->m_group);
        }
    }

    this->m_stateMachine->setInitialState(this->m_states.at(0));
    this->m_stateMachine->start();
}

void HealthPage::setupDetailItems()
{    
    this->m_detailPage = new AGraphicsRectObject(this);
    this->m_detailPage->setPos(0,0);

    QGraphicsPixmapItem *picBg = new QGraphicsPixmapItem(this->m_detailPage);
    picBg->setPixmap(QPixmap(EmenuEnv::themeDir + "/dis_detailbg.png"));
    picBg->setPos(25,60);
    this->m_dishPic = new QGraphicsPixmapItem(picBg);
    this->m_dishPic->setPixmap(QPixmap(EmenuEnv::dishPicDir + "/big/2.jpg"));

    this->m_dishPic->setPos(15,15);

    QFont font;
    this->m_dishName = new QGraphicsTextItem(this->m_detailPage);
    this->m_dishName->setPos(25,314);
    this->m_dishName->setTextWidth(330);
    font.setPointSize(18);
    this->m_dishName->setFont(font);
    this->m_dishName->setDefaultTextColor(EmenuEnv::textHeadingColor);
    this->m_dishName->setHtml("<p align = center> " + tr("菜品名称") + "</p>");

    QGraphicsTextItem *levelTip = new QGraphicsTextItem(this->m_detailPage);
    levelTip->setPos(25,400);
    font.setPointSize(16);
    levelTip->setFont(font);
    levelTip->setDefaultTextColor(EmenuEnv::textNormalColor);
    levelTip->setPlainText(tr("功效级别："));

    this->m_levelStars = new AGraphicsRectObject(this->m_detailPage);
    QGraphicsPixmapItem *star = 0;
    for (int i = 0; i < 5; i++) {
        star = new QGraphicsPixmapItem(this->m_levelStars);
        star->setPixmap(QPixmap(EmenuEnv::themeDir + "/hea_levelstar_b.png"));
        star->setPos(QPoint(i * 30, 0));
        star->setZValue(1);
        this->m_levelStarList.append(star);
    }
    this->m_levelStars->setPos(150,400);

    this->m_icons = new AGraphicsRectObject(this->m_detailPage);
    QGraphicsPixmapItem *icon = 0;
    for (int i = 0; i < 9; i++) {
        icon = new QGraphicsPixmapItem(this->m_icons);
        icon->setPixmap(QPixmap(EmenuEnv::themeDir + "/icon_fish.png"));
        icon->setPos(QPoint((i % 3) * 70, i / 3 * 70));
        icon->setZValue(1);
        this->m_iconList.append(icon);
    }
    this->m_icons->setPos(380,70);

    this->m_detailPage->setVisible(false);
    this->isDetail = false;
}

void HealthPage::setupDetailItemAnimation()
{
}

void HealthPage::enterDetail()
{
    if (this->isDetail == false) {
        this->m_rootPage->setVisible(false);
        this->m_detailPage->setVisible(true);
        this->isDetail = true;
    }
}

void HealthPage::quitDetail()
{
    this->m_rootPage->setVisible(true);
    this->m_detailPage->setVisible(false);
    this->isDetail = false;
}

void HealthPage::keyUp_handler()
{
    if (this->m_group->state() == QAbstractAnimation::Stopped) {
        emit this->up();
    }
}

void HealthPage::keyDown_handler()
{
    if (this->m_group->state() == QAbstractAnimation::Stopped) {
        emit this->down();
    }
}

void HealthPage::keyLeft_handler()
{
    if (this->m_group->state() == QAbstractAnimation::Stopped) {
        emit this->left();
    }
}

void HealthPage::keyRight_handler()
{
    if (this->m_group->state() == QAbstractAnimation::Stopped) {
        emit this->right();
    }
}

void HealthPage::keyReturn_handler()
{
   this->enterDetail();
}

void HealthPage::keyEscape_handler()
{
    if (this->isDetail == false) {
        this->hideHealthPage();
    } else {
        this->quitDetail();
    }
}
