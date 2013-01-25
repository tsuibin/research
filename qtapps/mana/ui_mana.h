/********************************************************************************
** Form generated from reading UI file 'mana.ui'
**
** Created: Tue Mar 8 10:36:39 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANA_H
#define UI_MANA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mana
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;

    void setupUi(QWidget *Mana)
    {
        if (Mana->objectName().isEmpty())
            Mana->setObjectName(QString::fromUtf8("Mana"));
        Mana->resize(400, 300);
        pushButton = new QPushButton(Mana);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 250, 85, 27));
        lineEdit = new QLineEdit(Mana);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 250, 261, 25));
        textEdit = new QTextEdit(Mana);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 20, 311, 211));

        retranslateUi(Mana);

        QMetaObject::connectSlotsByName(Mana);
    } // setupUi

    void retranslateUi(QWidget *Mana)
    {
        Mana->setWindowTitle(QApplication::translate("Mana", "Mana", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Mana", "Send", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Mana: public Ui_Mana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANA_H
