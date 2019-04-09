#ifndef USERUI_H
#define USERUI_H

#include <QtWidgets/QMainWindow>
#include "ui_userui.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

using namespace cv;
class userui : public QMainWindow
{
	Q_OBJECT

public:
	userui();
	~userui();
	Ui::useruiClass ui;
	

public slots:
	void on_ShowImage(Mat *image);            //显示原始画面
	void on_ShowProcessedImage(Mat *image);   //显示处理后的画面
	void on_ShowBubbleInfo(QString bubbleinfo);
	void on_ShowLineInfo(QString lineinfo);
};

#endif // USERUI_H
