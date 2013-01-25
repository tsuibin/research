#include <QGraphicsWidget>
#include <QKeyEvent>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QSignalTransition>
#include <QStateMachine>
#include <QTimer>
#include <QPen>
#include <QDebug>

#include "recommendationpage.h"
#include "acontrolbutton.h"
#include "agraphicspixmapobject.h"
#include "recommendationitem.h"
#include "emenuenv.h"
#include "dishdata.h"

RecommendationPage::RecommendationPage(QGraphicsItem *parent) :
        AAnimationPage(parent), m_recommendationDataList(0)
{
    this->setupUI();
}

void RecommendationPage::setupUI()
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

void RecommendationPage::setupRootItems()
{
    this->m_rootPage = new AGraphicsRectObject(this);
    this->m_rootPage->setPos(0,0);

    const int columnCount = 3;
    const int rowCount = 2;
    const int itemCount = columnCount * rowCount;
    this->m_recommendationItems = new AGraphicsRectObject(this->m_rootPage);
    RecommendationItem *item = 0;
    for (int i = 0; i < itemCount; i++) {
        item = new RecommendationItem(this->m_recommendationItems);
        item->setZValue(1);
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
        item->setId(i);
        connect(item,SIGNAL(pressed(int)),this,SLOT(selectItem(int)));
        connect(item,SIGNAL(clicked(int)),this,SLOT(itemSelected()));
        this->m_recommendationItemList.append(item);
    }

    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_recommendationItems->setPos(80,100);
        break;
    case EmenuEnv::R_640_480:
    default:
        this->m_recommendationItems->setPos(23,56);
        break;
    }

    this->currentItemIndex = 0;
    this->m_recommendationItemList.at(0)->setStatus(AGraphicsSelectItem::Active);
    this->isSelectable = true;
}

void RecommendationPage::setupDetailItems()
{
    this->m_detailPage = new AGraphicsRectObject(this);
    this->m_detailPage->setPos(0,0);

    QGraphicsPixmapItem *picBg = new QGraphicsPixmapItem(this->m_detailPage);
    picBg->setPixmap(QPixmap(EmenuEnv::themeDir + "/dis_detailbg.png"));
    this->m_dishPic = new QGraphicsPixmapItem(picBg);

    this->m_dishName = new QGraphicsTextItem(this->m_detailPage);
    this->m_dishName->setDefaultTextColor(EmenuEnv::textHeadingColor);

    QGraphicsPixmapItem *infoBg = new QGraphicsPixmapItem(QPixmap(EmenuEnv::themeDir + "/ran_dishinfobg.png"),this->m_detailPage);
    this->m_dishInfo = new QGraphicsTextItem(infoBg);
    this->m_dishInfo->setDefaultTextColor(EmenuEnv::textDetailColor);

    QGraphicsPixmapItem *recBg = new QGraphicsPixmapItem(QPixmap(EmenuEnv::themeDir + "/rec_recbg.png"),this->m_detailPage);
    this->m_dishRec = new QGraphicsTextItem(recBg);
    this->m_dishRec->setDefaultTextColor(EmenuEnv::textDetailColor);

    this->m_icons = new AGraphicsRectObject(this->m_detailPage);
    QGraphicsPixmapItem *icon = 0;
    for (int i = 0; i < 9; i++) {
        icon = new QGraphicsPixmapItem(this->m_icons);
        icon->setPos(QPoint((i % 3) * 70, i / 3 * 70));
        icon->setZValue(1);
        this->m_iconList.append(icon);
    }
    this->m_icons->setPos(380,70);

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

    QGraphicsPixmapItem *customerBg = new QGraphicsPixmapItem(QPixmap(EmenuEnv::themeDir + "/rec_customerbg.png"),this->m_detailPage);
    QGraphicsPixmapItem *recIcon = new QGraphicsPixmapItem(QPixmap(EmenuEnv::themeDir + "/rec_signet_detail.png"),this->m_detailPage);

    QFont font;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        picBg->setPos(80,70);
        this->m_dishPic->setPos(28,28);
        this->m_dishName->setPos(80,490);
        this->m_dishName->setTextWidth(549);
        font.setPointSize(32);
        this->m_dishName->setFont(font);
        infoBg->setPos(650,360);
        this->m_dishInfo->setPos(25,50);
        this->m_dishInfo->setTextWidth(520);
        font.setPointSize(15);
        this->m_dishInfo->setFont(font);
        recBg->setPos(85,570);
        this->m_dishRec->setFont(font);
        this->m_dishRec->setPos(25,50);
        this->m_dishRec->setTextWidth(520);
        font.setPointSize(15);
        this->m_dishRec->setFont(font);
        for (int i = 0; i < this->m_iconList.size(); i++) {
            this->m_iconList.at(i)->setPos(QPoint((i % 5) * 110, i / 5 * 120));
        }
        this->m_icons->setPos(650,100);
        recIcon->setPos(550,30);
        customerBg->setPos(650,565);
        break;
    case EmenuEnv::R_640_480:
    default:
        picBg->setPos(25,60);
        this->m_dishPic->setPos(15,15);
        this->m_dishName->setPos(25,314);
        this->m_dishName->setTextWidth(330);
        font.setPointSize(18);
        this->m_dishName->setFont(font);
        for (int i = 0; i < this->m_iconList.size(); i++) {
            this->m_iconList.at(i)->setPos(QPoint((i % 3) * 70, i / 3 * 70));
        }
        this->m_icons->setPos(380,70);
        break;
    }

    this->m_detailPage->setVisible(false);
    this->isDetailStates = false;
}

