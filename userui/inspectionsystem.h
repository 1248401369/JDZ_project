#pragma once

#include <QObject>
#include <userui.h>
#include "camera.h"
#include <task.h>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

using namespace cv;

class InspectionSystem :public QObject   //������Ҫ���źŵ����ӣ�������ͷ��������п���
{
	Q_OBJECT

public:
	InspectionSystem();
	~InspectionSystem();

public:
	Camera *camera;
	userui *window;
	Task *task;

	void connectSignal();  //���Ӹ����ź�

	public slots:
	void on_OpenCamera();  // ��ť�����
	void on_StartProcess();//��ʼ����
	void on_StopProcess(); //ֹͣ����

};