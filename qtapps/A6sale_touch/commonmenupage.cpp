#include <QState>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QSignalTransition>
#include <QStateMachine>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>

#include <math.h>

#include "commonmenupage.h"
#include "commonmenuitem.h"
#include "commondetail.h"
#include "acontrolbutton.h"
#include "agraphicspixmapobject.h"
#include "emenuenv.h"
#include "emenudata.h"

CommonMenuPage::CommonMenuPage(QGraphicsItem *parent) :
        AAnimationPage(parent)
{
    this->setupUI();
}

CommonMenuPage::~CommonMenuPage()
{
}

void CommonMenuPage::setupUI()
{
    this->setWallPaper(EmenuEnv::themeDir + "/bg.jpg");

    this->returnButton = new AControlButton(EmenuEnv::themeDir + "/control_return.png",EmenuEnv::themeDir + "/control_return_d.png",this);
    connect(this->returnButton,SIGNAL(clicked()),this,SLOT(keyEscape_handler()));
//    this->returnButton->setZValue(10);
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

void CommonMenuPage::setData(const QList <const DishData *> *dishDataList)
{
    this->m_dishDataList = dishDataList;
    this->m_pageCount = (this->m_dishDataList->size() - 1) / this->m_itemPerPage + 1;
    this->m_currentPage = 0;
    this->updatePage();
}

void CommonMenuPage::setupRootItems()
{
    this->m_rootPage = new AGraphicsRectObject(this);

    this->upButton = new AControlButton(EmenuEnv::themeDir + "/control_up.png",EmenuEnv::themeDir + "/control_up_d.png",this->m_rootPage);
    connect(this->upButton,SIGNAL(clicked()),this,SLOT(keyUp_handler()));
    this->downButton = new AControlButton(EmenuEnv::themeDir + "/control_down.png",EmenuEnv::themeDir + "/control_down_d.png",this->m_rootPage);
    connect(this->downButton,SIGNAL(clicked()),this,SLOT(keyDown_handler()));
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->upButton->setPos(1200,300);
        this->downButton->setPos(1200,430);
        break;
    case EmenuEnv::R_640_480:
    default:
        break;
    }

    this->m_dishItems = new AGraphicsRectObject(this->m_rootPage);
    const int columnCount = 3;
    const int rowCount = 2;
    const int itemCount = columnCount * rowCount;
    CommonMenuItem *item = 0;
    for (int i = 0; i < itemCount; i++) {
        item = new CommonMenuItem(this->m_dishItems);
        item->setId(i);
        connect(item,SIGNAL(pressed(int)),this,SLOT(selectItem(int)));
        connect(item,SIGNAL(clicked(int)),this,SLOT(itemSelected()));
        switch (EmenuEnv::currentResolution) {
        case EmenuEnv::R_1280_768:
            item->setPos(QPointF((i % columnCount) * 370,
                                 (i / columnCount) * 300 ));
            break;
        case EmenuEnv::R_640_480:
        default:
            item->setPos(QPointF((i % columnCount) * 200,
                                 (i / columnCount) * 200 ));
            break;
        }
        this->m_dishItemList.append(item);
    }

    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_dishItems->setPos(80,100);
        break;
    case EmenuEnv::R_640_480:
    default:
        this->m_dishItems->setPos(23,56);
        break;
    }

    this->m_itemPerPage = itemCount;
    this->m_currentPage = 0;
    this->currentItemIndex = 0;
    this->m_dishItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Active);
    this->isSelectable = true;
}

void CommonMenuPage::setupItemAnimations()
{
//    QState *smallState = new QState();
//    QState *bigState = new QState();
//
//    for (int i = 0; i < this->m_itemList.size(); i++) {
//        smallState->assignProperty(this->m_itemList[i],"scale", 0);
//        bigState->assignProperty(this->m_itemList[i],"scale",1);
//    }
//
//    //QSequentialAnimationGroup *showItemGroup = new QSequentialAnimationGroup(this);
//    QParallelAnimationGroup *showItemGroup = new QParallelAnimationGroup(this);
//    for (int i = 0; i < this->m_itemList.size(); i++) {
//        QPropertyAnimation *anim = new QPropertyAnimation(this->m_itemList[i], "scale", this);
//        anim->setDuration(300);
//        anim->setEasingCurve(QEasingCurve::OutBack);
//        showItemGroup->addAnimation(anim);
//    }
//
//    QSignalTransition *trans = smallState->addTransition(this, SIGNAL(showItem()), bigState);
//    trans->addAnimation(showItemGroup);
//    connect(showItemGroup,SIGNAL(finished()),this,SLOT(startSelect()));
//
//    trans = bigState->addTransition(this,SIGNAL(hideItem()),smallState);
//    connect(smallState,SIGNAL(entered()),this,SLOT(closeSelect()));
//
//    QStateMachine *states = new QStateMachine(this);
//    states->addState(smallState);
//    states->addState(bigState);
//    states->setInitialState(smallState);
//
//    states->start();
}