void RecommendationPage::setupItemAnimations()
{

}

void RecommendationPage::setupDetailItemAnimation()
{

}

void RecommendationPage::setData(const QList <const RecommendationData *> * recommendationDataList)
{
    this->m_recommendationDataList = recommendationDataList;

    for (int i = 0; i < this->m_recommendationItemList.size(); i++) {
        if (i < this->m_recommendationDataList->size()) {
            this->m_recommendationItemList.at(i)->setId(i);
            const DishData *dishData = this->m_recommendationDataList->at(i)->dishData;
            this->m_recommendationItemList.at(i)->setData(dishData->pic,dishData->name);
        } else {
            this->m_recommendationItemList.at(i)->setId(-1);
            this->m_recommendationItemList.at(i)->setData(QString(),QString());
        }
    }

}

void RecommendationPage::enterDetail()
{
    const DishData *dishData = this->m_recommendationDataList->at(this->currentItemIndex)->dishData;
    this->m_dishPic->setPixmap(EmenuEnv::dishPicDir + "/big/"+ dishData->pic);
    this->m_dishName->setHtml("<p align = 'center'><font color=\"" +
                              EmenuEnv::textHeadingColor.name() +"\"> "+
                              dishData->name +" / <font color=\"" +
                              EmenuEnv::textHeadingActiveColor_dish.name() + "\"> "
                              + tr("￥")+ dishData->price + "</p>");
    this->m_dishInfo->setPlainText(dishData->info);
    this->m_dishRec->setPlainText(this->m_recommendationDataList->at(this->currentItemIndex)->recommendation);
    for (int i = 0; i < this->m_iconList.size(); i++) {
        if (i <= dishData->speciality.toInt()) {
            this->m_iconList.at(i)->setPixmap(QPixmap(EmenuEnv::themeDir + "/icon_" + QString::number(i+1) + ".png"));
        } else {
            this->m_iconList.at(i)->setPixmap(QPixmap(EmenuEnv::themeDir + "/icon_" + QString::number(i+1) + "d.png"));
        }
    }
    this->m_detailPage->setVisible(true);
    this->m_rootPage->setVisible(false);
    this->isDetailStates = true;
}

void RecommendationPage::quitDetail()
{
    this->m_detailPage->setVisible(false);
    this->m_rootPage->setVisible(true);
    this->isDetailStates = false;
}

void RecommendationPage::detailSelectnext()
{
    this->keyRight_handler();
    this->enterDetail();
}

void RecommendationPage::detailSelectPrevious()
{
    this->keyLeft_handler();
    this->enterDetail();
}

void RecommendationPage::selectItem(int index)
{
    if (this->isSelectable == false) return;
    if (index >= 0 && index < this->m_recommendationItemList.size()) {
        this->m_recommendationItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Normal);
        this->currentItemIndex = index;
        this->m_recommendationItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Active);
    }
}

void RecommendationPage::itemSelected()
{
    if (this->isSelectable == false) return;
    this->enterDetail();
}

void RecommendationPage::keyEscape_handler()
{
    if (this->isDetailStates == true) {
        this->quitDetail();
    } else {
        this->hidePage();
    }
}

void RecommendationPage::keyReturn_handler()
{
    this->itemSelected();
}

void RecommendationPage::keyUp_handler()
{
    int index = this->currentItemIndex - 3;
    if (index < 0) {
        index += this->m_recommendationItemList.size();
    }
    this->selectItem(index);
}

void RecommendationPage::keyDown_handler()
{
    int index = this->currentItemIndex + 3;
    if (index >= this->m_recommendationItemList.size()) {
        index -= this->m_recommendationItemList.size();
    }
    this->selectItem(index);
}

void RecommendationPage::keyLeft_handler()
{
    int index = this->currentItemIndex - 1;
    if (index < 0) {
        index += this->m_recommendationItemList.size();
    }
    this->selectItem(index);
}

void RecommendationPage::keyRight_handler()
{
    int index = this->currentItemIndex + 1;
    if (index >= this->m_recommendationItemList.size()) {
        index = 0;
    }
    this->selectItem(index);
}

void RecommendationPage::resetPage()
{
    if (this->currentItemIndex != 0) {
        this->selectItem(0);
    }
}
