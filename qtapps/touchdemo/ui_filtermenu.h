/********************************************************************************
** Form generated from reading UI file 'filtermenu.ui'
**
** Created: Fri Apr 12 11:39:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERMENU_H
#define UI_FILTERMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterMenu
{
public:

    void setupUi(QWidget *FilterMenu)
    {
        if (FilterMenu->objectName().isEmpty())
            FilterMenu->setObjectName(QString::fromUtf8("FilterMenu"));
        FilterMenu->resize(1280, 103);

        retranslateUi(FilterMenu);

        QMetaObject::connectSlotsByName(FilterMenu);
    } // setupUi

    void retranslateUi(QWidget *FilterMenu)
    {
        FilterMenu->setWindowTitle(QApplication::translate("FilterMenu", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FilterMenu: public Ui_FilterMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERMENU_H
