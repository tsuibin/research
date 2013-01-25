#include <QApplication>
#include <QState>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QSignalTransition>
#include <QStateMachine>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>

#include "featurequeryitem.h"
#include "featurequerypage.h"
#include "commonmenupage.h"
#include "acontrolbutton.h"
#include "agraphicspixmapobject.h"
#include "emenuenv.h"
#include "dishdata.h"

FeatureQueryPage::FeatureQueryPage(QGraphicsItem *parent) :
        AAnimationPage(parent)
{
    this->setupUI();
}

FeatureQueryPage::~FeatureQueryPage()
{
}

void FeatureQueryPage::setupUI()
{
    this->setWallPaper(EmenuEnv::themeDir + "/bg.jpg");

    this->setupRootItems();
    this->setupDetailItems();
    this->setupItemAnimations();
    this->setupDetailItemAnimation();
}

void FeatureQueryPage::setupRootItems()
{
    this->m_rootPage = new AGraphicsRectObject(this);

    this->returnButton = new AControlButton(EmenuEnv::themeDir + "/control_return.png",EmenuEnv::themeDir + "/control_return_d.png",this->m_rootPage);
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

    this->m_queryItems = new AGraphicsRectObject(this->m_rootPage);
    const int columnCount = 5;
    const int rowCount = 5;
    const int itemCount = columnCount * rowCount;
    FeatureQueryItem *item = 0;
    for (int i = 0; i < itemCount; i++) {
        item = new FeatureQueryItem(this->m_queryItems);
        item->setZValue(1);
        switch (EmenuEnv::currentResolution) {
        case EmenuEnv::R_1280_768:
            item->setPos(QPointF((i % columnCount) * 230, (i / columnCount) * 130 ));
            break;
        case EmenuEnv::R_640_480:
        default:
            item->setPos(QPointF((i % columnCount) * 50, (i / columnCount) * 50 ));
            break;
        }
        item->setId(i);
        connect(item,SIGNAL(pressed(int)),this,SLOT(selectItem(int)));
        connect(item,SIGNAL(clicked(int)),this,SLOT(itemSelected()));
        this->m_queryItemList.append(item);
    }

    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_queryItems->setPos(60,80);
        break;
    case EmenuEnv::R_640_480:
    default:
        this->m_queryItems->setPos(50,50);
        break;
    }

    this->currentItemIndex = 0;
    this->m_queryItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Active);
    this->isSelectable = true;
}

