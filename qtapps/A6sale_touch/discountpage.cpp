#include <QFont>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>

#include "discountpage.h"
#include "discountitem.h"
#include "discountpriceitem.h"
#include "agraphicspixmapobject.h"
#include "agraphicsrectobject.h"
#include "acontrolbutton.h"
#include "emenuenv.h"
#include "dishdata.h"

DiscountPage::DiscountPage(QGraphicsItem *parent) :
        AAnimationPage(parent), m_discountDataList(0)
{
    this->setupUI();
}

DiscountPage::~DiscountPage()
{
}

void DiscountPage::setupUI()
{
    this->setWallPaper(EmenuEnv::themeDir + "/bg.jpg");

    this->returnButton = new AControlButton(EmenuEnv::themeDir + "/control_return.png",EmenuEnv::themeDir + "/control_return_d.png",this);
    connect(this->returnButton,SIGNAL(clicked()),this,SLOT(keyEscape_handler()));
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->returnButton->setPos(1200,0);
        break;

    case EmenuEnv::R_640_480:
    default:
        break;
    }

    this->setupRootItems();
    this->setupItemAnimations();
    this->setupDetailItems();
    this->setupDetailItemAnimation();
}

void DiscountPage::setData(const QList <const DiscountData *> *discountDataList)
{
    this->m_discountDataList = discountDataList;
    if (this->m_discountDataList->size() < 4) return;
    const DishData *dishData = 0;
    for (int i = 0; i < this->m_itemList.size(); i++) {
        dishData = this->m_discountDataList->at(i)->dishData;
        this->m_itemList.at(i)->setData(dishData->pic,dishData->name,this->m_discountDataList->at(i)->oldPrice);
        this->m_priceItemList.at(i)->setPrice(dishData->price);
    }
}

void DiscountPage::setupRootItems()
{
    this->m_rootPage = new AGraphicsRectObject(this);
    this->m_rootPage->setZValue(1);
    this->m_rootPage->setPos(0,0);

    QList <QPointF> pricePosList;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        pricePosList << QPointF(225,125) << QPointF(790,125) << QPointF(225,465) << QPointF(790,465);
        break;
    case EmenuEnv::R_640_480:
    default:
        pricePosList << QPointF(98,88) << QPointF(399,88) << QPointF(98,295) << QPointF(399,295);
        break;
    }
    DiscountPriceItem *priceItem = 0;
    for (int i = 0; i < 4; i++) {
        priceItem = new DiscountPriceItem(this->m_rootPage);
        priceItem->setZValue(3);
        priceItem->setPos(pricePosList.at(i));
        this->m_priceItemList.append(priceItem);
    }

    QStringList cornerPicList;
    cornerPicList << "/dis_topleft_c.png"       << "/dis_topright_c.png"
                  << "/dis_bottomleft_c.png"    << "/dis_bottomright_c.png";
    QList <QPointF> cornerPosList;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        cornerPosList << QPointF(191,87) << QPointF(755,87) << QPointF(191,424) << QPointF(755,424);
        break;
    case EmenuEnv::R_640_480:
    default:
        cornerPosList << QPointF(74,56) << QPointF(373,56) << QPointF(74,264) << QPointF(373,264);
        break;
    }
    AGraphicsPixmapObject *corner = 0;
    for (int i = 0; i < 4; i++) {
        corner = new AGraphicsPixmapObject(this->m_rootPage);
        corner->setPixmap(QPixmap(EmenuEnv::themeDir + cornerPicList.at(i)));
        corner->setZValue(2);
        corner->setPos(cornerPosList.at(i));
        this->m_cornerList.append(corner);
    }

    QList <QPointF> itemPosList;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        itemPosList << QPointF(190,82) << QPointF(754,82) << QPointF(190,420)  << QPointF(754,420);
        break;
    case EmenuEnv::R_640_480:
    default:
        itemPosList << QPointF(72,54) << QPointF(371,54) << QPointF(72,262) << QPointF(371,262);
        break;
    }
    DiscountItem *item = 0;
    for (int i = 0; i < 4; i++) {
        item = new DiscountItem(this->m_rootPage);
        item->setPos(itemPosList.at(i));
        item->setZValue(1);
        item->setId(i);
        connect(item,SIGNAL(pressed(int)),this,SLOT(selectItem(int)));
        connect(item,SIGNAL(clicked(int)),this,SLOT(itemSelected()));
        this->m_itemList.append(item);
    }

    this->currentItemIndex = 0;
    this->m_itemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Active);
}

