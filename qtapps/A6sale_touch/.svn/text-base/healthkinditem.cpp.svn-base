#include <QFont>

#include "healthkinditem.h"
#include "emenuenv.h"

HealthKindItem::HealthKindItem(QGraphicsItem *parent) :
        AGraphicsSelectItem(parent)
{
    this->m_background = new QGraphicsPixmapItem(this);
    this->m_background->setPos(0,0);
    this->m_background->setZValue(0);
    this->m_background->setPixmap(QPixmap(EmenuEnv::themeDir + "/hea_cursor.png"));

    QFont font;
    this->m_text = new QGraphicsTextItem(this);
    this->m_text->setDefaultTextColor(EmenuEnv::textHeadingColor);
    this->m_text->setZValue(1);
    this->m_text->setTextWidth(this->m_background->pixmap().width());
    switch (EmenuEnv::currentResolution) {
    case EmenuEnv::R_1280_768:
        font.setPixelSize(35);
        this->m_text->setFont(font);
        this->m_text->setPos(0,10);
        break;
    case EmenuEnv::R_640_480:
    default:
        font.setPixelSize(20);
        this->m_text->setFont(font);
        this->m_text->setPos(0,5);
        break;
    }

    this->setRect(this->m_background->boundingRect());
}

HealthKindItem::~HealthKindItem()
{
}

void HealthKindItem::setData(const QString &text)
{
    this->m_text->setPlainText(text);
}

void HealthKindItem::updateStatus()
{
    switch (this->m_currentStatus) {
    case AGraphicsSelectItem::Active:
        this->m_background->setVisible(true);
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingActiveColor);
        break;

    default:
        this->m_background->setVisible(false);
        this->m_text->setDefaultTextColor(EmenuEnv::textHeadingColor);
        break;
    }
}
