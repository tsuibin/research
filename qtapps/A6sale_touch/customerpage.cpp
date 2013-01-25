#include <QFont>
#include <QPropertyAnimation>
#include <QSignalTransition>
#include <QStateMachine>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>

#include "customerpage.h"
#include "agraphicspixmapobject.h"
#include "acontrolbutton.h"
#include "emenuenv.h"

CustomerPage::CustomerPage(QGraphicsItem *parent) :
        AGraphicsRectObject(parent)
{
    this->setFlag(QGraphicsItem::ItemIsFocusable,true);
    this->setVisible(false);

    this->setupItems();
    this->setupItemAnimations();
}

CustomerPage::~CustomerPage()
{
}

void CustomerPage::showCustomerPage()
{
    this->setVisible(true);
    this->setFocus();
}

void CustomerPage::quitCustomerPage()
{
    this->setVisible(false);
    emit this->quitPage();
}

void CustomerPage::keyPressEvent (QKeyEvent * event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        this->selectLeft();
        break;

    case Qt::Key_Right:
        this->selectRight();
        break;

    case Qt::Key_Return:
        this->itemSelected();
        break;

    case Qt::Key_Escape:
        this->quitCustomerPage();
        break;

    default:
        break;
    }
    event->accept();
}

void CustomerPage::itemSelected()
{
    emit this->optionSelected(m_currentSelectIndex);
}

void CustomerPage::selectLeft()
{
    if (this->m_group->state() != QAbstractAnimation::Stopped) {
        return;
    }
    if (this->m_currentSelectIndex < this->m_picItemList.size() - 1) {
        this->m_currentSelectIndex ++;
    } else {
        this->m_currentSelectIndex = 0;
    }

    emit this->left();
}

void CustomerPage::selectRight()
{
    if (this->m_group->state() != QAbstractAnimation::Stopped) {
        return;
    }

    if (this->m_currentSelectIndex > 0) {
        this->m_currentSelectIndex --;
    } else {
        this->m_currentSelectIndex += this->m_picItemList.size() - 1;
    }

    emit this->right();
}

void CustomerPage::setupItems()
{
    this->m_wallpaper = new AGraphicsPixmapObject(this);
    this->m_wallpaper->setPixmap(QPixmap(EmenuEnv::themeDir + "/cus_bg.jpg"));
    this->m_wallpaper->setZValue(0);
    this->m_wallpaper->setPos(0,0);

    this->m_textBackground = new AControlButton(EmenuEnv::themeDir + "/cus_textbg.png",EmenuEnv::themeDir + "/cus_textbg.png",this);
    this->m_textBackground->setZValue(1);
    connect(this->m_textBackground,SIGNAL(clicked()),this,SLOT(itemSelected()));

    QStringList picList;
    picList << EmenuEnv::themeDir + "/cus_story.png"
            << EmenuEnv::themeDir + "/cus_recommond.png"
            << EmenuEnv::themeDir + "/cus_rank.png"
            << EmenuEnv::themeDir + "/cus_discount.png"
            << EmenuEnv::themeDir + "/cus_health.png"
            << EmenuEnv::themeDir + "/cus_search.png"
            << EmenuEnv::themeDir + "/cus_menu.png";

    QStringList textList;
    textList << tr("菜品故事") << tr("主厨推荐") << tr("销售排行") << tr("今日特价")
             << tr("食疗养生") << tr("特色分类") << tr("菜品浏览");

    AGraphicsPixmapObject *item = 0;
    QGraphicsTextItem *t_item = 0;
    for (int i = 0; i < 7; i++) {
        item = new AGraphicsPixmapObject(picList.at(i),this);
        item->setOffset(-item->pixmap().width() / 2,-item->pixmap().height() / 2 );
        item->setZValue(3);
        item->setTransformationMode(Qt::SmoothTransformation);
        this->m_picItemList.append(item);

        t_item = new QGraphicsTextItem(textList.at(i),this);
        t_item->setDefaultTextColor(EmenuEnv::textHeadingColor);
        t_item->setZValue(2);
        this->m_textItemList.append(t_item);
    }

    this->returnButton = new AControlButton(EmenuEnv::themeDir + "/control_return.png",EmenuEnv::themeDir + "/control_return_d.png",this);
    connect(this->returnButton,SIGNAL(clicked()),this,SLOT(quitCustomerPage()));

    this->leftButton = new AControlButton(EmenuEnv::themeDir + "/control_left.png",EmenuEnv::themeDir + "/control_left_d.png",this);
    connect(this->leftButton,SIGNAL(clicked()),this,SLOT(selectLeft()));
    this->leftButton->setZValue(5);

    this->rightButton = new AControlButton(EmenuEnv::themeDir + "/control_right.png",EmenuEnv::themeDir + "/control_right_d.png",this);
    connect(this->rightButton,SIGNAL(clicked()),this,SLOT(selectRight()));
    this->rightButton->setZValue(5);

    QFont font;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_640_480:
        this->m_textBackground->setPos(150,355);
        font.setPixelSize(35);
        for (int i = 0; i < this->m_textItemList.size(); i++) {
            this->m_textItemList.at(i)->setFont(font);
        }
        break;

    case EmenuEnv::R_1280_768:
        this->m_textBackground->setPos(400,600);
        font.setPixelSize(58);
        for (int i = 0; i < this->m_textItemList.size(); i++) {
            this->m_textItemList.at(i)->setFont(font);
        }
        this->returnButton->setPos(1200,0);
        this->rightButton->setPos(840,650);
        this->leftButton->setPos(400,650);
        break;

    default:
        break;
    }
}