void DiscountPage::setupItemAnimations()
{
    QState *smallState = new QState();
    QState *bigState = new QState();

    for (int i = 0; i < this->m_itemList.size(); i++) {
        smallState->assignProperty(this->m_itemList[i],"scale", 0);
        bigState->assignProperty(this->m_itemList[i],"scale",1);
    }

    QSequentialAnimationGroup *showItemGroup = new QSequentialAnimationGroup(this);
    for (int i = 0; i < this->m_itemList.size(); i++) {
        QPropertyAnimation *anim = new QPropertyAnimation(this->m_itemList[i], "scale", this);
        anim->setDuration(300);
        anim->setEasingCurve(QEasingCurve::OutBack);
        showItemGroup->addAnimation(anim);
    }

    QSignalTransition *trans = smallState->addTransition(this, SIGNAL(start()), bigState);
    trans->addAnimation(showItemGroup);
    connect(showItemGroup,SIGNAL(finished()),this,SLOT(startSelect()));

    trans = bigState->addTransition(this,SIGNAL(quitPage()),smallState);
    connect(smallState,SIGNAL(entered()),this,SLOT(closeSelect()));

    QStateMachine *states = new QStateMachine(this);
    states->addState(smallState);
    states->addState(bigState);
    states->setInitialState(smallState);

    states->start();
}

void DiscountPage::setupDetailItems()
{
    this->m_detailPage = new AGraphicsRectObject(this);
    this->m_detailPage->setPos(0,0);
    this->m_detailPage->setZValue(2);

    this->m_detailCorner = new AGraphicsPixmapObject(this->m_detailPage);
    this->m_detailCorner->setPixmap(QPixmap(EmenuEnv::themeDir + "/dis_detailcorner.png"));
    this->m_detailCorner->setZValue(2);

    this->m_dishPicBg = new AGraphicsPixmapObject(this->m_detailPage);
    this->m_dishPicBg->setPixmap(QPixmap(EmenuEnv::themeDir + "/dis_detailbg.png"));
    this->m_detailDishPic = new QGraphicsPixmapItem(this->m_dishPicBg);

    this->m_detailDishName = new QGraphicsTextItem(this->m_detailPage);
    this->m_detailDishName->setDefaultTextColor(EmenuEnv::textHeadingColor);

    this->m_icons = new AGraphicsRectObject(this->m_detailPage);
    this->m_icons->setZValue(1);
    QGraphicsPixmapItem *icon = 0;
    for (int i = 0; i < 9; i++) {
        icon = new QGraphicsPixmapItem(this->m_icons);
        this->m_iconList.append(icon);
    }

    this->m_detailOldPriceItem = new QGraphicsTextItem(this->m_detailPage);
    this->m_detailOldPriceItem->setZValue(1);
    this->m_detailOldPriceItem->setDefaultTextColor(EmenuEnv::textNormalColor);

    QGraphicsPixmapItem *cuttingLine1 = new QGraphicsPixmapItem(this->m_detailPage);
    cuttingLine1->setPixmap(QPixmap(EmenuEnv::themeDir + "/dis_cuttingline.png"));

    this->m_detailPriceItem = new QGraphicsTextItem(this->m_detailPage);
    this->m_detailPriceItem->setDefaultTextColor(EmenuEnv::textHeadingActiveColor_dish);
    this->m_detailPriceItem->setZValue(1);
        
    QGraphicsPixmapItem *cuttingLine2 = new QGraphicsPixmapItem(this->m_detailPage);
    cuttingLine2->setPixmap(QPixmap(EmenuEnv::themeDir + "/dis_cuttingline.png"));

    this->m_detailDishInfoItem = new QGraphicsTextItem(this->m_detailPage);
    this->m_detailDishInfoItem->setDefaultTextColor(EmenuEnv::textHeadingColor);
    this->m_detailDishInfoItem->setZValue(1);

    this->upButton = new AControlButton(EmenuEnv::themeDir + "/control_up.png",EmenuEnv::themeDir + "/control_up_d.png",this->m_detailPage);
    connect(this->upButton,SIGNAL(clicked()),this,SLOT(detailSelectPrevious()));
    this->downButton = new AControlButton(EmenuEnv::themeDir + "/control_down.png",EmenuEnv::themeDir + "/control_down_d.png",this->m_detailPage);
    connect(this->downButton,SIGNAL(clicked()),this,SLOT(detailSelectnext()));
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->upButton->setPos(1210,300);
        this->downButton->setPos(1210,430);
        break;
    case EmenuEnv::R_640_480:
    default:
        break;
    }

    this->m_detailPage->setVisible(false);
    this->isDetailStates = false;

    QFont font;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_detailCorner->setPos(QPointF(102,80));
        this->m_dishPicBg->setPos(125,100);
        this->m_detailDishPic->setPos(28,28);
        this->m_detailDishName->setPos(125,520);
        this->m_detailDishName->setTextWidth(549);
        font.setPointSize(32);
        this->m_detailDishName->setFont(font);
        for (int i = 0; i < this->m_iconList.size(); i++) {
            this->m_iconList.at(i)->setPos(QPoint(120 * i,0));
        }
        this->m_icons->setPos(100,625);
        this->m_detailOldPriceItem->setPos(740,110);
        this->m_detailOldPriceItem->setTextWidth(436);
        font.setPixelSize(30);
        this->m_detailOldPriceItem->setFont(font);
        cuttingLine1->setPos(740,150);
        this->m_detailPriceItem->setPos(740,160);
        this->m_detailPriceItem->setTextWidth(436);
        font.setPixelSize(40);
        this->m_detailPriceItem->setFont(font);
        cuttingLine2->setPos(740,215);
        this->m_detailDishInfoItem->setPos(740,240);
        this->m_detailDishInfoItem->setTextWidth(436);
        font.setPixelSize(26);
        this->m_detailDishInfoItem->setFont(font);
        break;
        
    case EmenuEnv::R_640_480:
    default:
        this->m_detailCorner->setPos(QPointF(15,59));
        this->m_dishPicBg->setPos(25,65);
        this->m_detailDishPic->setPos(15,15);
        this->m_detailDishName->setPos(25,319);
        this->m_detailDishName->setTextWidth(330);
        font.setPointSize(18);
        this->m_detailDishName->setFont(font);
        for (int i = 0; i < this->m_iconList.size(); i++) {
            this->m_iconList.at(i)->setPos(QPoint(70 * i,0));
        }
        this->m_icons->setPos(10,400);
        this->m_detailOldPriceItem->setPos(381,80);
        this->m_detailOldPriceItem->setTextWidth(220);
        font.setPixelSize(18);
        this->m_detailOldPriceItem->setFont(font);
        cuttingLine1->setPos(381,106);
        this->m_detailPriceItem->setPos(381,111);
        this->m_detailPriceItem->setTextWidth(220);
        font.setPixelSize(25);
        this->m_detailPriceItem->setFont(font);
        cuttingLine2->setPos(381,145);
        this->m_detailDishInfoItem->setPos(381,167);
        this->m_detailDishInfoItem->setTextWidth(220);
        font.setPixelSize(18);
        this->m_detailDishInfoItem->setFont(font);
        break;
    }
}

