/********************************************************************************
** Form generated from reading UI file 'Trader.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRADER_H
#define UI_TRADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TraderClass
{
public:
    QWidget *centralWidget;
    QTextBrowser *textLog;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TraderClass)
    {
        if (TraderClass->objectName().isEmpty())
            TraderClass->setObjectName(QStringLiteral("TraderClass"));
        TraderClass->resize(600, 400);
        centralWidget = new QWidget(TraderClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textLog = new QTextBrowser(centralWidget);
        textLog->setObjectName(QStringLiteral("textLog"));
        textLog->setGeometry(QRect(70, 110, 256, 192));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 10, 75, 23));
        TraderClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TraderClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        TraderClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TraderClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TraderClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TraderClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TraderClass->setStatusBar(statusBar);

        retranslateUi(TraderClass);

        QMetaObject::connectSlotsByName(TraderClass);
    } // setupUi

    void retranslateUi(QMainWindow *TraderClass)
    {
        TraderClass->setWindowTitle(QApplication::translate("TraderClass", "Trader", nullptr));
        pushButton->setText(QApplication::translate("TraderClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TraderClass: public Ui_TraderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRADER_H
