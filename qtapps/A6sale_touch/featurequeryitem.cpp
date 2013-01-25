#include <QFont>

#include "emenuenv.h"
#include "featurequeryitem.h"

FeatureQueryItem::FeatureQueryItem(QGraphicsItem *parent) :
        AGraphicsSelectItem(parent)
{
    this->m_background = new QGraphicsPixmapItem(this);
    this->m_background->setPos(0,0);
    this->m_background->setZValue(0);
    this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/sea_item.png"));

    this->m_text = new QGraphicsTextItem(this->m_background);
    this->m_text->setDefaultTextColor(EmenuEnv::textHeadingColor);
    this->m_text->setTextWidth(this->m_background->boundingRect().width());

    QFont font;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        font.setPixelSize(40);
        this->m_text->setFont(font);
        this->m_text->setPos(0,40);
        break;
    case EmenuEnv::R_640_480:
    default:
        font.setPixelSize(20);
        this->m_text->setFont(font);
        this->m_text->setPos(0,0);
        break;
    }

    this->setRect(this->m_background->boundingRect());
}

FeatureQueryItem::~FeatureQueryItem()
{
}

void FeatureQueryItem::setData(const QString &text)
{
    this->m_text->setHtml("<p align = 'center'>" + text + "</p>");
}

void FeatureQueryItem::updateStatus()
{
    switch (this->m_currentStatus) {
    case AGraphicsSelectItem::Active:
        this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/sea_item_active.png"));
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingActiveColor);
        break;

    default:
        this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/sea_item.png"));
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingColor);
        break;
    }
}