void DiscountPage::setupDetailItemAnimation()
{
//暂时屏蔽效果
//    QState *inState = new QState();
//    QState *outState = new QState();
//    inState->assignProperty(this->dishPicBg,"pos", QPointF(25,65));
//    inState->assignProperty(this->m_detailCorner,"visible",true);
//
//    outState->assignProperty(this->dishPicBg,"pos", QPoint(650,65));
//    outState->assignProperty(this->m_detailCorner,"visible",false);
//    outState->assignProperty(this->m_detailDishName,"visible",false);
//    outState->assignProperty(this->m_icons,"visible",false);
//    outState->assignProperty(this->m_detailPriceItem,"visible",false);
//    outState->assignProperty(this->m_detailOldPriceItem,"visible",false);
//    outState->assignProperty(this->m_detailDishInfoItem,"visible",false);
//
//    QSignalTransition *trans = inState->addTransition(this, SIGNAL(childOut()), outState);
//
//    QPropertyAnimation *anim = new QPropertyAnimation(this->dishPicBg, "pos", this);
//    anim->setDuration(750);
//    anim->setEasingCurve(QEasingCurve::InOutExpo);
//    trans = outState->addTransition(this, SIGNAL(childIn()), inState);
//    trans->addAnimation(anim);
//    connect(anim,SIGNAL(finished()),this,SLOT(showDetail()));
//
//    QStateMachine *states = new QStateMachine(this);
//    states->addState(inState);
//    states->addState(outState);
//    states->setInitialState(outState);
//    states->start();
}

