#include <QKeyEvent>
#include <QDebug>
#include <QApplication>

#include "emenu.h"
#include "emenudata.h"
#include "emenuenv.h"

#include "welcompage.h"
#include "customerpage.h"
#include "discountpage.h"
#include "storypage.h"
#include "healthpage.h"
#include "commonmenupage.h"
#include "featurequerypage.h"
#include "recommendationpage.h"
#include "rankpage.h"

Emenu::Emenu(QWidget * parent) :
        QGraphicsView(parent)
{        
    this->setupData();
    this->setupScene();
    this->setupPages();
    this->setupInterfaces();
}

Emenu::~Emenu()
{
    delete this->m_pagesRoot;
    delete this->m_scene;
}

void Emenu::setupData()
{
    this->m_emenuData = new EmenuData();
    this->m_emenuData->loadData();
}

void Emenu::setupScene()
{
    this->m_scene = new QGraphicsScene(-EmenuEnv::resolutionWidth / 2,- EmenuEnv::resolutionHeight / 2,EmenuEnv::resolutionWidth,EmenuEnv::resolutionHeight);
    this->m_scene->setStickyFocus(true);

    this->setScene(m_scene);
    this->centerOn(0,0);
    this->setBackgroundBrush(Qt::black);
    this->resize(EmenuEnv::resolutionWidth,EmenuEnv::resolutionHeight);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void Emenu::setupPages()
{
    this->m_pagesRoot = new QGraphicsRectItem(0,0,EmenuEnv::resolutionWidth,EmenuEnv::resolutionHeight);
    this->m_pagesRoot->setPos(-EmenuEnv::resolutionWidth / 2,- EmenuEnv::resolutionHeight / 2);
    this->m_pagesRoot->setFlag(QGraphicsItem::ItemClipsChildrenToShape,true);

    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(this->m_pagesRoot);
    background->setPixmap(QPixmap(EmenuEnv::themeDir + "/bg.jpg"));
    background->setZValue(0);

    this->m_welcomPage = new WelcomPage(this->m_pagesRoot);
    this->m_welcomPage->setZValue(1);
    this->m_customerPage = new CustomerPage(this->m_pagesRoot);
    this->m_customerPage->setZValue(2);
    this->m_discountPage = new DiscountPage(this->m_pagesRoot);
    this->m_discountPage->setZValue(3);
    this->m_storyPage = new StoryPage(this->m_pagesRoot);
    this->m_storyPage->setZValue(4);
    this->m_healthPage = new HealthPage(this->m_pagesRoot);
    this->m_healthPage->setZValue(5);
    this->m_commonMenuPage = new CommonMenuPage(this->m_pagesRoot);
    this->m_commonMenuPage->setZValue(6);
    this->m_featureQueryPage = new FeatureQueryPage(this->m_pagesRoot);
    this->m_featureQueryPage->setZValue(7);
    this->m_recommendationPage = new RecommendationPage(this->m_pagesRoot);
    this->m_recommendationPage->setZValue(8);
    this->m_rankPage = new RankPage(this->m_pagesRoot);
    this->m_rankPage->setZValue(9);

    this->m_scene->addItem(this->m_pagesRoot);
}

void Emenu::setupInterfaces()
{
    connect(this->m_welcomPage,SIGNAL(enter()),this->m_customerPage,SLOT(showCustomerPage()));
    connect(this->m_customerPage,SIGNAL(optionSelected(int)),this,SLOT(showPage(int)));

    connect(this->m_customerPage,SIGNAL(quitPage()),this->m_welcomPage,SLOT(showWelcomPage()));
    connect(this->m_discountPage,SIGNAL(quitPage()),this->m_customerPage,SLOT(showCustomerPage()));
    connect(this->m_storyPage,SIGNAL(quitPage()),this->m_customerPage,SLOT(showCustomerPage()));
    connect(this->m_healthPage,SIGNAL(quitPage()),this->m_customerPage,SLOT(showCustomerPage()));
    connect(this->m_commonMenuPage,SIGNAL(quitPage()),this->m_customerPage,SLOT(showCustomerPage()));
    connect(this->m_featureQueryPage,SIGNAL(quitPage()),this->m_customerPage,SLOT(showCustomerPage()));
    connect(this->m_recommendationPage,SIGNAL(quitPage()),this->m_customerPage,SLOT(showCustomerPage()));
    connect(this->m_rankPage,SIGNAL(quitPage()),this->m_customerPage,SLOT(showCustomerPage()));

    this->m_welcomPage->setWelcomPic(EmenuEnv::themeDir + "/mainemenu.jpg");
    this->m_discountPage->setData(this->m_emenuData->getDiscountData());
    this->m_storyPage->setData(this->m_emenuData->getStoryDataList());
    this->m_commonMenuPage->setData(this->m_emenuData->getDishDataList());
    this->m_recommendationPage->setData(this->m_emenuData->getRecommendationDataList());
    this->m_rankPage->setData(this->m_emenuData->getRankDataList());
    this->m_featureQueryPage->setData(this->m_emenuData->getCategoryDataMap());
}

void Emenu::start()
{
    if (EmenuEnv::fullScreen == 0) {
        this->show();
    } else {
        this->showFullScreen();
    }

    this->m_welcomPage->showWelcomPage();
}

void Emenu::showPage(int option)
{
    switch (option) {
    case CustomerPage::Story:
        this->m_storyPage->showPage();
        this->m_customerPage->setVisible(false);
        break;

    case CustomerPage::Recommondation:
        this->m_recommendationPage->showPage();
        this->m_customerPage->setVisible(false);
        break;

    case CustomerPage::Rank:
        this->m_rankPage->showPage();
        this->m_customerPage->setVisible(false);
        break;

    case CustomerPage::Discount:
        this->m_discountPage->showPage();
        this->m_customerPage->setVisible(false);
        break;

    case CustomerPage::Health:
//        this->m_healthPage->showHealthPage();
//        this->m_customerPage->setVisible(false);
        break;

    case CustomerPage::FeatureQuery:
        this->m_featureQueryPage->showPage();
        this->m_customerPage->setVisible(false);
        break;

    case CustomerPage::CommonMenu:
        this->m_commonMenuPage->showPage();
        this->m_customerPage->setVisible(false);
        break;

//    case CustomerPage::Query:
//        break;

    default:
        break;
    }
}

void Emenu::keyPressEvent(QKeyEvent *event)
{
//    qDebug() << "Emenu::keyPressEvent: " << event->key() << this->m_scene->focusItem() << QApplication::focusWidget () ;
    QGraphicsView::keyPressEvent(event);
}
