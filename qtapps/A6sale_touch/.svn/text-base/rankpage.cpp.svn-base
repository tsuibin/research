#include <QFont>
#include <QKeyEvent>
#include <QDebug>

#include "rankpage.h"
#include "rankitem.h"
#include "dishdata.h"
#include "emenuenv.h"
#include "acontrolbutton.h"
#include "agraphicspixmapobject.h"

RankPage::RankPage(QGraphicsItem *parent) :
        AAnimationPage(parent), m_rankDataList(0)

{
    this->setupUI();
}

RankPage::~RankPage()
{

}

void RankPage::setupUI()
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

void RankPage::setData(const QList<const RankData *> *rankDataList)
{
    this->m_rankDataList = rankDataList;
    for (int i = 0; i < this->m_rankItemList.size(); i++) {
        if (i < this->m_rankDataList->size()) {
            const DishData *dishData = this->m_rankDataList->at(i)->dishData;
            this->m_rankItemList.at(i)->setData(dishData->name,this->m_rankDataList->at(i)->isUp);
        }
    }
}

void RankPage::enterDetail()
{
    const DishData *dishData = this->m_rankDataList->at(this->currentItemIndex)->dishData;
    this->m_dishPic->setPixmap(EmenuEnv::dishPicDir + "/big/"+ dishData->pic);
    this->m_dishName->setHtml("<p align = 'center'><font color=\"" +
                              EmenuEnv::textHeadingColor.name() +"\"> "+
                              dishData->name +" / <font color=\"" +
                              EmenuEnv::textHeadingActiveColor_dish.name() + "\"> "
                              + tr("￥")+ dishData->price + "</p>");
    this->m_dishRankNo->setHtml("<p align = 'center'> " + QString::number(this->currentItemIndex + 1) + "</p>");
    if (this->m_rankDataList->at(this->currentItemIndex)->isUp == false) {
        this->m_dishUp->setPixmap(QPixmap(EmenuEnv::themeDir + "/ran_down.png"));
    } else {
        this->m_dishUp->setPixmap(QPixmap(EmenuEnv::themeDir + "/ran_up.png"));
    }
    this->m_dishInfo->setPlainText(dishData->info);
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

void RankPage::quitDetail()
{
    this->m_detailPage->setVisible(false);
    this->m_rootPage->setVisible(true);
    this->isDetailStates = false;
}

void RankPage::setupRootItems()
{
    this->m_rootPage = new AGraphicsRectObject(this);
    this->m_rootPage->setPos(0,0);

    const int columnCount = 2;
    const int rowCount = 5;
    const int itemCount = columnCount * rowCount;
    this->m_rankItems = new AGraphicsRectObject(this->m_rootPage);
    RankItem *item = 0;
    for (int i = 0; i < itemCount; i++) {
        item = new RankItem(i + 1, this->m_rankItems);
        item->setZValue(1);
        switch (EmenuEnv::currentResolution) {
        case EmenuEnv::R_1280_768:
            item->setPos(QPointF((i / rowCount) * 600, (i % rowCount) * 120 ));
            break;
        case EmenuEnv::R_640_480:
        default:
            item->setPos(QPointF((i / rowCount) * 310, (i % rowCount) * 75 ));
            break;
        }
        item->setId(i);
        connect(item,SIGNAL(pressed(int)),this,SLOT(selectItem(int)));
        connect(item,SIGNAL(clicked(int)),this,SLOT(itemSelected()));
        this->m_rankItemList.append(item);
    }

    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_rankItems->setPos(70,70);
        break;
    case EmenuEnv::R_640_480:
    default:
        this->m_rankItems->setPos(98,108);
        break;
    }

    this->m_rankItemList.at(0)->setStatus(AGraphicsSelectItem::Active);
    this->currentItemIndex = 0;
    this->isSelectable = true;
}

