/********************************************************************************
** Form generated from reading UI file 'capture.ui'
**
** Created: Fri Oct 29 14:58:56 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTURE_H
#define UI_CAPTURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Capture
{
public:

    void setupUi(QWidget *Capture)
    {
        if (Capture->objectName().isEmpty())
            Capture->setObjectName(QString::fromUtf8("Capture"));
        Capture->resize(400, 300);

        retranslateUi(Capture);

        QMetaObject::connectSlotsByName(Capture);
    } // setupUi

    void retranslateUi(QWidget *Capture)
    {
        Capture->setWindowTitle(QApplication::translate("Capture", "Capture", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Capture: public Ui_Capture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTURE_H
