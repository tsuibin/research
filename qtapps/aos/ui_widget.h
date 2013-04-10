/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Thu Apr 12 10:07:06 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetApp
{
public:
    QLabel *label_AppIcon;
    QLabel *label_AppName;
    QLabel *label_AppDelFlag;

    void setupUi(QWidget *SetApp)
    {
        if (SetApp->objectName().isEmpty())
            SetApp->setObjectName(QString::fromUtf8("SetApp"));
        SetApp->resize(80, 90);
        label_AppIcon = new QLabel(SetApp);
        label_AppIcon->setObjectName(QString::fromUtf8("label_AppIcon"));
        label_AppIcon->setGeometry(QRect(10, 0, 60, 60));
        label_AppName = new QLabel(SetApp);
        label_AppName->setObjectName(QString::fromUtf8("label_AppName"));
        label_AppName->setGeometry(QRect(0, 62, 80, 18));
        label_AppName->setMouseTracking(false);
        label_AppName->setLayoutDirection(Qt::LeftToRight);
        label_AppDelFlag = new QLabel(SetApp);
        label_AppDelFlag->setObjectName(QString::fromUtf8("label_AppDelFlag"));
        label_AppDelFlag->setGeometry(QRect(0, 0, 16, 16));
        label_AppDelFlag->setStyleSheet(QString::fromUtf8("background-image: url(:/images/close.png);"));

        retranslateUi(SetApp);

        QMetaObject::connectSlotsByName(SetApp);
    } // setupUi

    void retranslateUi(QWidget *SetApp)
    {
        SetApp->setWindowTitle(QApplication::translate("SetApp", "Widget", 0, QApplication::UnicodeUTF8));
        label_AppIcon->setText(QString());
        label_AppName->setText(QString());
        label_AppDelFlag->setText(QApplication::translate("SetApp", "16", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetApp: public Ui_SetApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
