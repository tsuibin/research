#ifndef HEALTHPAGE_H
#define HEALTHPAGE_H

#include <QParallelAnimationGroup>
#include <QState>
#include <QStateMachine>

#include "aanimationpage.h"

class HealthItem;
class HealthKindItem;
class AGraphicsPixmapObject;

class HealthPage : public AAnimationPage
{
    Q_OBJECT

public:
    HealthPage(QGraphicsItem *parent = 0);

public slots:
    void showHealthPage();
    void hideHealthPage();

signals:
    void quitPage();
    void up();
    void down();
    void left();
    void right();

protected:
    void setupUI();

    void keyUp_handler();
    void keyDown_handler();
    void keyLeft_handler();
    void keyRight_handler();
    void keyReturn_handler();
    void keyEscape_handler();

private slots:
    void enterDetail();
    void quitDetail();

private:  
    void setupRootItems();
    void setupDetailItems();
    void setupItemAnimations();
    void setupDetailItemAnimation();

private:
    AGraphicsPixmapObject *m_wallpaper;

    AGraphicsRectObject *m_rootPage;
    AGraphicsPixmapObject *m_naviBar;
//    AGraphicsPixmapObject *m_cursor;
    QList <HealthKindItem *> m_kindItemList;
    QList<QList<HealthItem*> *> m_dishList;
    QList<AGraphicsPixmapObject*> m_kindItems;
    QParallelAnimationGroup *m_group;
    QList<QState *> m_states;
    QStateMachine *m_stateMachine;

    AGraphicsRectObject *m_detailPage;
    QGraphicsPixmapItem *m_dishPic;
    QGraphicsTextItem *m_dishName;
    AGraphicsRectObject *m_levelStars;
    QList <QGraphicsPixmapItem *> m_levelStarList;
    QGraphicsTextItem *m_dishInfo;
    AGraphicsRectObject *m_icons;
    QList <QGraphicsPixmapItem *> m_iconList;

    bool isDetail;
};

#endif // HEALTHPAGE_H
