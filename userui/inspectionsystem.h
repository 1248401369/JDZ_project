#pragma once

#include <QObject>
#include <userui.h>
#include "camera.h"
#include <task.h>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

using namespace cv;

class InspectionSystem :public QObject   //本类主要做信号的连接，对摄像头，界面进行控制
{
	Q_OBJECT

public:
	InspectionSystem();
	~InspectionSystem();

public:
	Camera *camera;
	userui *window;
	Task *task;

	void connectSignal();  //连接各种信号

	public slots:
	void on_OpenCamera();  // 按钮打开相机
	void on_StartProcess();//开始处理
	void on_StopProcess(); //停止处理

};