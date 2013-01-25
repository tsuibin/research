#ifndef FEATUREQUERYPAGE_H
#define FEATUREQUERYPAGE_H

#include "aanimationpage.h"

class FeatureQueryItem;
class CommonMenuPage;
class AGraphicsPixmapObject;
class AControlButton;
class CategoryData;

class FeatureQueryPage : public AAnimationPage
{
    Q_OBJECT

public:
    FeatureQueryPage(QGraphicsItem *parent = 0);
    ~FeatureQueryPage();

    void setData(const QMap <int,CategoryData *> *categoryIdMap);

signals:
    void hideItem();
    void showItem();
    void childIn();
    void childOut();

protected:
    void setupUI();
    void resetPage();

protected slots:
    void keyUp_handler();
    void keyDown_handler();
    void keyLeft_handler();
    void keyRight_handler();
    void keyReturn_handler();
    void keyEscape_handler();

private slots:
    void itemSelected();
    void selectItem(int index);

    void startSelect();
    void closeSelect();

    void enterDetail();
    void quitDetail();

private:
    void setupRootItems();
    void setupItemAnimations();
    void setupDetailItems();
    void setupDetailItemAnimation();

private:
    AGraphicsRectObject *m_rootPage;
    AGraphicsRectObject *m_queryItems;
    QList <FeatureQueryItem *> m_queryItemList;
    AControlButton *returnButton;
    CommonMenuPage *m_detailPage;

    int currentItemIndex;
    bool isSelectable;
    bool isDetailStates;

    const QMap <int,CategoryData *> * m_categoryIdMap;
    QList <CategoryData *> m_categoryList;
};

#endif // FEATUREQUERYPAGE_H
