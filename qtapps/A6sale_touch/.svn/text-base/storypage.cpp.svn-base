#include <QGraphicsWidget>
#include <QKeyEvent>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QSignalTransition>
#include <QStateMachine>
#include <QTimer>
#include <QPen>
#include <QDebug>

#include "storypage.h"
#include "acontrolbutton.h"
#include "agraphicspixmapobject.h"
#include "agraphicsrectobject.h"
#include "storyselectitem.h"
#include "storytextitem.h"
#include "commondetail.h"
#include "emenuenv.h"
#include "dishdata.h"

StoryPage::StoryPage(QGraphicsItem *parent) :
        AAnimationPage(parent), m_storyDataList(0)
{
    this->setupUI();
}

void StoryPage::setupUI()
{
    this->setWallPaper(EmenuEnv::themeDir + "/bg.jpg");

    this->returnButton = new AControlButton(EmenuEnv::themeDir + "/control_return.png",EmenuEnv::themeDir + "/control_return_d.png",this);
    connect(this->returnButton,SIGNAL(clicked()),this,SLOT(keyEscape_handler()));
    this->returnButton->setZValue(10);
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->returnButton->setPos(1200,0);
        break;
    case EmenuEnv::R_640_480:
    default:
        break;
    }

    this->setupRootItems();
    this->setupDetailItems();
    this->setupItemAnimations();
    this->setupDetailItemAnimation();
}

void StoryPage::keyEscape_handler()
{
    if (this->isDetailStates == false) {
        this->hidePage();
    } else {
        this->quitDetail();
    }
}

void StoryPage::setupRootItems()
{
    this->m_rootPage = new AGraphicsRectObject(this);
    this->m_rootPage->setPos(0,0);
    this->initStorySelector();
    this->initStoryTextArea();

    this->enterButton = new AControlButton(EmenuEnv::themeDir + "/control_right.png",EmenuEnv::themeDir + "/control_right_d.png",this->m_rootPage);
    connect(this->enterButton,SIGNAL(clicked()),this,SLOT(keyReturn_handler()));
    this->enterButton->setZValue(10);
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->enterButton->setPos(1200,380);
        break;
    case EmenuEnv::R_640_480:
    default:
        break;
    }
}

void StoryPage::initStorySelector()
{
    this->m_storySelector = new AGraphicsRectObject(this->m_rootPage);

    const int itemCount = 6;
    StorySelectItem *item = 0;
    for (int i = 0; i < itemCount; i++) {
        item = new StorySelectItem(this->m_storySelector);
        item->setZValue(i);
        connect(item,SIGNAL(pressed(int)),this,SLOT(selectItem(int)));
        this->m_storyItemList.append(item);
    }

    this->m_storySelector->setZValue(1);

    this->currentItemIndex = 0;
    this->m_storyItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Active);

    //set resolution
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_storySelector->setPos(95,96);
        for (int i = 0; i < this->m_storyItemList.size(); i++) {
            this->m_storyItemList.at(i)->setPos(0, i * 70);
        }
        break;

    case EmenuEnv::R_640_480:
    default:
        this->m_storySelector->setPos(11,46);
        for (int i = 0; i < this->m_storyItemList.size(); i++) {
            this->m_storyItemList.at(i)->setPos(0, i * 50);
        }
        break;
    }
}