void FeatureQueryPage::setupItemAnimations()
{
//    QState *smallState = new QState();
//    QState *bigState = new QState();
//
//    for (int i = 0; i < this->itemList.size(); i++) {
//        smallState->assignProperty(this->itemList[i],"scale", 0);
//        bigState->assignProperty(this->itemList[i],"scale",1);
//    }
// //QSequentialAnimationGroup *showItemGroup = new QSequentialAnimationGroup(this);
//    QParallelAnimationGroup *showItemGroup = new QParallelAnimationGroup(this);
//
////    for (int i = 0; i < 1 /*this->itemList.size()*/; i++) {
////        QPropertyAnimation *anim = new QPropertyAnimation(this->itemList[i], "scale", this);
////        anim->setDuration(300);
////        anim->setEasingCurve(QEasingCurve::OutQuint);
////        showItemGroup->addAnimation(anim);
////    }
//
//    QSignalTransition *trans = smallState->addTransition(this, SIGNAL(showItem()), bigState);
//    trans->addAnimation(showItemGroup);
////    connect(showItemGroup,SIGNAL(finished()),this,SLOT(startSelect()));
//    connect(bigState,SIGNAL(entered()),this,SLOT(startSelect()));
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

void FeatureQueryPage::setupDetailItems()
{
    this->m_detailPage = new CommonMenuPage(this);
    connect(this->m_detailPage,SIGNAL(quitPage()),this,SLOT(quitDetail()));
    this->m_detailPage->setPos(0,0);
    this->m_detailPage->setVisible(false);
    this->isDetailStates = false;
}

void FeatureQueryPage::setupDetailItemAnimation()
{
//    QState *inState = new QState();
//    QState *outState = new QState();
//    inState->assignProperty(this->searchChildWidget,"pos", QPointF(320,240));
//    outState->assignProperty(this->searchChildWidget,"pos", QPoint(320,-240));
//
////   QPropertyAnimation *anim = new QPropertyAnimation(this->searchChildWidget, "pos", this);
////    anim->setDuration(750);
////    anim->setEasingCurve(QEasingCurve::InOutExpo);
//
//    QSignalTransition *trans = inState->addTransition(this, SIGNAL(childOut()), outState);
////    trans->addAnimation(anim);
////    connect(anim,SIGNAL(finished()),this,SIGNAL(showItem()));
//
//    connect(this,SIGNAL(childOut()),this,SIGNAL(showItem()));
//
//
////    anim = new QPropertyAnimation(this->searchChildWidget, "pos", this);
////    anim->setDuration(750);
////    anim->setEasingCurve(QEasingCurve::InOutExpo);
//    trans = outState->addTransition(this, SIGNAL(childIn()), inState);
////    trans->addAnimation(anim);
//
//
//    QStateMachine *states = new QStateMachine(this);
//    states->addState(inState);
//    states->addState(outState);
//    states->setInitialState(outState);
//    states->start();
}

void FeatureQueryPage::setData(const QMap <int,CategoryData *> * categoryIdMap)
{
    this->m_categoryIdMap = categoryIdMap;
    this->m_categoryList = this->m_categoryIdMap->values();

    for (int i = 0; i < this->m_queryItemList.size(); i++) {
        if (i < this->m_categoryList.size()) {
            this->m_queryItemList.at(i)->setId(i);
            this->m_queryItemList.at(i)->setVisible(true);
            this->m_queryItemList.at(i)->setData(this->m_categoryList.at(i)->name);
        } else {
            this->m_queryItemList.at(i)->setVisible(false);
        }
    }
}

void FeatureQueryPage::startSelect()
{
//    this->m_queryItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Active);
//    this->isSelectable = true;
}

void FeatureQueryPage::closeSelect()
{
//    this->isSelectable = false;
//    this->m_queryItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Normal);
}

void FeatureQueryPage::selectItem(int index)
{
    if (this->isSelectable == false) return;
    if (index >= 0 && index < this->m_queryItemList.size()) {
        this->m_queryItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Normal);
        this->currentItemIndex = index;
        this->m_queryItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Active);
    }
}

void FeatureQueryPage::itemSelected()
{
    if (this->isSelectable == false) return;
    this->enterDetail();
}

void FeatureQueryPage::enterDetail()
{
    if (this->isDetailStates == false) {
        this->m_detailPage->setData(&(this->m_categoryList.at(this->currentItemIndex)->dishDataList));
        this->m_detailPage->showPage();
        this->m_rootPage->setVisible(false);
        this->isDetailStates = true;
    }
}

void FeatureQueryPage::quitDetail()
{
    this->m_rootPage->setVisible(true);
    this->setFocus();
    this->m_detailPage->setVisible(false);
    this->isDetailStates = false;
}

void FeatureQueryPage::keyUp_handler()
{
    int index = this->currentItemIndex - 5;
    if (index < 0) {
        index += this->m_queryItemList.size();
    }
    this->selectItem(index);
}

void FeatureQueryPage::keyDown_handler()
{
    int index = this->currentItemIndex + 5;
    if (index >= this->m_queryItemList.size()) {
        index -= this->m_queryItemList.size();
    }
    this->selectItem(index);
}

void FeatureQueryPage::keyLeft_handler()
{
    int index = this->currentItemIndex - 1;
    if (index < 0) {
        index += this->m_queryItemList.size();
    }
    this->selectItem(index);
}

void FeatureQueryPage::keyRight_handler()
{
    int index = this->currentItemIndex + 1;
    if (index >= this->m_queryItemList.size()) {
        index = 0;
    }
    this->selectItem(index);
}

void FeatureQueryPage::keyReturn_handler()
{
    this->itemSelected();
}

void FeatureQueryPage::keyEscape_handler()
{
    if (this->isDetailStates == true) {
        this->quitDetail();
    } else {
        this->hidePage();
    }
}

void FeatureQueryPage::resetPage()
{
//    this->currentItemIndex = 0;
    this->selectItem(0);
}
