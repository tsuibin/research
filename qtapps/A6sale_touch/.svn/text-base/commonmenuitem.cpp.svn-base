#include <QFont>

#include "commonmenuitem.h"
#include "emenuenv.h"

CommonMenuItem::CommonMenuItem(QGraphicsItem *parent) :
        AGraphicsSelectItem(parent)
{
    this->m_background = new QGraphicsPixmapItem(this);
    this->m_background->setPos(0,0);
    this->m_background->setZValue(0);
    this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/eme_itembg.png"));

    this->m_pic = new QGraphicsPixmapItem(this->m_background);
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
    this->m_text->setTextWidth(this->m_background->pixmap().width());
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
        font.setPixelSize(18);
        this->m_text->setFont(font);
        break;
    }

    this->setRect(this->m_background->boundingRect());
}

CommonMenuItem::~CommonMenuItem()
{
}

void CommonMenuItem::setData(const QString &pic,const QString &name, const QString &price)
{
    this->m_pic->setPixmap(QPixmap(EmenuEnv::dishPicDir + "/middle/" + pic));
    this->m_text->setHtml("<p align = 'center'>" + name + "<br>" + tr("￥") + price + "</p>");
}

void CommonMenuItem::updateStatus()
{
    switch (this->m_currentStatus) {
    case AGraphicsSelectItem::Active:
        this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/eme_itembg_active.png"));
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingActiveColor_dish);
        break;

    default:
        this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/eme_itembg.png"));
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingColor);
        break;
    }
}