void StoryPage::initStoryTextArea()
{
    this->m_storyText = new AGraphicsRectObject(this->m_rootPage);

    this->m_textScrollArea = new AGraphicsRectObject(this->m_storyText);
    this->m_textScrollArea->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    this->m_textScrollArea->setPen(QPen(Qt::transparent));
    this->m_textScrollArea->setZValue(0);

    QGraphicsPixmapItem *m_textScrollAreaBg = new QGraphicsPixmapItem(QPixmap(EmenuEnv::themeDir + "/sto_textbg.png"),this->m_textScrollArea);
    m_textScrollAreaBg->setZValue(0);
    m_textScrollAreaBg->setPos(0,0);

    this->m_textScrollContent = new AGraphicsRectObject(this->m_textScrollArea);
    this->m_textScrollContent->setPos(0,0);

    const int itemCount = 6;
    StoryTextItem *item = 0;
    for (int i = 0; i < itemCount; i++) {
        item = new StoryTextItem(this->m_textScrollContent);
        item->setZValue(1);
        this->m_textItemList.append(item);
    }

    AGraphicsPixmapObject *m_roller_up = new AGraphicsPixmapObject(this->m_storyText);
    m_roller_up->setPixmap(QPixmap(EmenuEnv::themeDir + "/sto_scrollbar_up.png"));
    m_roller_up->setZValue(1);
    m_roller_up->setPos(0,0);

    this->m_roller_down = new AGraphicsPixmapObject(this->m_storyText);
    this->m_roller_down->setPixmap(QPixmap(EmenuEnv::themeDir + "/sto_scrollbar_down.png"));
    this->m_roller_down->setZValue(2);

    this->m_storyText->setZValue(1);

    //set resolution
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_textScrollArea->setRect(0,0,674,588);
        this->m_textScrollArea->setPos(32,25);
        for (int i = 0; i < this->m_textItemList.size(); i++) {
            this->m_textItemList.at(i)->setPos(0, i * 588);
        }
        this->m_roller_down->setPos(0,728);
        this->m_storyText->setPos(449,71);
        break;

    case EmenuEnv::R_640_480:
    default:
        this->m_textScrollArea->setRect(0,0,361,361);
        this->m_textScrollArea->setPos(16,21);
        for (int i = 0; i < this->m_textItemList.size(); i++) {
            this->m_textItemList.at(i)->setPos(0, i * 361);
        }
        this->m_roller_down->setPos(0,372);
        this->m_storyText->setPos(225,47);
        break;
    }
}

void StoryPage::setupDetailItems()
{
    this->m_detailPage = new CommonDetail(this);
    this->m_detailPage->setPos(0,0);
    this->m_detailPage->setVisible(false);
    this->isDetailStates = false;
}

void StoryPage::setupItemAnimations()
{
    QParallelAnimationGroup *group = 0;
    QPropertyAnimation *anim = 0;
    QSignalTransition *trans = 0;
    int duration = 500;

    QState *quitState = new QState();
    QState *rootState = new QState();
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        quitState->assignProperty(this->m_storySelector,"pos",QPointF(-330,96));
        quitState->assignProperty(this->m_storyText,"pos",QPointF(1300,71));
        rootState->assignProperty(this->m_storySelector,"pos",QPointF(95,96));
        rootState->assignProperty(this->m_storyText,"pos",QPointF(449,71));
        break;
    case EmenuEnv::R_640_480:
    default:
        quitState->assignProperty(this->m_storySelector,"pos",QPointF(-210,46));
        quitState->assignProperty(this->m_storyText,"pos",QPointF(660,47));
        rootState->assignProperty(this->m_storySelector,"pos",QPointF(11,46));
        rootState->assignProperty(this->m_storyText,"pos",QPointF(225,47));
        break;
    }
    group = new QParallelAnimationGroup(this);
    anim = new QPropertyAnimation(this->m_storySelector, "pos", this);
    anim->setDuration(duration);
    anim->setEasingCurve(QEasingCurve::OutExpo);
    group->addAnimation(anim);
    anim = new QPropertyAnimation(this->m_storyText, "pos", this);
    anim->setDuration(duration);
    anim->setEasingCurve(QEasingCurve::OutExpo);
    group->addAnimation(anim);

    trans = quitState->addTransition(this,SIGNAL(start()),rootState);
    trans->addAnimation(group);
    connect(group,SIGNAL(finished()),this,SIGNAL(textStart()));
    trans = rootState->addTransition(this,SIGNAL(quitPage()),quitState);

    duration = 1000;
    QState *textQuitState = new QState(rootState);
    QState *textRootState = new QState(rootState);

    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        textQuitState->assignProperty(this->m_textScrollArea,"rect",QRectF(0,0,674,50));
        textQuitState->assignProperty(this->m_roller_down,"pos",QPointF(0,50));
        textRootState->assignProperty(this->m_textScrollArea,"rect",QRectF(0,0,674,588));
        textRootState->assignProperty(this->m_roller_down,"pos",QPointF(0,588));
        break;
    case EmenuEnv::R_640_480:
    default:
        textQuitState->assignProperty(this->m_textScrollArea,"rect",QRectF(0,0,361,24));
        textQuitState->assignProperty(this->m_roller_down,"pos",QPointF(0,35));
        textRootState->assignProperty(this->m_textScrollArea,"rect",QRectF(0,0,361,361));
        textRootState->assignProperty(this->m_roller_down,"pos",QPointF(0,372));
        break;
    }

    group = new QParallelAnimationGroup(this);
    anim = new QPropertyAnimation(this->m_textScrollArea, "rect", this);
    anim->setDuration(duration);
    anim->setEasingCurve(QEasingCurve::OutExpo);
    group->addAnimation(anim);
    anim = new QPropertyAnimation(this->m_roller_down, "pos", this);
    anim->setDuration(duration);
    anim->setEasingCurve(QEasingCurve::OutExpo);
    group->addAnimation(anim);

    trans = textQuitState->addTransition(this,SIGNAL(textStart()),textRootState);
    trans->addAnimation(group);

    const int stateCount = 6;
    QList <QState *> textStateList;
    QState *state = 0;
    for (int i = 0; i < stateCount; i++) {
        state = new QState(textRootState);
        for (int j = 0; j < this->m_textItemList.size(); j++) {
            switch (EmenuEnv::currentResolution) {
            case EmenuEnv::R_1280_768:
                state->assignProperty(this->m_textScrollContent,"pos",QPointF(0,-(588 * i)));
                break;
            case EmenuEnv::R_640_480:
            default:
                state->assignProperty(this->m_textScrollContent,"pos",QPointF(0,-(361 * i)));
                break;
            }
        }
        textStateList.append(state);
    }
    duration = 500;
    group = new QParallelAnimationGroup(this);

    anim = new QPropertyAnimation(this->m_textScrollContent, "pos", this);
    anim->setDuration(duration);
    group->addAnimation(anim);

    for (int i = 0; i < textStateList.size(); i++) {
        trans = textRootState->addTransition(this->m_storyItemList.at(i),SIGNAL(active(int)),textStateList.at(i));
        trans->addAnimation(group);
    }

    textRootState->setInitialState(textStateList.at(0));

    rootState->setInitialState(textQuitState);

    QStateMachine *stateMachine = new QStateMachine(this);
    stateMachine->addState(quitState);
    stateMachine->addState(rootState);
    stateMachine->setInitialState(quitState);
    stateMachine->start();

    this->isSelectable = true;
}

