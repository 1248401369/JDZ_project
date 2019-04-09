#pragma once

#include <QtCore\qthread.h>
#include <iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

class Camera : public QThread //camera��Qthread��������࣬�̳з�ʽΪ����
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
	void Sig_imageToShow(Mat *image);//��ʾ�ź�
	void Sig_imageToProcess(Mat *image);//��ʼ�����ź�
	void Sig_Image_Process_Before(Mat *frameprocess);
};