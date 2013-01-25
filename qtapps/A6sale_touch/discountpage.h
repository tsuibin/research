#ifndef DISCOUNTPAGE_H
#define DISCOUNTPAGE_H

#include "aanimationpage.h"

class DiscountItem;
class DiscountPriceItem;
class AControlButton;
class AGraphicsPixmapObject;
class DiscountData;
class DishData;

class DiscountPage : public AAnimationPage
{
    Q_OBJECT

public:
    DiscountPage(QGraphicsItem *parent = 0);
    ~DiscountPage();

    void setData(const QList <const DiscountData *> *discountDataList);

signals:
    void hideItem();
    void showItem();

    void childIn();
    void childOut();

protected:
    void setupUI();

    void keyUp_handler();
    void keyDown_handler();
    void keyLeft_handler();
    void keyRight_handler();
    void keyReturn_handler();
    void keyEscape_handler();

    void resetPage();

private slots:
    void startSelect();
    void closeSelect();

    void selectItem(int index);
    void itemSelected();

//    void showDetail();
    void enterDetail();
    void quitDetail();

    void detailSelectnext();
    void detailSelectPrevious();

private:
    void setupRootItems();
    void setupItemAnimations();
    void setupDetailItems();
    void setupDetailItemAnimation();

private:
    AControlButton *returnButton;

    AGraphicsRectObject *m_rootPage;
    QList <AGraphicsPixmapObject *> m_cornerList;
    QList <DiscountItem *> m_itemList;
    QList <DiscountPriceItem *> m_priceItemList;

    AGraphicsRectObject *m_detailPage;
    AGraphicsPixmapObject *m_detailCorner;
    AGraphicsPixmapObject *m_dishPicBg;
    QGraphicsPixmapItem *m_detailDishPic;
    QGraphicsTextItem *m_detailDishName;
    QGraphicsTextItem *m_detailPriceItem;
    QGraphicsTextItem *m_detailOldPriceItem;
    QGraphicsTextItem *m_detailDishInfoItem;
    AGraphicsRectObject *m_icons;
    QList <QGraphicsPixmapItem *> m_iconList;
    AControlButton *upButton;
    AControlButton *downButton;

    int currentItemIndex;
    bool isSelectable;
    bool isDetailStates;

    const QList <const DiscountData *> *m_discountDataList;
};

#endif // DISCOUNTPAGE_H
