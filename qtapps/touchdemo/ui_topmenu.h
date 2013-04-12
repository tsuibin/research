/********************************************************************************
** Form generated from reading UI file 'topmenu.ui'
**
** Created: Fri Apr 12 11:39:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPMENU_H
#define UI_TOPMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopMenu
{
public:
    QLabel *label;
    QLabel *label_title;
    QLabel *label_edit;
    QLabel *label_create;
    QLabel *label_ret;

    void setupUi(QWidget *TopMenu)
    {
        if (TopMenu->objectName().isEmpty())
            TopMenu->setObjectName(QString::fromUtf8("TopMenu"));
        TopMenu->resize(1280, 48);
        label = new QLabel(TopMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 48));
        label_title = new QLabel(TopMenu);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(10, 10, 181, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label_title->setFont(font);
        label_title->setStyleSheet(QString::fromUtf8("color: rgb(67, 67, 67);\n"
"font: 75 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_edit = new QLabel(TopMenu);
        label_edit->setObjectName(QString::fromUtf8("label_edit"));
        label_edit->setGeometry(QRect(1212, 0, 68, 48));
        label_create = new QLabel(TopMenu);
        label_create->setObjectName(QString::fromUtf8("label_create"));
        label_create->setGeometry(QRect(1144, 0, 68, 48));
        label_ret = new QLabel(TopMenu);
        label_ret->setObjectName(QString::fromUtf8("label_ret"));
        label_ret->setGeometry(QRect(1076, 0, 68, 48));

        retranslateUi(TopMenu);

        QMetaObject::connectSlotsByName(TopMenu);
    } // setupUi

    void retranslateUi(QWidget *TopMenu)
    {
        TopMenu->setWindowTitle(QApplication::translate("TopMenu", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_title->setText(QApplication::translate("TopMenu", "\346\267\261\345\272\246\347\234\213\345\233\276", 0, QApplication::UnicodeUTF8));
        label_edit->setText(QString());
        label_create->setText(QString());
        label_ret->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TopMenu: public Ui_TopMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPMENU_H
