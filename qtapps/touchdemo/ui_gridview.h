/********************************************************************************
** Form generated from reading UI file 'gridview.ui'
**
** Created: Fri Apr 12 16:26:38 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRIDVIEW_H
#define UI_GRIDVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GirdView
{
public:

    void setupUi(QWidget *GirdView)
    {
        if (GirdView->objectName().isEmpty())
            GirdView->setObjectName(QString::fromUtf8("GirdView"));
        GirdView->resize(3840, 800);
        GirdView->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(GirdView);

        QMetaObject::connectSlotsByName(GirdView);
    } // setupUi

    void retranslateUi(QWidget *GirdView)
    {
        GirdView->setWindowTitle(QApplication::translate("GirdView", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GirdView: public Ui_GirdView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRIDVIEW_H
