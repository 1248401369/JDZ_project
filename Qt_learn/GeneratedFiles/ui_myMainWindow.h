/********************************************************************************
** Form generated from reading UI file 'myMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAINWINDOW_H
#define UI_MYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myMainWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *myMainWindowClass)
    {
        if (myMainWindowClass->objectName().isEmpty())
            myMainWindowClass->setObjectName(QStringLiteral("myMainWindowClass"));
        myMainWindowClass->resize(600, 400);
        menuBar = new QMenuBar(myMainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        myMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(myMainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        myMainWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(myMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        myMainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(myMainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        myMainWindowClass->setStatusBar(statusBar);

        retranslateUi(myMainWindowClass);

        QMetaObject::connectSlotsByName(myMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *myMainWindowClass)
    {
        myMainWindowClass->setWindowTitle(QApplication::translate("myMainWindowClass", "myMainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class myMainWindowClass: public Ui_myMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWINDOW_H