void CommonMenuPage::setupDetailItems()
{
    this->m_detailPage = new CommonDetail(this);
    this->m_detailPage->setPos(0,0);

    this->detailUpButton = new AControlButton(EmenuEnv::themeDir + "/control_up.png",EmenuEnv::themeDir + "/control_up_d.png",this->m_detailPage);
    connect(this->detailUpButton,SIGNAL(clicked()),this,SLOT(detailSelectPrevious()));
    this->detailDownButton = new AControlButton(EmenuEnv::themeDir + "/control_down.png",EmenuEnv::themeDir + "/control_down_d.png",this->m_detailPage);
    connect(this->detailDownButton,SIGNAL(clicked()),this,SLOT(detailSelectnext()));
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->detailUpButton->setPos(1200,300);
        this->detailDownButton->setPos(1200,430);
        break;
    case EmenuEnv::R_640_480:
    default:
        break;
    }

    this->m_detailPage->setVisible(false);
    this->isDetailStates = false;
}

void CommonMenuPage::setupDetailItemAnimation()
{
}

void CommonMenuPage::updatePage()
{
    int index = this->m_currentPage * this->m_itemPerPage;
    this->validItemCount = this->m_dishItemList.size();
    const DishData *dishData = 0;
    for (int i = 0; i < this->m_dishItemList.size(); i++) {
        if ((index + i) < this->m_dishDataList->size()) {
            dishData = this->m_dishDataList->at(index + i);
            this->m_dishItemList.at(i)->setData(dishData->pic,dishData->name,dishData->price);
            this->m_dishItemList.at(i)->setVisible(true);
        } else {
            this->validItemCount--;
            this->m_dishItemList.at(i)->setVisible(false);
        }
    }
    this->selectItem(0);
}

void CommonMenuPage::startSelect()
{
    this->m_dishItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Active);
    this->isSelectable = true;
}

void CommonMenuPage::closeSelect()
{
    this->isSelectable = false;
    this->m_dishItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Normal);
}

void CommonMenuPage::selectItem(int index)
{
    if (this->isSelectable == false) return;
    if (index >= 0 && index < this->m_dishItemList.size()) {
        this->m_dishItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Normal);
        this->currentItemIndex = index;
        this->m_dishItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Active);
    }
}

void CommonMenuPage::itemSelected()
{
    if (this->isSelectable == false) return;
    this->enterDetail();
}

void CommonMenuPage::enterDetail()
{
    this->m_detailPage->setData(this->m_dishDataList->at(this->currentItemIndex + this->m_itemPerPage * this->m_currentPage));
    this->m_detailPage->setVisible(true);
    this->m_rootPage->setVisible(false);
    this->isDetailStates = true;
}

void CommonMenuPage::quitDetail()
{
    this->m_detailPage->setVisible(false);
    this->m_rootPage->setVisible(true);
    this->isDetailStates = false;
}

void CommonMenuPage::detailSelectnext()
{
    this->keyRight_handler();
    this->enterDetail();
}

void CommonMenuPage::detailSelectPrevious()
{
    this->keyLeft_handler();
    this->enterDetail();
}

void CommonMenuPage::keyUp_handler()
{
    if (this->m_currentPage > 0) {
        this->m_currentPage--;
        this->updatePage();
    } else {
        this->m_currentPage = this->m_pageCount - 1;
        this->updatePage();
    }
}

void CommonMenuPage::keyDown_handler()
{
    if (this->m_currentPage < this->m_pageCount - 1) {
        this->m_currentPage++;
        this->updatePage();
    } else {
        this->m_currentPage = 0;
        this->updatePage();
    }
}

void CommonMenuPage::keyLeft_handler()
{
    int index = this->currentItemIndex - 1;
    if (index < 0) {
        this->keyUp_handler();
        this->selectItem(this->validItemCount - 1);
    } else {
        this->selectItem(index);
    }
}

void CommonMenuPage::keyRight_handler()
{
    int index = this->currentItemIndex + 1;
    if (index >= this->validItemCount) {
        this->keyDown_handler();
        this->selectItem(0);
    } else {
        this->selectItem(index);
    }
}

void CommonMenuPage::keyEscape_handler()
{
    if (this->isDetailStates == true) {
        this->quitDetail();
    } else {
        this->hidePage();
    }
}

void CommonMenuPage::keyReturn_handler()
{
    this->itemSelected();
}

void CommonMenuPage::resetPage()
{
//    this->currentItemIndex = 0;
    this->m_currentPage = 0;
    this->updatePage();
    this->selectItem(0);
}
