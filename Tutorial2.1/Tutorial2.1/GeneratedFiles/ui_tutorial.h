/********************************************************************************
** Form generated from reading UI file 'tutorial.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL_H
#define UI_TUTORIAL_H

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

class Ui_TutorialClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TutorialClass)
    {
        if (TutorialClass->objectName().isEmpty())
            TutorialClass->setObjectName(QStringLiteral("TutorialClass"));
        TutorialClass->resize(600, 400);
        menuBar = new QMenuBar(TutorialClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TutorialClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TutorialClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TutorialClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TutorialClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TutorialClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TutorialClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TutorialClass->setStatusBar(statusBar);

        retranslateUi(TutorialClass);

        QMetaObject::connectSlotsByName(TutorialClass);
    } // setupUi

    void retranslateUi(QMainWindow *TutorialClass)
    {
        TutorialClass->setWindowTitle(QApplication::translate("TutorialClass", "Tutorial", 0));
    } // retranslateUi

};

namespace Ui {
    class TutorialClass: public Ui_TutorialClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL_H
