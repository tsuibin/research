#ifndef RANKPAGE_H
#define RANKPAGE_H

#include <QState>

#include "aanimationpage.h"

class AGraphicsPixmapObject;
class AControlButton;
class RankItem;
class RankData;

class RankPage : public AAnimationPage
{
    Q_OBJECT

public:
    RankPage(QGraphicsItem *parent = 0);
    ~RankPage();

    void setData(const QList <const RankData *> *rankDataList);

protected:
    void setupUI();

    void keyUp_handler();
    void keyDown_handler();
    void keyLeft_handler();
    void keyRight_handler();
    void keyReturn_handler();
    void keyEscape_handler();

private slots:
    void selectItem(int index);
    void itemSelected();
    void resetPage();

    void enterDetail();
    void quitDetail();

    void detailSelectnext();
    void detailSelectPrevious();

private:
    void setupRootItems();
    void setupDetailItems();
    void setupItemAnimations();
    void setupDetailItemAnimation();

private:
    AControlButton *returnButton;

    AGraphicsRectObject *m_rootPage;
    AGraphicsRectObject *m_rankItems;
    QList <RankItem *> m_rankItemList;

    AGraphicsRectObject *m_detailPage;
    QGraphicsPixmapItem *m_dishPic;
    QGraphicsTextItem *m_dishName;
    QGraphicsTextItem *m_dishInfo;
    QGraphicsTextItem *m_dishRankNo;
    QGraphicsPixmapItem *m_dishUp;
    AGraphicsRectObject *m_icons;
    QList <QGraphicsPixmapItem *> m_iconList;
    AControlButton *upButton;
    AControlButton *downButton;

    int currentItemIndex;
    bool isSelectable;
    bool isDetailStates;

    const QList <const RankData *> * m_rankDataList;
};

#endif // RANKPAGE_H