void CustomerPage::setupItemAnimations()
{
    QList <QPointF> picPath;
    QList <QPointF> textPath;

    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_640_480:
        picPath << QPointF(320,315) << QPointF(105,225) << QPointF(145,110)
                << QPointF(270,76)  << QPointF(375,76)  << QPointF(495,110)
                << QPointF(535,225);

        textPath << QPointF(245,385) << QPointF(70,270) << QPointF(100,125)
                 << QPointF(240,76)  << QPointF(350,76)  << QPointF(470,125)
                 << QPointF(480,270);
        break;

    case EmenuEnv::R_1280_768:
        picPath << QPointF(640,495)  << QPointF(234,372)  << QPointF(291,183)
                << QPointF(528,129)  << QPointF(753,129)  << QPointF(988,183)
                << QPointF(1050,372);

        textPath << QPointF(520,630) << QPointF(165,430) << QPointF(240,210)
                 << QPointF(490,140)  << QPointF(720,140)  << QPointF(940,210)
                 << QPointF(980,430);
        break;

    default:
        break;
    }

    QState *state = 0;
    for (int i = 0; i < 7; i++) {
        state = new QState();
        for (int j = 0; j < this->m_picItemList.size(); j++) {
            state->assignProperty(this->m_picItemList.at(j),"pos",picPath.at((i+j) % 7));
            state->assignProperty(this->m_textItemList.at(j),"pos",textPath.at((i+j)%7));
            state->assignProperty(this->m_textItemList.at(j),"opacity",1);

            if ((i + j) % 7 == 0) {
                state->assignProperty(this->m_picItemList.at(j),"scale", 1);
                state->assignProperty(this->m_textItemList.at(j),"scale",1);
            } else if ((i + j) % 7 == 6 || (i + j) % 7== 1) {
                state->assignProperty(this->m_picItemList.at(j),"scale", 0.6);
                state->assignProperty(this->m_textItemList.at(j),"scale",0.6);
            } else if ((i + j) % 7 == 2 || (i + j) % 7== 5) {
                state->assignProperty(this->m_picItemList.at(j),"scale", 0.3);
                state->assignProperty(this->m_textItemList.at(j),"scale",0.4);
            } else {
                state->assignProperty(this->m_picItemList.at(j),"scale", 0);
                state->assignProperty(this->m_textItemList.at(j),"scale",0.4);
            }
        }

        this->m_states.append(state);
    }

    this->m_group = new QParallelAnimationGroup(this);

    if (EmenuEnv::animationLevel > 0) {
        QPropertyAnimation *anim = 0;
        for (int i = 0; i < this->m_picItemList.size(); i++) {
                anim = new QPropertyAnimation(this->m_picItemList.at(i), "pos", this);
                anim->setDuration(300);
                this->m_group->addAnimation(anim);
                anim = new QPropertyAnimation(this->m_picItemList.at(i), "scale", this);
                anim->setDuration(300);
                this->m_group->addAnimation(anim);
                anim = new QPropertyAnimation(this->m_textItemList.at(i), "opacity", this);
                anim->setDuration(300);
                anim->setKeyValueAt(0,0);
                this->m_group->addAnimation(anim);
            }
    }

    QStateMachine *stateMachine = new QStateMachine(this);
    for (int i = 0; i < this->m_states.size(); i++) {
        stateMachine->addState(this->m_states.at(i));

        if (i != 0) {
            QSignalTransition *trans = this->m_states.at(i)->addTransition(this,SIGNAL(left()),this->m_states.at(i - 1));
            trans->addAnimation(this->m_group);
        } else {
            QSignalTransition *trans = this->m_states.at(i)->addTransition(this,SIGNAL(left()),this->m_states.at(this->m_states.size() - 1));
            trans->addAnimation(this->m_group);
        }

        if (i != this->m_states.size() - 1) {
            QSignalTransition *trans = this->m_states.at(i)->addTransition(this,SIGNAL(right()),this->m_states.at(i + 1));
            trans->addAnimation(this->m_group);
        } else {
            QSignalTransition *trans = this->m_states.at(i)->addTransition(this,SIGNAL(right()),this->m_states.at(0));
            trans->addAnimation(this->m_group);
        }
    }

    stateMachine->setInitialState(this->m_states.at(0));
    stateMachine->start();

    this->m_currentSelectIndex = 0;
}