void RankPage::setupDetailItems()
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

    QGraphicsPixmapItem *iconBg = new QGraphicsPixmapItem(QPixmap(EmenuEnv::themeDir + "/ran_iconbg.png"),this->m_detailPage);
    this->m_dishRankNo = new QGraphicsTextItem(iconBg);
    this->m_dishRankNo->setDefaultTextColor(EmenuEnv::textHeadingActiveColor_dish);
    this->m_dishUp = new QGraphicsPixmapItem(iconBg);

    this->m_icons = new AGraphicsRectObject(this->m_detailPage);
    QGraphicsPixmapItem *icon = 0;
    for (int i = 0; i < 9; i++) {
        icon = new QGraphicsPixmapItem(this->m_icons);
        icon->setPos(QPoint((i % 3) * 70, i / 3 * 70));
        icon->setZValue(1);
        this->m_iconList.append(icon);
    }

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

    QGraphicsPixmapItem *customerBg1 = new QGraphicsPixmapItem(QPixmap(EmenuEnv::themeDir + "/ran_customerbg1.png"),this->m_detailPage);
    QGraphicsPixmapItem *customerBg2 = new QGraphicsPixmapItem(QPixmap(EmenuEnv::themeDir + "/ran_customerbg2.png"),this->m_detailPage);

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
        iconBg->setPos(540,30);
        this->m_dishRankNo->setPos(0,3);
        font.setPointSize(35);
        this->m_dishRankNo->setFont(font);
        this->m_dishRankNo->setTextWidth(80);
        this->m_dishUp->setPos(40,77);
        for (int i = 0; i < this->m_iconList.size(); i++) {
            this->m_iconList.at(i)->setPos(QPoint((i % 5) * 110, i / 5 * 120));
        }
        this->m_icons->setPos(650,100);
        customerBg1->setPos(650,565);
        customerBg2->setPos(85,570);
        break;
    case EmenuEnv::R_640_480:
    default:
        picBg->setPos(25,60);
        this->m_dishPic->setPos(15,15);
        this->m_dishName->setPos(25,314);
        this->m_dishName->setTextWidth(330);
        font.setPointSize(18);
        this->m_dishName->setFont(font);
        for (int i = 0; i < 9; i++) {
            this->m_iconList.at(i)->setPos(QPoint((i % 3) * 70, i / 3 * 70));
        }
        this->m_icons->setPos(380,70);
        break;
    }

    this->m_detailPage->setVisible(false);
    this->isDetailStates = false;
}

void RankPage::setupItemAnimations()
{

}

void RankPage::setupDetailItemAnimation()
{

}

void RankPage::detailSelectnext()
{
    this->keyDown_handler();
    this->enterDetail();
}

void RankPage::detailSelectPrevious()
{
    this->keyUp_handler();
    this->enterDetail();
}

void RankPage::selectItem(int index)
{
    if (this->isSelectable == false) return;
    if (index >= 0 && index < this->m_rankItemList.size()) {
        this->m_rankItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Normal);
        this->currentItemIndex = index;
        this->m_rankItemList.at(this->currentItemIndex)->setStatus(AGraphicsSelectItem::Active);
    }
}

void RankPage::itemSelected()
{
    if (this->isSelectable == false) return;
    this->enterDetail();
}

void RankPage::keyEscape_handler()
{
    if (this->isDetailStates == true) {
        this->quitDetail();
    } else {
        this->hidePage();
    }
}

void RankPage::keyReturn_handler()
{
    this->itemSelected();
}

void RankPage::keyUp_handler()
{    
    int index = this->currentItemIndex - 1;
    if (index < 0) {
        index += this->m_rankItemList.size();
    }
    this->selectItem(index);
}

void RankPage::keyDown_handler()
{   
    int index = this->currentItemIndex + 1;
    if (index >= this->m_rankItemList.size()) {
        index = 0;
    }
    this->selectItem(index);
}

void RankPage::keyLeft_handler()
{
    int index = this->currentItemIndex - 5;
    if (index < 0) {
        index += this->m_rankItemList.size();
    }
    this->selectItem(index);
}

void RankPage::keyRight_handler()
{
    int index = this->currentItemIndex + 5;
    if (index >= this->m_rankItemList.size()) {
        index -= this->m_rankItemList.size();
    }
    this->selectItem(index);
}

void RankPage::resetPage()
{
    if (this->currentItemIndex != 0) {
        this->selectItem(0);
    }
}
