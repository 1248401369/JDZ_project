#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_myMainWindow.h"

class myMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	myMainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::myMainWindowClass ui;
};
