#include <QStyleOptionGraphicsItem>
#include <QPainter>

#include "storytextitem.h"
#include "emenuenv.h"

StoryTextItem::StoryTextItem(QGraphicsItem *parent) :
        AGraphicsRectObject(parent)
{
    this->m_titleIconLeft = new QGraphicsPixmapItem(QPixmap(EmenuEnv::themeDir + "/sto_title_left.png"),this);
    this->m_titleIconRight = new QGraphicsPixmapItem(QPixmap(EmenuEnv::themeDir + "/sto_title_right.png"),this);

    this->m_title = new QGraphicsTextItem(this);
    this->m_title->setDefaultTextColor(EmenuEnv::textHeadingColor);
    this->m_title->setHtml("<p align = 'center'> " + tr("菜品故事") + "</p>");

    this->m_pic = new QGraphicsPixmapItem(this);
    this->m_pic->setZValue(1);

    this->m_text = new QGraphicsTextItem(this);
    this->m_text->setDefaultTextColor(EmenuEnv::textNormalColor);

    QFont font;
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_titleIconLeft->setPos(76,90);
        this->m_titleIconRight->setPos(494,90);
        this->m_title->setPos(169,55);
        this->m_title->setTextWidth(325);
        font.setPixelSize(50);
        this->m_title->setFont(font);
        this->m_pic->setPos(106,166);
        this->m_text->setPos(90,150);
        this->m_text->setTextWidth(486);
        font.setPixelSize(20);
        this->m_text->setFont(font);
        break;

    case EmenuEnv::R_640_480:
        this->m_titleIconLeft->setPos(62,43);
        this->m_titleIconRight->setPos(242,43);
        this->m_title->setPos(120,20);
        this->m_title->setTextWidth(122);
        font.setPixelSize(28);
        this->m_title->setFont(font);
        this->m_pic->setPos(39,83);
        this->m_text->setPos(29,72);
        this->m_text->setTextWidth(300);
        font.setPixelSize(12);
        this->m_text->setFont(font);
    default:
        break;
    }
}

void StoryTextItem::setItemData(const QString &picPath, const QString &text)
{
    this->m_pic->setPixmap(QPixmap(EmenuEnv::dishPicDir + "/small/" +picPath));
    this->m_text->setHtml("<p> <img src=\"" + EmenuEnv::themeDir + "/sto_picbg.png" + "\"  align=\"left\">" + text + "</p>");
}
