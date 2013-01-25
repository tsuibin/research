#include <QFont>
#include <QDebug>

#include "storyselectitem.h"
#include "emenuenv.h"

StorySelectItem::StorySelectItem(QGraphicsItem *parent) :
        AGraphicsSelectItem(parent)
{
    this->m_background = new QGraphicsPixmapItem(this);
    this->m_background->setPos(0,0);
    this->m_background->setZValue(0);
    this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/sto_itembg.png"));

    QFont font;
    this->m_text = new QGraphicsTextItem(this);
    this->m_text->setDefaultTextColor(EmenuEnv::textHeadingColor);
    this->m_text->setTextWidth(this->m_background->pixmap().width());
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        font.setPixelSize(26);
        this->m_text->setFont(font);
        this->m_text->setPos(0,30);
        break;
    case EmenuEnv::R_640_480:
    default:
        font.setPixelSize(16);
        this->m_text->setFont(font);
        this->m_text->setPos(0,16);
        break;
    }

    this->setRect(this->m_background->boundingRect());
}

StorySelectItem::~StorySelectItem()
{
}

void StorySelectItem::setData(int id,const QString &text)
{
    this->setId(id);
    this->m_text->setHtml("<p align = 'center'>" + text + "</p>");
}

void StorySelectItem::updateStatus()
{
    switch (this->m_currentStatus) {
    case AGraphicsSelectItem::Active:
        this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/sto_itembg_active.png"));
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingActiveColor);
        break;

    default:
        this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/sto_itembg.png"));
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingColor);
        break;
    }
}
