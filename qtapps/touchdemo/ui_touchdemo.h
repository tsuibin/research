/********************************************************************************
** Form generated from reading UI file 'touchdemo.ui'
**
** Created: Fri Apr 12 16:26:38 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOUCHDEMO_H
#define UI_TOUCHDEMO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TouchDemo
{
public:
    QLabel *label;

    void setupUi(QWidget *TouchDemo)
    {
        if (TouchDemo->objectName().isEmpty())
            TouchDemo->setObjectName(QString::fromUtf8("TouchDemo"));
        TouchDemo->resize(1280, 800);
        label = new QLabel(TouchDemo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1280, 800));

        retranslateUi(TouchDemo);

        QMetaObject::connectSlotsByName(TouchDemo);
    } // setupUi

    void retranslateUi(QWidget *TouchDemo)
    {
        TouchDemo->setWindowTitle(QApplication::translate("TouchDemo", "TouchDemo", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TouchDemo: public Ui_TouchDemo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOUCHDEMO_H
