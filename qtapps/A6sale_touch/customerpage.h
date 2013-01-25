#ifndef CUSTOMERPAGE_H
#define CUSTOMERPAGE_H

#include <QState>
#include <QParallelAnimationGroup>

#include "agraphicsrectobject.h"

class AGraphicsPixmapObject;
class AControlButton;

class CustomerPage : public AGraphicsRectObject
{
    Q_OBJECT

public:
    CustomerPage(QGraphicsItem *parent = 0);
    ~CustomerPage();

    enum BrowseOption {
        Story,
        Recommondation,
        Rank,
        Discount,
        Health,
        FeatureQuery,
        CommonMenu,
        Query
    };

public slots:
    void showCustomerPage();
    void quitCustomerPage();

signals:
    void optionSelected(int);
    void quitPage();
    void left();
    void right();

protected:
    void keyPressEvent (QKeyEvent * event);

private slots:
    void itemSelected();

    void selectLeft();
    void selectRight();

private:
    void setupItems();
    void setupItemAnimations();

private:
    AGraphicsPixmapObject *m_wallpaper;
    AControlButton *m_textBackground;
    QList <AGraphicsPixmapObject *> m_picItemList;
    QList <QGraphicsTextItem *> m_textItemList;
    AControlButton *returnButton;
    AControlButton *leftButton;
    AControlButton *rightButton;

    QParallelAnimationGroup *m_group;
    QList<QState *> m_states;

    int m_currentSelectIndex;
};

#endif // CUSTOMERPAGE_H
