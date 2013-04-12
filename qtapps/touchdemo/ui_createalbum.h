/********************************************************************************
** Form generated from reading UI file 'createalbum.ui'
**
** Created: Fri Apr 12 11:39:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEALBUM_H
#define UI_CREATEALBUM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateAlbum
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QWidget *CreateAlbum)
    {
        if (CreateAlbum->objectName().isEmpty())
            CreateAlbum->setObjectName(QString::fromUtf8("CreateAlbum"));
        CreateAlbum->resize(448, 234);
        pushButton = new QPushButton(CreateAlbum);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 140, 85, 41));
        pushButton_2 = new QPushButton(CreateAlbum);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 140, 81, 41));
        lineEdit = new QLineEdit(CreateAlbum);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 100, 281, 27));
        label = new QLabel(CreateAlbum);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 60, 111, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Droid Sans [unknown]"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        retranslateUi(CreateAlbum);

        QMetaObject::connectSlotsByName(CreateAlbum);
    } // setupUi

    void retranslateUi(QWidget *CreateAlbum)
    {
        CreateAlbum->setWindowTitle(QApplication::translate("CreateAlbum", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("CreateAlbum", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("CreateAlbum", "PushButton", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("CreateAlbum", "\350\257\267\344\270\272\346\255\244\347\233\270\345\206\214\350\276\223\345\205\245\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateAlbum", "\346\226\260\345\273\272\347\233\270\345\206\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateAlbum: public Ui_CreateAlbum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEALBUM_H
