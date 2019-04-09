#pragma once

#include <QtCore\qthread.h>
#include <iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

class Camera : public QThread //camera是Qthread类的派生类，继承方式为公有
{
	Q_OBJECT

public:
	Camera();
	~Camera();
	void run();

public:
	bool isGrabing;
	bool stopRun;
	Mat frameshow;
	Mat frameprocess;
public:
	void grabimage();
	void stopgrabimage();
	Mat frame;
	bool startCamera();
	bool stopCamera();
	int a = 0;

signals:
	void Sig_imageToShow(Mat *image);//显示信号
	void Sig_imageToProcess(Mat *image);//开始处理信号
	void Sig_Image_Process_Before(Mat *frameprocess);
};