#include <QFont>

#include "commondetail.h"
#include "emenuenv.h"
#include "dishdata.h"

CommonDetail::CommonDetail(QGraphicsItem *parent) :
        AGraphicsRectObject(parent)
{
    this->initDetailDish();
    this->initDetailInfo();
    this->initDetailIcons();
}

CommonDetail::~CommonDetail()
{
}

void CommonDetail::setData(const DishData *dishData)
{
    this->m_dishPic->setPixmap(EmenuEnv::dishPicDir + "/big/"+ dishData->pic);
    this->m_dishName->setHtml("<p align = 'center'><font color=\"" +
                              EmenuEnv::textHeadingColor.name() +"\"> "+
                              dishData->name +" / <font color=\"" +
                              EmenuEnv::textHeadingActiveColor_dish.name() + "\"> "
                              + tr("￥")+ dishData->price + "</p>");
    this->m_dishInfo->setHtml("<p align = 'center'> " + dishData->info + "</p>");

    for (int i = 0; i < this->m_iconList.size(); i++) {
        if (i <= dishData->speciality.toInt()) {
            this->m_iconList.at(i)->setPixmap(QPixmap(EmenuEnv::themeDir + "/icon_" + QString::number(i+1) + ".png"));
        } else {
            this->m_iconList.at(i)->setPixmap(QPixmap(EmenuEnv::themeDir + "/icon_" + QString::number(i+1) + "d.png"));
        }
    }
}

void CommonDetail::initDetailDish()
{
    this->m_detailDish = new AGraphicsRectObject(this);

    QGraphicsPixmapItem *dishPicBg = new QGraphicsPixmapItem(this->m_detailDish);
    dishPicBg->setPixmap(QPixmap(EmenuEnv::themeDir + "/dis_detailbg.png"));
    dishPicBg->setPos(0,0);

    this->m_dishPic = new QGraphicsPixmapItem(dishPicBg);

    this->m_dishName = new QGraphicsTextItem(this->m_detailDish);
    this->m_dishName->setDefaultTextColor(EmenuEnv::textHeadingColor);

    QFont font;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_detailDish->setPos(129,82);
        this->m_dishPic->setPos(28,28);
        this->m_dishName->setPos(0,420);
        this->m_dishName->setTextWidth(549);
        font.setPointSize(32);
        this->m_dishName->setFont(font);
        break;

    case EmenuEnv::R_640_480:
    default:
        this->m_detailDish->setPos(25,65);
        this->m_dishPic->setPos(15,15);
        this->m_dishName->setPos(0,254);
        this->m_dishName->setTextWidth(330);
        font.setPointSize(18);
        this->m_dishName->setFont(font);
        break;
    }
}

void CommonDetail::initDetailInfo()
{
    this->m_detailInfo = new AGraphicsRectObject(this);

    QGraphicsPixmapItem *cuttingLine1 = new QGraphicsPixmapItem(this->m_detailInfo);
    cuttingLine1->setPixmap(QPixmap(EmenuEnv::themeDir + "/dis_cuttingline.png"));
    cuttingLine1->setPos(0,0);

    QGraphicsTextItem *dishInfoTip = new QGraphicsTextItem(this->m_detailInfo);
    dishInfoTip->setDefaultTextColor(EmenuEnv::textHeadingActiveColor_dish);
    dishInfoTip->setHtml("<p align = 'center'> " + tr("菜品介绍 :") + "</p>");

    QGraphicsPixmapItem *cuttingLine2 = new QGraphicsPixmapItem(this->m_detailInfo);
    cuttingLine2->setPixmap(QPixmap(EmenuEnv::themeDir + "/dis_cuttingline.png"));

    this->m_dishInfo = new QGraphicsTextItem(this->m_detailInfo);
    this->m_dishInfo->setDefaultTextColor(EmenuEnv::textHeadingColor);

    QFont font;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_detailInfo->setPos(700,130);
        dishInfoTip->setPos(0,6);
        dishInfoTip->setTextWidth(436);
        font.setPointSize(38);
        dishInfoTip->setFont(font);
        cuttingLine2->setPos(0,70);
        this->m_dishInfo->setPos(0,110);
        font.setPointSize(24);
        this->m_dishInfo->setFont(font);
        this->m_dishInfo->setTextWidth(436);
        break;

    case EmenuEnv::R_640_480:
    default:
        this->m_detailInfo->setPos(380,100);
        dishInfoTip->setPos(0,6);
        dishInfoTip->setTextWidth(220);
        font.setPointSize(18);
        dishInfoTip->setFont(font);
        cuttingLine2->setPos(0,40);
        break;
    }
}

void CommonDetail::initDetailIcons()
{
    this->m_icons = new AGraphicsRectObject(this);
    QGraphicsPixmapItem *icon = 0;
    for (int i = 0; i < 9; i++) {
        icon = new QGraphicsPixmapItem(this->m_icons);
        icon->setZValue(1);
        this->m_iconList.append(icon);
    }

    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        for (int i = 0; i < this->m_iconList.size(); i++) {
            this->m_iconList.at(i)->setPos(QPoint(120 * i,0));
        }
        this->m_icons->setPos(100,625);
        break;

    case EmenuEnv::R_640_480:
    default:
        for (int i = 0; i < 9; i++) {
            this->m_iconList.at(i)->setPos(QPoint(70 * i,0));
        }
        this->m_icons->setPos(10,400);
        break;
    }
}
