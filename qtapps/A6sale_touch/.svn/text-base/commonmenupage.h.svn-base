#ifndef COMMONMENUPAGE_H
#define COMMONMENUPAGE_H

#include "aanimationpage.h"

class CommonMenuItem;
class CommonDetail;
class DishData;
class AControlButton;

class CommonMenuPage : public AAnimationPage
{
    Q_OBJECT

public:
    CommonMenuPage(QGraphicsItem *parent = 0);
    ~CommonMenuPage();

    void setData(const QList <const DishData *> *dishDataList);

signals:
    void hideItem();
    void showItem();
    void childIn();
    void childOut();

protected slots:
    void keyEscape_handler();
    void keyReturn_handler();
    void keyUp_handler();
    void keyDown_handler();
    void keyLeft_handler();
    void keyRight_handler();
    void setupUI();
    void resetPage();

private slots:
    void selectItem(int index);
    void itemSelected();

    void startSelect();
    void closeSelect();

    void detailSelectnext();
    void detailSelectPrevious();

private:
    void setupRootItems();
    void setupDetailItems();
    void setupItemAnimations();
    void setupDetailItemAnimation();

    void updatePage();

    void enterDetail();
    void quitDetail();

private:
    AControlButton *returnButton;

    AGraphicsRectObject *m_rootPage;
    AGraphicsRectObject *m_dishItems;
    QList <CommonMenuItem *> m_dishItemList;
    AControlButton *upButton;
    AControlButton *downButton;

    CommonDetail *m_detailPage;
    AControlButton *detailUpButton;
    AControlButton *detailDownButton;

    int currentItemIndex;
    bool isSelectable;
    bool isDetailStates;

    int m_itemPerPage;
    int m_currentPage;
    int m_pageCount;
    int validItemCount;

    const QList <const DishData *> *m_dishDataList;
};


#endif // COMMONMENUPAGE_H
