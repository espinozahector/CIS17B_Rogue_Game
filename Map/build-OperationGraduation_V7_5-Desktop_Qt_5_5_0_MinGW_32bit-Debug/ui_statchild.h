/********************************************************************************
** Form generated from reading UI file 'statchild.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATCHILD_H
#define UI_STATCHILD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMdiSubWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatChild
{
public:
    QWidget *centralWidget;
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

    void setupUi(QMdiSubWindow *StatChild)
    {
        if (StatChild->objectName().isEmpty())
            StatChild->setObjectName(QStringLiteral("StatChild"));
        StatChild->resize(900, 170);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StatChild->sizePolicy().hasHeightForWidth());
        StatChild->setSizePolicy(sizePolicy);
        StatChild->setMinimumSize(QSize(900, 170));
        StatChild->setMaximumSize(QSize(900, 170));
        StatChild->setFocusPolicy(Qt::ClickFocus);
        StatChild->setAutoFillBackground(false);
        StatChild->setProperty("animated", QVariant(false));
        StatChild->setProperty("documentMode", QVariant(false));
        StatChild->setProperty("unifiedTitleAndToolBarOnMac", QVariant(false));
        centralWidget = new QWidget(StatChild);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setGeometry(QRect(0, 0, 900, 150));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        xpLabel = new QLabel(centralWidget);
        xpLabel->setObjectName(QStringLiteral("xpLabel"));
        xpLabel->setGeometry(QRect(570, 50, 81, 41));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        xpLabel->setFont(font);
        xpLabel->setAlignment(Qt::AlignCenter);
        healthBar = new QProgressBar(centralWidget);
        healthBar->setObjectName(QStringLiteral("healthBar"));
        healthBar->setGeometry(QRect(130, 10, 761, 31));
        sizePolicy1.setHeightForWidth(healthBar->sizePolicy().hasHeightForWidth());
        healthBar->setSizePolicy(sizePolicy1);
        healthBar->setValue(0);
        healthBar->setTextVisible(false);
        attackArmorFrame = new QFrame(centralWidget);
        attackArmorFrame->setObjectName(QStringLiteral("attackArmorFrame"));
        attackArmorFrame->setGeometry(QRect(150, 80, 161, 61));
        attackArmorFrame->setStyleSheet(QStringLiteral(""));
        attackArmorFrame->setFrameShape(QFrame::WinPanel);
        attackArmorFrame->setFrameShadow(QFrame::Sunken);
        attackArmorFrame->setLineWidth(0);
        attackArmorFrame->setMidLineWidth(0);
        attackLabel = new QLabel(attackArmorFrame);
        attackLabel->setObjectName(QStringLiteral("attackLabel"));
        attackLabel->setGeometry(QRect(10, 10, 91, 21));
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
        armorLabel->setGeometry(QRect(10, 37, 91, 20));
        armorLabel->setFont(font1);
        armorLabel->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        armorLabel->setAlignment(Qt::AlignCenter);
        attackNumber = new QLabel(attackArmorFrame);
        attackNumber->setObjectName(QStringLiteral("attackNumber"));
        attackNumber->setGeometry(QRect(110, 10, 41, 21));
        attackNumber->setFont(font1);
        attackNumber->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 0, 0);"));
        attackNumber->setAlignment(Qt::AlignCenter);
        armorNumber = new QLabel(attackArmorFrame);
        armorNumber->setObjectName(QStringLiteral("armorNumber"));
        armorNumber->setGeometry(QRect(110, 37, 41, 21));
        armorNumber->setFont(font1);
        armorNumber->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 255);"));
        armorNumber->setAlignment(Qt::AlignCenter);
        charName = new QLabel(centralWidget);
        charName->setObjectName(QStringLiteral("charName"));
        charName->setGeometry(QRect(240, 48, 241, 30));
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
        xpNextLvlNumber->setGeometry(QRect(720, 50, 91, 41));
        xpNextLvlNumber->setFont(font);
        xpNextLvlNumber->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        critSpeedFrame = new QFrame(centralWidget);
        critSpeedFrame->setObjectName(QStringLiteral("critSpeedFrame"));
        critSpeedFrame->setGeometry(QRect(320, 80, 161, 61));
        critSpeedFrame->setStyleSheet(QStringLiteral(""));
        critSpeedFrame->setFrameShape(QFrame::WinPanel);
        critSpeedFrame->setFrameShadow(QFrame::Sunken);
        critSpeedFrame->setLineWidth(0);
        critSpeedFrame->setMidLineWidth(0);
        critLabel = new QLabel(critSpeedFrame);
        critLabel->setObjectName(QStringLiteral("critLabel"));
        critLabel->setGeometry(QRect(10, 10, 81, 20));
        critLabel->setFont(font1);
        critLabel->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        critLabel->setAlignment(Qt::AlignCenter);
        speedLabel = new QLabel(critSpeedFrame);
        speedLabel->setObjectName(QStringLiteral("speedLabel"));
        speedLabel->setGeometry(QRect(10, 40, 81, 16));
        speedLabel->setFont(font1);
        speedLabel->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        speedLabel->setAlignment(Qt::AlignCenter);
        critNumber = new QLabel(critSpeedFrame);
        critNumber->setObjectName(QStringLiteral("critNumber"));
        critNumber->setGeometry(QRect(100, 10, 41, 16));
        critNumber->setFont(font1);
        critNumber->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(183, 1, 255);"));
        critNumber->setAlignment(Qt::AlignCenter);
        speedNumber = new QLabel(critSpeedFrame);
        speedNumber->setObjectName(QStringLiteral("speedNumber"));
        speedNumber->setGeometry(QRect(100, 40, 41, 16));
        speedNumber->setFont(font1);
        speedNumber->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        speedNumber->setAlignment(Qt::AlignCenter);
        xpCurrentNumber = new QLabel(centralWidget);
        xpCurrentNumber->setObjectName(QStringLiteral("xpCurrentNumber"));
        xpCurrentNumber->setGeometry(QRect(640, 50, 81, 41));
        xpCurrentNumber->setFont(font);
        xpCurrentNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        xpBar = new QProgressBar(centralWidget);
        xpBar->setObjectName(QStringLiteral("xpBar"));
        xpBar->setGeometry(QRect(490, 50, 401, 41));
        sizePolicy1.setHeightForWidth(xpBar->sizePolicy().hasHeightForWidth());
        xpBar->setSizePolicy(sizePolicy1);
        xpBar->setValue(0);
        xpBar->setTextVisible(false);
        xpBar->setTextDirection(QProgressBar::TopToBottom);
        charNameLabel = new QLabel(centralWidget);
        charNameLabel->setObjectName(QStringLiteral("charNameLabel"));
        charNameLabel->setGeometry(QRect(130, 50, 101, 21));
        charNameLabel->setFont(font2);
        charNameLabel->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        charNameLabel->setAlignment(Qt::AlignCenter);
        levelNumber = new QLabel(centralWidget);
        levelNumber->setObjectName(QStringLiteral("levelNumber"));
        levelNumber->setGeometry(QRect(10, 20, 101, 101));
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
        healthLabel->setGeometry(QRect(430, 10, 141, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Adobe Arabic"));
        font4.setPointSize(26);
        font4.setBold(true);
        font4.setWeight(75);
        healthLabel->setFont(font4);
        healthLabel->setAlignment(Qt::AlignCenter);
        specialBar = new QProgressBar(centralWidget);
        specialBar->setObjectName(QStringLiteral("specialBar"));
        specialBar->setGeometry(QRect(490, 100, 401, 41));
        sizePolicy1.setHeightForWidth(specialBar->sizePolicy().hasHeightForWidth());
        specialBar->setSizePolicy(sizePolicy1);
        specialBar->setValue(0);
        specialBar->setTextVisible(false);
        specialBar->setTextDirection(QProgressBar::TopToBottom);
        specialLabel = new QLabel(centralWidget);
        specialLabel->setObjectName(QStringLiteral("specialLabel"));
        specialLabel->setGeometry(QRect(490, 100, 401, 41));
        specialLabel->setFont(font);
        specialLabel->setAlignment(Qt::AlignCenter);
        levelLabel = new QLabel(centralWidget);
        levelLabel->setObjectName(QStringLiteral("levelLabel"));
        levelLabel->setGeometry(QRect(20, 10, 61, 21));
        levelLabel->setFont(font1);
        levelLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        levelLabel->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 120, 131, 23));
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

        retranslateUi(StatChild);

        QMetaObject::connectSlotsByName(StatChild);
    } // setupUi

    void retranslateUi(QMdiSubWindow *StatChild)
    {
        StatChild->setWindowTitle(QString());
        xpLabel->setText(QApplication::translate("StatChild", "XP", 0));
        attackLabel->setText(QApplication::translate("StatChild", "ATTACK:", 0));
        armorLabel->setText(QApplication::translate("StatChild", "ARMOR:", 0));
        attackNumber->setText(QApplication::translate("StatChild", "99", 0));
        armorNumber->setText(QApplication::translate("StatChild", "99", 0));
        charName->setText(QApplication::translate("StatChild", "Intrepid Explorer", 0));
        xpNextLvlNumber->setText(QApplication::translate("StatChild", "/100", 0));
        critLabel->setText(QApplication::translate("StatChild", "CRIT%:", 0));
        speedLabel->setText(QApplication::translate("StatChild", "SPEED:", 0));
        critNumber->setText(QApplication::translate("StatChild", "99", 0));
        speedNumber->setText(QApplication::translate("StatChild", "99", 0));
        xpCurrentNumber->setText(QApplication::translate("StatChild", "38", 0));
#ifndef QT_NO_ACCESSIBILITY
        xpBar->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        charNameLabel->setText(QApplication::translate("StatChild", "NAME :", 0));
        levelNumber->setText(QApplication::translate("StatChild", "99", 0));
        healthLabel->setText(QApplication::translate("StatChild", "Health", 0));
#ifndef QT_NO_ACCESSIBILITY
        specialBar->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        specialLabel->setText(QApplication::translate("StatChild", "Special Attack", 0));
        levelLabel->setText(QApplication::translate("StatChild", "LEVEL", 0));
        pushButton->setText(QApplication::translate("StatChild", "Test Button", 0));
    } // retranslateUi

};

namespace Ui {
    class StatChild: public Ui_StatChild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATCHILD_H
