#include <QFont>

#include "discountitem.h"
#include "emenuenv.h"

DiscountItem::DiscountItem(QGraphicsItem *parent) :
        AGraphicsSelectItem(parent)
{
    this->m_background = new QGraphicsPixmapItem(this);
    this->m_background->setPos(0,0);
    this->m_background->setZValue(0);
    this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/dis_itembg.png"));

    this->m_pic = new QGraphicsPixmapItem(this);
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_pic->setPos(34,34.5);
        break;
    case EmenuEnv::R_640_480:
    default:
        this->m_pic->setPos(22,22);
        break;
    }
    this->m_pic->setZValue(1);

    QFont font;
    this->m_text = new QGraphicsTextItem(this);
    this->m_text->setDefaultTextColor(EmenuEnv::textHeadingColor);
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        font.setPixelSize(29);
        this->m_text->setPos(0,270);
        break;
    case EmenuEnv::R_640_480:
    default:
        font.setPixelSize(16);
        this->m_text->setPos(0,170);
        break;
    }
    this->m_text->setFont(font);
    this->m_text->setTextWidth(this->m_background->pixmap().width());

    this->setRect(this->m_background->pixmap().rect());
}

DiscountItem::~DiscountItem()
{
}

void DiscountItem::setData(const QString &picPath, const QString &dishName, const QString &price)
{
    this->m_pic->setPixmap(QPixmap(EmenuEnv::dishPicDir + "/middle/" + picPath));
    this->m_text->setHtml("<p align = 'center'>" + dishName + tr(" (原价:") + price + ")</p>");
}

void DiscountItem::updateStatus()
{
    switch (this->m_currentStatus) {
    case AGraphicsSelectItem::Active:
        this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/dis_itembg_active.png"));
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingActiveColor_dish);
        break;

    default:
        this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/dis_itembg.png"));
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingColor);
        break;
    }
}
