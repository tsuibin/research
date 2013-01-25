#ifndef RECOMMENDATIONPAGE_H
#define RECOMMENDATIONPAGE_H

#include <QState>

#include "aanimationpage.h"

class AControlButton;
class AGraphicsPixmapObject;
class RecommendationItem;
class RecommendationData;

class RecommendationPage : public AAnimationPage
{
    Q_OBJECT

public:
    RecommendationPage(QGraphicsItem *parent = 0);

    void setData(const QList <const RecommendationData *> *recommendationDataList);

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
    AGraphicsRectObject *m_recommendationItems;
    QList <RecommendationItem *> m_recommendationItemList;

    AGraphicsRectObject *m_detailPage;
    QGraphicsPixmapItem *m_dishPic;
    QGraphicsTextItem *m_dishName;
    QGraphicsTextItem *m_dishInfo;
    QGraphicsTextItem *m_dishRec;
    AGraphicsRectObject *m_icons;
    QList <QGraphicsPixmapItem *> m_iconList;
    AControlButton *upButton;
    AControlButton *downButton;

    int currentItemIndex;
    bool isSelectable;
    bool isDetailStates;

    const QList <const RecommendationData *> * m_recommendationDataList;
};

#endif // RECOMMENDATIONPAGE_H
