#include <QFont>

#include "rankitem.h"
#include "emenuenv.h"

RankItem::RankItem(int rankNo,QGraphicsItem *parent) :
        AGraphicsSelectItem(parent)
{
    this->m_background = new QGraphicsPixmapItem(this);
    this->m_background->setPos(0,0);
    this->m_background->setZValue(1);
    if (rankNo >= 1 && rankNo <= 3) {
        this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/ran_item1.png"));
    } else if (rankNo > 3 && rankNo <= 6) {
        this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/ran_item2.png"));
    } else {
        this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/ran_item3.png"));
    }

    QFont font;
    this->m_text = new QGraphicsTextItem(this);
    this->m_text->setDefaultTextColor(EmenuEnv::textHeadingColor);
    this->m_text->setZValue(2);
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        font.setPixelSize(35);
        this->m_text->setFont(font);
        this->m_text->setPos(120,50);
        this->m_text->setTextWidth(360);
        break;
    case EmenuEnv::R_640_480:
    default:
        font.setPixelSize(20);
        this->m_text->setFont(font);
        this->m_text->setPos(65,27);
        this->m_text->setTextWidth(220);
        break;
    }


    this->m_rankNo = new QGraphicsTextItem(this);
    if (rankNo >= 1 && rankNo <= 3) {
        this->m_rankNo->setDefaultTextColor(EmenuEnv::textActiveColor);
    } else {
        this->m_rankNo->setDefaultTextColor(EmenuEnv::textHeadingActiveColor);
    }
    this->m_rankNo->setZValue(2);
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        font.setPixelSize(40);
        font.setItalic(true);
        this->m_rankNo->setFont(font);
        this->m_rankNo->setPos(20,45);
        this->m_rankNo->setTextWidth(80);
        break;
    case EmenuEnv::R_640_480:
    default:
        font.setPixelSize(22);
        font.setItalic(true);
        this->m_rankNo->setFont(font);
        this->m_rankNo->setPos(15,25);
        this->m_rankNo->setTextWidth(40);
        break;
    }
    this->m_rankNo->setHtml("<p align = 'center'>" + QString::number(rankNo) + "</p>");

    this->m_icon = new QGraphicsPixmapItem(this);
    this->m_icon->setZValue(2);
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        this->m_icon->setPos(473,38);
        break;
    case EmenuEnv::R_640_480:
    default:
        this->m_icon->setPos(275,22);
        break;
    }

    this->m_active = new QGraphicsPixmapItem(QPixmap(EmenuEnv::themeDir + "/ran_item_active.png"),this);
    this->m_active->setPos(0,0);
    this->m_active->setZValue(0);
    this->m_active->setVisible(false);

    this->setRect(this->m_background->boundingRect());
}

RankItem::~RankItem()
{
}

void RankItem::setData(const QString &text,bool up)
{
    this->m_text->setPlainText(text);
    if (up == false) {
        this->m_icon->setPixmap(QPixmap(EmenuEnv::themeDir + "/ran_down.png"));
    } else {
        this->m_icon->setPixmap(QPixmap(EmenuEnv::themeDir + "/ran_up.png"));
    }
}

void RankItem::updateStatus()
{
    switch (this->m_currentStatus) {
    case AGraphicsSelectItem::Active:
        this->m_active->setVisible(true);
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingActiveColor);
        break;

    default:
        this->m_active->setVisible(false);
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingColor);
        break;
    }
}
