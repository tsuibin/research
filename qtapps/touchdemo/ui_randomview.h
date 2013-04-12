/********************************************************************************
** Form generated from reading UI file 'randomview.ui'
**
** Created: Fri Apr 12 16:26:38 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDOMVIEW_H
#define UI_RANDOMVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RandomView
{
public:

    void setupUi(QWidget *RandomView)
    {
        if (RandomView->objectName().isEmpty())
            RandomView->setObjectName(QString::fromUtf8("RandomView"));
        RandomView->resize(1280, 800);

        retranslateUi(RandomView);

        QMetaObject::connectSlotsByName(RandomView);
    } // setupUi

    void retranslateUi(QWidget *RandomView)
    {
        RandomView->setWindowTitle(QApplication::translate("RandomView", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RandomView: public Ui_RandomView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMVIEW_H