void StoryPage::setupDetailItemAnimation()
{
}

void StoryPage::setData(const QList <const StoryData *> * storyDataList)
{
    this->m_storyDataList = storyDataList;

    for (int i = 0; i < this->m_storyItemList.size(); i++) {
        if (i < this->m_storyDataList->size()) {
            this->m_storyItemList.at(i)->setData(i,this->m_storyDataList->at(i)->dishData->name);
            this->m_storyItemList.at(i)->setVisible(true);
        } else {
            this->m_storyItemList.at(i)->setData(-1,QString());
            this->m_storyItemList.at(i)->setVisible(false);
        }
    }

    for (int i = 0; i < this->m_textItemList.size(); i++) {
        if (i < this->m_storyDataList->size()) {
            this->m_textItemList.at(i)->setItemData(this->m_storyDataList->at(i)->dishData->pic,
                                                    this->m_storyDataList->at(i)->story);
            this->m_textItemList.at(i)->setVisible(true);
        } else {
            this->m_textItemList.at(i)->setItemData(QString(),QString());
            this->m_textItemList.at(i)->setVisible(false);
        }
    }
}

void StoryPage::itemSelected()
{
    if (this->isSelectable == false) return;
    this->enterDetail();
}

void StoryPage::enterDetail()
{
    if (this->isDetailStates == false) {
        this->m_detailPage->setData(this->m_storyDataList->at(this->currentItemIndex)->dishData);
        this->m_detailPage->setVisible(true);
        this->m_rootPage->setVisible(false);
        this->isDetailStates = true;
    }
}

void StoryPage::quitDetail()
{
    this->m_detailPage->setVisible(false);
    this->m_rootPage->setVisible(true);
    this->isDetailStates = false;
}

void StoryPage::selectItem(int index)
{
    if (this->isSelectable == false) return;
    if (index >= 0 && index < this->m_storyItemList.size()) {
        this->m_storyItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Normal);
        this->currentItemIndex = index;
        this->m_storyItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Active);
    }
}

void StoryPage::keyUp_handler()
{
    int index = this->currentItemIndex - 1;
    if (index < 0) {
        return;
    }
    this->selectItem(index);
}

void StoryPage::keyDown_handler()
{
    int index = this->currentItemIndex + 1;
    if (index >= this->m_storyItemList.size()) {
        return;
    }
    this->selectItem(index);
}

void StoryPage::keyReturn_handler()
{
    this->itemSelected();
}

void StoryPage::resetPage()
{
    if (this->currentItemIndex != 0) {
        this->selectItem(0);
    }
}
