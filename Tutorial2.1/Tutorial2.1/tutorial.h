#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <QtWidgets/QMainWindow>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include "ui_tutorial.h"

class Tutorial : public QMainWindow
{
	Q_OBJECT

public:
	Tutorial(QWidget *parent = 0);
	~Tutorial();

	void createCenteralWidget();
	void createActions();
	void createMenus();
    void createToolBars();

public slots:
	 void openFile();


private:
	QLabel *label;
	QAction *m_pActionOpenFile;
	QToolBar *m_pToolBarOpenFile;
};

#endif // TUTORIAL_H
