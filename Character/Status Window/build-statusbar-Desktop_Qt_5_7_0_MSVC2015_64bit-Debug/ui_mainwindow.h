/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *bgGraphic;
    QLabel *xpLabel;
    QProgressBar *healthBar;
    QFrame *attackArmorFrame;
    QLabel *attackLabel;
    QLabel *armorLabel;
    QLabel *attackNumber;
    QLabel *armorNumber;
    QLabel *charName;
    QLabel *xpNextLvlNumber;
    QFrame *critSpeedFrame;
    QLabel *critLabel;
    QLabel *speedLabel;
    QLabel *critNumber;
    QLabel *speedNumber;
    QLabel *xpCurrentNumber;
    QProgressBar *xpBar;
    QLabel *charNameLabel;
    QLabel *levelNumber;
    QLabel *healthLabel;
    QProgressBar *specialBar;
    QLabel *specialLabel;
    QLabel *levelLabel;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 180);
        MainWindow->setMinimumSize(QSize(900, 180));
        MainWindow->setMaximumSize(QSize(900, 180));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral(""));
        MainWindow->setAnimated(false);
        MainWindow->setDocumentMode(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        bgGraphic = new QLabel(centralWidget);
        bgGraphic->setObjectName(QStringLiteral("bgGraphic"));
        bgGraphic->setGeometry(QRect(0, 0, 901, 181));
        bgGraphic->setPixmap(QPixmap(QString::fromUtf8(":/StatusBG.jpg")));
        xpLabel = new QLabel(centralWidget);
        xpLabel->setObjectName(QStringLiteral("xpLabel"));
        xpLabel->setGeometry(QRect(570, 70, 81, 41));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        xpLabel->setFont(font);
        xpLabel->setAlignment(Qt::AlignCenter);
        healthBar = new QProgressBar(centralWidget);
        healthBar->setObjectName(QStringLiteral("healthBar"));
        healthBar->setGeometry(QRect(130, 12, 761, 41));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(healthBar->sizePolicy().hasHeightForWidth());
        healthBar->setSizePolicy(sizePolicy);
        healthBar->setStyleSheet(QStringLiteral(""));
        healthBar->setValue(0);
        healthBar->setTextVisible(false);
        attackArmorFrame = new QFrame(centralWidget);
        attackArmorFrame->setObjectName(QStringLiteral("attackArmorFrame"));
        attackArmorFrame->setGeometry(QRect(160, 100, 151, 71));
        attackArmorFrame->setStyleSheet(QStringLiteral(""));
        attackArmorFrame->setFrameShape(QFrame::WinPanel);
        attackArmorFrame->setFrameShadow(QFrame::Sunken);
        attackArmorFrame->setLineWidth(0);
        attackArmorFrame->setMidLineWidth(0);
        attackLabel = new QLabel(attackArmorFrame);
        attackLabel->setObjectName(QStringLiteral("attackLabel"));
        attackLabel->setGeometry(QRect(10, 10, 71, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        attackLabel->setFont(font1);
        attackLabel->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        attackLabel->setAlignment(Qt::AlignCenter);
        armorLabel = new QLabel(attackArmorFrame);
        armorLabel->setObjectName(QStringLiteral("armorLabel"));
        armorLabel->setGeometry(QRect(10, 40, 71, 21));
        armorLabel->setFont(font1);
        armorLabel->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        armorLabel->setAlignment(Qt::AlignCenter);
        attackNumber = new QLabel(attackArmorFrame);
        attackNumber->setObjectName(QStringLiteral("attackNumber"));
        attackNumber->setGeometry(QRect(90, 10, 41, 21));
        attackNumber->setFont(font1);
        attackNumber->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 0, 0);"));
        attackNumber->setAlignment(Qt::AlignCenter);
        armorNumber = new QLabel(attackArmorFrame);
        armorNumber->setObjectName(QStringLiteral("armorNumber"));
        armorNumber->setGeometry(QRect(90, 40, 41, 21));
        armorNumber->setFont(font1);
        armorNumber->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 255);"));
        armorNumber->setAlignment(Qt::AlignCenter);
        charName = new QLabel(centralWidget);
        charName->setObjectName(QStringLiteral("charName"));
        charName->setGeometry(QRect(240, 60, 231, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Adobe Arabic"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        charName->setFont(font2);
        charName->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        charName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        xpNextLvlNumber = new QLabel(centralWidget);
        xpNextLvlNumber->setObjectName(QStringLiteral("xpNextLvlNumber"));
        xpNextLvlNumber->setGeometry(QRect(720, 70, 91, 41));
        xpNextLvlNumber->setFont(font);
        xpNextLvlNumber->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        critSpeedFrame = new QFrame(centralWidget);
        critSpeedFrame->setObjectName(QStringLiteral("critSpeedFrame"));
        critSpeedFrame->setGeometry(QRect(320, 100, 151, 71));
        critSpeedFrame->setStyleSheet(QStringLiteral(""));
        critSpeedFrame->setFrameShape(QFrame::WinPanel);
        critSpeedFrame->setFrameShadow(QFrame::Sunken);
        critSpeedFrame->setLineWidth(0);
        critSpeedFrame->setMidLineWidth(0);
        critLabel = new QLabel(critSpeedFrame);
        critLabel->setObjectName(QStringLiteral("critLabel"));
        critLabel->setGeometry(QRect(10, 10, 71, 21));
        critLabel->setFont(font1);
        critLabel->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        critLabel->setAlignment(Qt::AlignCenter);
        speedLabel = new QLabel(critSpeedFrame);
        speedLabel->setObjectName(QStringLiteral("speedLabel"));
        speedLabel->setGeometry(QRect(10, 40, 71, 21));
        speedLabel->setFont(font1);
        speedLabel->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        speedLabel->setAlignment(Qt::AlignCenter);
        critNumber = new QLabel(critSpeedFrame);
        critNumber->setObjectName(QStringLiteral("critNumber"));
        critNumber->setGeometry(QRect(90, 10, 41, 21));
        critNumber->setFont(font1);
        critNumber->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(183, 1, 255);"));
        critNumber->setAlignment(Qt::AlignCenter);
        speedNumber = new QLabel(critSpeedFrame);
        speedNumber->setObjectName(QStringLiteral("speedNumber"));
        speedNumber->setGeometry(QRect(90, 40, 41, 21));
        speedNumber->setFont(font1);
        speedNumber->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        speedNumber->setAlignment(Qt::AlignCenter);
        xpCurrentNumber = new QLabel(centralWidget);
        xpCurrentNumber->setObjectName(QStringLiteral("xpCurrentNumber"));
        xpCurrentNumber->setGeometry(QRect(640, 70, 81, 41));
        xpCurrentNumber->setFont(font);
        xpCurrentNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        xpBar = new QProgressBar(centralWidget);
        xpBar->setObjectName(QStringLiteral("xpBar"));
        xpBar->setGeometry(QRect(490, 70, 401, 41));
        sizePolicy.setHeightForWidth(xpBar->sizePolicy().hasHeightForWidth());
        xpBar->setSizePolicy(sizePolicy);
        xpBar->setValue(0);
        xpBar->setTextVisible(false);
        xpBar->setTextDirection(QProgressBar::TopToBottom);
        charNameLabel = new QLabel(centralWidget);
        charNameLabel->setObjectName(QStringLiteral("charNameLabel"));
        charNameLabel->setGeometry(QRect(160, 60, 71, 31));
        charNameLabel->setFont(font2);
        charNameLabel->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        charNameLabel->setAlignment(Qt::AlignCenter);
        levelNumber = new QLabel(centralWidget);
        levelNumber->setObjectName(QStringLiteral("levelNumber"));
        levelNumber->setGeometry(QRect(20, 50, 81, 101));
        QFont font3;
        font3.setFamily(QStringLiteral("Adobe Arabic"));
        font3.setPointSize(64);
        font3.setBold(true);
        font3.setWeight(75);
        levelNumber->setFont(font3);
        levelNumber->setStyleSheet(QStringLiteral("color: rgb(231, 199, 34);"));
        levelNumber->setAlignment(Qt::AlignCenter);
        healthLabel = new QLabel(centralWidget);
        healthLabel->setObjectName(QStringLiteral("healthLabel"));
        healthLabel->setGeometry(QRect(490, 20, 81, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Adobe Arabic"));
        font4.setPointSize(26);
        font4.setBold(true);
        font4.setWeight(75);
        healthLabel->setFont(font4);
        healthLabel->setAlignment(Qt::AlignCenter);
        specialBar = new QProgressBar(centralWidget);
        specialBar->setObjectName(QStringLiteral("specialBar"));
        specialBar->setGeometry(QRect(490, 130, 401, 41));
        sizePolicy.setHeightForWidth(specialBar->sizePolicy().hasHeightForWidth());
        specialBar->setSizePolicy(sizePolicy);
        specialBar->setValue(0);
        specialBar->setTextVisible(false);
        specialBar->setTextDirection(QProgressBar::TopToBottom);
        specialLabel = new QLabel(centralWidget);
        specialLabel->setObjectName(QStringLiteral("specialLabel"));
        specialLabel->setGeometry(QRect(490, 130, 401, 41));
        specialLabel->setFont(font);
        specialLabel->setAlignment(Qt::AlignCenter);
        levelLabel = new QLabel(centralWidget);
        levelLabel->setObjectName(QStringLiteral("levelLabel"));
        levelLabel->setGeometry(QRect(30, 50, 61, 21));
        levelLabel->setFont(font1);
        levelLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        levelLabel->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 150, 131, 23));
        MainWindow->setCentralWidget(centralWidget);
        bgGraphic->raise();
        healthBar->raise();
        attackArmorFrame->raise();
        charName->raise();
        critSpeedFrame->raise();
        xpBar->raise();
        charNameLabel->raise();
        levelNumber->raise();
        healthLabel->raise();
        xpCurrentNumber->raise();
        xpLabel->raise();
        xpNextLvlNumber->raise();
        specialBar->raise();
        specialLabel->raise();
        levelLabel->raise();
        pushButton->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        bgGraphic->setText(QString());
        xpLabel->setText(QApplication::translate("MainWindow", "XP", 0));
        attackLabel->setText(QApplication::translate("MainWindow", "ATTACK:", 0));
        armorLabel->setText(QApplication::translate("MainWindow", "ARMOR:", 0));
        attackNumber->setText(QApplication::translate("MainWindow", "99", 0));
        armorNumber->setText(QApplication::translate("MainWindow", "99", 0));
        charName->setText(QApplication::translate("MainWindow", "Intrepid Explorer", 0));
        xpNextLvlNumber->setText(QApplication::translate("MainWindow", "/100", 0));
        critLabel->setText(QApplication::translate("MainWindow", "CRIT%:", 0));
        speedLabel->setText(QApplication::translate("MainWindow", "SPEED:", 0));
        critNumber->setText(QApplication::translate("MainWindow", "99", 0));
        speedNumber->setText(QApplication::translate("MainWindow", "99", 0));
        xpCurrentNumber->setText(QApplication::translate("MainWindow", "38", 0));
#ifndef QT_NO_ACCESSIBILITY
        xpBar->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        charNameLabel->setText(QApplication::translate("MainWindow", "NAME :", 0));
        levelNumber->setText(QApplication::translate("MainWindow", "99", 0));
        healthLabel->setText(QApplication::translate("MainWindow", "Health", 0));
#ifndef QT_NO_ACCESSIBILITY
        specialBar->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        specialLabel->setText(QApplication::translate("MainWindow", "Special Attack", 0));
        levelLabel->setText(QApplication::translate("MainWindow", "LEVEL", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Test Button", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
