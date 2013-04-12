/********************************************************************************
** Form generated from reading UI file 'albumpreview.ui'
**
** Created: Fri Apr 12 16:26:38 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALBUMPREVIEW_H
#define UI_ALBUMPREVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlbumPreview
{
public:

    void setupUi(QWidget *AlbumPreview)
    {
        if (AlbumPreview->objectName().isEmpty())
            AlbumPreview->setObjectName(QString::fromUtf8("AlbumPreview"));
        AlbumPreview->resize(375, 374);

        retranslateUi(AlbumPreview);

        QMetaObject::connectSlotsByName(AlbumPreview);
    } // setupUi

    void retranslateUi(QWidget *AlbumPreview)
    {
        AlbumPreview->setWindowTitle(QApplication::translate("AlbumPreview", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AlbumPreview: public Ui_AlbumPreview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALBUMPREVIEW_H
