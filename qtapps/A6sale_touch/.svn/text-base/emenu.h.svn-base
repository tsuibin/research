#ifndef EMENU_H
#define EMENU_H

#include <QGraphicsView>

class WelcomPage;
class CustomerPage;
class DiscountPage;
class StoryPage;
class HealthPage;
class CommonMenuPage;
class FeatureQueryPage;
class RecommendationPage;
class RankPage;
class EmenuData;

class Emenu : public QGraphicsView
{
    Q_OBJECT

public:
    Emenu(QWidget * parent = 0);
    ~Emenu();

public slots:
    void start();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void showPage(int option);

private:
    void setupData();
    void setupScene();
    void setupPages();
    void setupInterfaces();

private:
    QGraphicsScene *m_scene;

    QGraphicsRectItem *m_pagesRoot;
    WelcomPage *m_welcomPage;
    CustomerPage *m_customerPage;
    DiscountPage *m_discountPage;
    HealthPage *m_healthPage;
    CommonMenuPage *m_commonMenuPage;
    FeatureQueryPage *m_featureQueryPage;
    RecommendationPage *m_recommendationPage;
    RankPage *m_rankPage;
    StoryPage *m_storyPage;

    EmenuData *m_emenuData;
};

#endif // EMENU_H
