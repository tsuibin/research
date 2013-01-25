#include <QFont>

#include "recommendationitem.h"
#include "emenuenv.h"

RecommendationItem::RecommendationItem(QGraphicsItem *parent) :
        AGraphicsSelectItem(parent)

{
    this->m_picBg = new QGraphicsPixmapItem(QPixmap(EmenuEnv::themeDir + "/rec_itembg.png"),this);
    this->m_picBg->setPos(0,0);
    this->m_pic = new QGraphicsPixmapItem(this->m_picBg);
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_pic->setPos(39,39);
        this->m_pic->setScale(263.0/ 302.0);
        break;
    case EmenuEnv::R_640_480:
    default:
        this->m_pic->setPos(22,21);
        this->m_pic->setScale(150.0 / 190.0);
        break;
    }

    this->m_text = new QGraphicsTextItem(this);
    this->m_text->setDefaultTextColor(EmenuEnv::textHeadingColor);
    QFont font;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_text->setPos(20,250);
        this->m_text->setTextWidth(300);
        font.setPixelSize(25);
        this->m_text->setFont(font);
        break;
    case EmenuEnv::R_640_480:
    default:
        this->m_text->setPos(0,145);
        this->m_text->setTextWidth(194);
        font.setPixelSize(18);
        this->m_text->setFont(font);
        break;
    }

    this->m_recommendationIcon = new QGraphicsPixmapItem(QPixmap(EmenuEnv::themeDir + "/rec_signet.png"),this);
    this->m_recommendationIcon->setZValue(1);
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_recommendationIcon->setPos(260, -5);
        break;
    case EmenuEnv::R_640_480:
    default:
        this->m_recommendationIcon->setPos(140, -5);
        break;
    }
    this->setRect(this->m_picBg->boundingRect());
}

RecommendationItem::~RecommendationItem()
{
}

void RecommendationItem::setData(const QString &pic,const QString &text)
{
    this->m_pic->setPixmap(QPixmap(EmenuEnv::dishPicDir + "/middle/" + pic));
    this->m_text->setHtml("<p align = 'center'>" + text + "</p>");
}

void RecommendationItem::updateStatus()
{
    switch (this->m_currentStatus) {
    case AGraphicsSelectItem::Active:
        this->m_picBg->setPixmap(QPixmap(EmenuEnv::themeDir + "/rec_itembg_active.png"));
        this->m_recommendationIcon->setPixmap(QPixmap(EmenuEnv::themeDir + "/rec_signet_active.png"));
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingActiveColor_dish);
        break;

    default:
        this->m_picBg->setPixmap(QPixmap(EmenuEnv::themeDir + "/rec_itembg.png"));
        this->m_recommendationIcon->setPixmap(QPixmap(EmenuEnv::themeDir + "/rec_signet.png"));
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingColor);
        break;
    }
}
