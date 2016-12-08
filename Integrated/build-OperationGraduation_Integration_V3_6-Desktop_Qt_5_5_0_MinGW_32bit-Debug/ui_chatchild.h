/********************************************************************************
** Form generated from reading UI file 'chatchild.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATCHILD_H
#define UI_CHATCHILD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMdiSubWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatChild
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMdiSubWindow *ChatChild)
    {
        if (ChatChild->objectName().isEmpty())
            ChatChild->setObjectName(QStringLiteral("ChatChild"));
        ChatChild->resize(800, 600);
        menubar = new QMenuBar(ChatChild);
        menubar->setObjectName(QStringLiteral("menubar"));
        centralwidget = new QWidget(ChatChild);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        statusbar = new QStatusBar(ChatChild);
        statusbar->setObjectName(QStringLiteral("statusbar"));

        retranslateUi(ChatChild);

        QMetaObject::connectSlotsByName(ChatChild);
    } // setupUi

    void retranslateUi(QMdiSubWindow *ChatChild)
    {
        ChatChild->setWindowTitle(QApplication::translate("ChatChild", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatChild: public Ui_ChatChild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATCHILD_H
