#include <QFont>

#include "healthitem.h"
#include "emenuenv.h"

HealthItem::HealthItem(QGraphicsItem *parent) :
        AGraphicsSelectItem(parent)
{    
    this->m_background = new QGraphicsPixmapItem(this);
    this->m_background->setPos(0,0);
    this->m_background->setZValue(0);
    this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/hea_itembg.png"));

    this->m_pic = new QGraphicsPixmapItem(this->m_background);
    this->m_pic->setPos(18,13.5);

    QFont font;
    this->m_name = new QGraphicsTextItem(this->m_background);
    this->m_name->setDefaultTextColor(EmenuEnv::textHeadingColor);
    font.setPixelSize(18);
    this->m_name->setFont(font);
    this->m_name->setPos(120,15);
    this->m_name->setTextWidth(225);

    this->m_info = new QGraphicsTextItem(this->m_background);
    this->m_info->setDefaultTextColor(EmenuEnv::textDetailColor);
    font.setPixelSize(12);
    this->m_info->setPos(393,31);
    this->m_info->setDefaultTextColor(EmenuEnv::textDetailColor);
    this->m_info->setTextWidth(190);

    QGraphicsPixmapItem *item = 0;
    QPixmap starPixmap(EmenuEnv::themeDir + "/hea_levelstar_s.png");
    for (int i = 0; i < 5; i++) {
        item = new QGraphicsPixmapItem(starPixmap,this->m_background);
        item->setPos(200 + 20 * i,45);
//        item->setVisible(false);
        this->m_stars.append(item);
    }

    this->setRect(this->m_background->boundingRect());
}

HealthItem::~HealthItem()
{
}

void HealthItem::setData(const QString &pic, const QString &name, const QString &price, const int &level, const QString &info)
{
    this->m_pic->setPixmap(pic);
    this->m_name->setHtml("<p>" + name + "/" + price + "</p>");
    for (int i = 0; i < this->m_stars.size(); i++) {
        if (i < level) {
            this->m_stars.at(i)->setVisible(true);
        } else {
            this->m_stars.at(i)->setVisible(false);
        }
    }
    this->m_info->setHtml("<p>" + info + "</p>");
}

void HealthItem::updateStatus()
{
    switch (this->m_currentStatus) {
    case AGraphicsSelectItem::Active:
        this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/hea_itembg_active.png"));
        this->m_name->setDefaultTextColor(EmenuEnv::textHeadingActiveColor);
        break;

    default:
        this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/hea_itembg.png"));
        this->m_name->setDefaultTextColor(EmenuEnv::textHeadingColor);
        break;
    }
}
