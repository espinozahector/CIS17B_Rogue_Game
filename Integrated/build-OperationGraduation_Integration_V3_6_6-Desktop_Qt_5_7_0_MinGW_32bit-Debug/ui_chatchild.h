/********************************************************************************
** Form generated from reading UI file 'chatchild.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
        ChatChild->resize(350, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChatChild->sizePolicy().hasHeightForWidth());
        ChatChild->setSizePolicy(sizePolicy);
        ChatChild->setMaximumSize(QSize(350, 600));
        menubar = new QMenuBar(ChatChild);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 0, 0));
        centralwidget = new QWidget(ChatChild);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setGeometry(QRect(0, 0, 100, 30));
        statusbar = new QStatusBar(ChatChild);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setGeometry(QRect(0, 0, 3, 18));

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