//void DiscountPage::showDetail()
//{
////    this->m_detailCorner->setVisible(true);
//    this->m_detailDishName->setVisible(true);
//    this->m_icons->setVisible(true);
//    this->m_detailPriceItem->setVisible(true);
//    this->m_detailOldPriceItem->setVisible(true);
//    this->m_detailDishInfoItem->setVisible(true);
//}

void DiscountPage::enterDetail()
{
    const DishData *dishData = this->m_discountDataList->at(this->currentItemIndex)->dishData;
    this->m_detailDishPic->setPixmap(EmenuEnv::dishPicDir + "/big/" + dishData->pic);
    this->m_detailDishName->setHtml("<p align = center>" + dishData->name + "</p>");
    this->m_detailOldPriceItem->setHtml("<p align = 'center'> " + tr("原价: ") + this->m_discountDataList->at(this->currentItemIndex)->oldPrice + tr(" 元") + "</p>");
    this->m_detailPriceItem->setHtml("<p align = 'center'> " + tr("促销价: ") + dishData->price + tr(" 元") + "</p>");
    this->m_detailDishInfoItem->setHtml("<p align = 'center'> " + dishData->info + "</p>");
    for (int i = 0; i < this->m_iconList.size(); i++) {
        if (i <= dishData->speciality.toInt()) {
            this->m_iconList.at(i)->setPixmap(QPixmap(EmenuEnv::themeDir + "/icon_" + QString::number(i+1) + ".png"));
        } else {
            this->m_iconList.at(i)->setPixmap(QPixmap(EmenuEnv::themeDir + "/icon_" + QString::number(i+1) + "d.png"));
        }
    }
    this->m_rootPage->setVisible(false);
    this->m_detailPage->setVisible(true);
    this->isDetailStates = true;
}

void DiscountPage::quitDetail()
{
    this->m_detailPage->setVisible(false);
    this->m_rootPage->setVisible(true);
    this->isDetailStates = false;
}

void DiscountPage::detailSelectnext()
{
    this->keyRight_handler();
    this->enterDetail();
}

void DiscountPage::detailSelectPrevious()
{
    this->keyLeft_handler();
    this->enterDetail();
}

void DiscountPage::startSelect()
{
    for (int i = 0; i < this->m_cornerList.size(); i++) {
        this->m_cornerList.at(i)->setVisible(true);
    }
    for (int i = 0; i < this->m_priceItemList.size(); i++) {
        this->m_priceItemList.at(i)->setVisible(true);
    }
    this->m_itemList.at(this->currentItemIndex)->setStatus(DiscountItem::Active);
    this->isSelectable = true;
}

void DiscountPage::closeSelect()
{
    this->isSelectable = false;
    this->m_itemList.at(this->currentItemIndex)->setStatus(DiscountItem::Normal);
    for (int i = 0; i < this->m_priceItemList.size(); i++) {
        this->m_priceItemList.at(i)->setVisible(false);
    }
    for (int i = 0; i < this->m_cornerList.size(); i++) {
        this->m_cornerList.at(i)->setVisible(false);
    }
}

void DiscountPage::selectItem(int index)
{
    if (this->isSelectable == false) return;
    if (index >= 0 && index < this->m_itemList.size()) {
        this->m_itemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Normal);
        this->currentItemIndex = index;
        this->m_itemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Active);
    }
}

void DiscountPage::itemSelected()
{
    if (this->isSelectable == false) return;
    this->enterDetail();
}

void DiscountPage::keyEscape_handler()
{
    if (this->isDetailStates == true) {
        this->quitDetail();
    } else {
        this->hidePage();
    }
}

void DiscountPage::keyReturn_handler()
{
    this->itemSelected();
}

void DiscountPage::keyUp_handler()
{
    int index = this->currentItemIndex - 2;
    if (index < 0) {
        index += this->m_itemList.size();
    }
    this->selectItem(index);
}

void DiscountPage::keyDown_handler()
{
    int index = this->currentItemIndex + 2;
    if (index >= this->m_itemList.size()) {
        index -= this->m_itemList.size();
    }
    this->selectItem(index);
}

void DiscountPage::keyLeft_handler()
{
    int index = this->currentItemIndex - 1;
    if (index < 0) {
        index += this->m_itemList.size();
    }
    this->selectItem(index);
}

void DiscountPage::keyRight_handler()
{
    int index = this->currentItemIndex + 1;
    if (index >= this->m_itemList.size()) {
        index = 0;
    }
    this->selectItem(index);
}

void DiscountPage::resetPage()
{
    this->currentItemIndex = 0;
}

