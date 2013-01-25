#ifndef STORYPAGE_H
#define STORYPAGE_H

#include <QState>

#include "aanimationpage.h"

class AControlButton;
class AGraphicsPixmapObject;
class StorySelectItem;
class StoryTextItem;
class CommonDetail;
class StoryData;
class DishData;

class StoryPage : public AAnimationPage
{
    Q_OBJECT

public:
    StoryPage(QGraphicsItem *parent = 0);

    void setData(const QList <const StoryData *> * storyDataList);

public slots:

signals:
    void left();
    void right();

    void textStart();

protected:
    void setupUI();
    void keyUp_handler();
    void keyDown_handler();
    void keyReturn_handler();
    void resetPage();

private slots:
    void keyEscape_handler();
    void itemSelected();

    void enterDetail();
    void quitDetail();

    void selectItem(int index);

private:
    void setupRootItems();
    void setupDetailItems();
    void setupItemAnimations();
    void setupDetailItemAnimation();

    void initStorySelector();
    void initStoryTextArea();

private:

    AGraphicsRectObject *m_rootPage;
    AGraphicsRectObject *m_storySelector;
    QList <StorySelectItem *> m_storyItemList;
    AGraphicsRectObject *m_storyText;
    AGraphicsRectObject *m_textScrollArea;
    AGraphicsPixmapObject *m_roller_down;
    AGraphicsRectObject *m_textScrollContent;
    QList <StoryTextItem *> m_textItemList;

    CommonDetail *m_detailPage;

    AControlButton *returnButton;
    AControlButton *enterButton;

    int currentItemIndex;
    bool isSelectable;
    bool isDetailStates;

    const QList <const StoryData *> * m_storyDataList;
};

#endif // STORYPAGE_H
