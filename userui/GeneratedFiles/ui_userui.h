/********************************************************************************
** Form generated from reading UI file 'userui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERUI_H
#define UI_USERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_useruiClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QLabel *label_1;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *useruiClass)
    {
        if (useruiClass->objectName().isEmpty())
            useruiClass->setObjectName(QStringLiteral("useruiClass"));
        useruiClass->resize(1222, 803);
        centralWidget = new QWidget(useruiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(220, 20, 151, 61));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(620, 20, 151, 61));
        label_1 = new QLabel(centralWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(70, 140, 460, 351));
        label_1->setFrameShape(QFrame::Panel);
        label_1->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(570, 140, 460, 351));
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Sunken);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(810, 20, 161, 61));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(580, 550, 231, 181));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(false);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(580, 530, 221, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(850, 560, 301, 25));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(850, 530, 75, 21));
        useruiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(useruiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1222, 23));
        useruiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(useruiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        useruiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(useruiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        useruiClass->setStatusBar(statusBar);

        retranslateUi(useruiClass);

        QMetaObject::connectSlotsByName(useruiClass);
    } // setupUi

    void retranslateUi(QMainWindow *useruiClass)
    {
        useruiClass->setWindowTitle(QApplication::translate("useruiClass", "userui", Q_NULLPTR));
        pushButton_1->setText(QApplication::translate("useruiClass", "\350\275\275\345\205\245\350\247\206\351\242\221", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("useruiClass", "\345\244\204\347\220\206", Q_NULLPTR));
        label_1->setText(QApplication::translate("useruiClass", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("useruiClass", "TextLabel", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("useruiClass", "\346\232\202\345\201\234", Q_NULLPTR));
        label->setText(QApplication::translate("useruiClass", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("useruiClass", "ROI1\346\260\224\346\263\241\344\277\241\346\201\257\357\274\232\345\272\217\345\217\267\357\274\214\351\235\242\347\247\257\357\274\214(\344\270\255\345\277\203\345\235\220\346\240\207)", Q_NULLPTR));
        label_4->setText(QApplication::translate("useruiClass", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("useruiClass", "ROI2\347\272\277\346\256\265\345\256\275\345\272\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class useruiClass: public Ui_useruiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERUI_H
