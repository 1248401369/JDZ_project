#pragma once
#include <QThread>
#include <camera.h>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<functional>

using namespace cv;
using namespace std;

class Task : public QThread //任务线程
{
	Q_OBJECT

public:
	Task(Camera *cam);//线程构造函数，camera类进行初始化
	~Task();
public slots:
	void process(Mat *image);
public:
	void ROI_Bubble_process(Mat &src, Mat &ROI_Bubble);
	void ROI_Line_process(Mat &src, Mat &ROI_Line);
	void small_roi_process(Mat &src, Mat &ROI_Line, int Canny_threshold,int i);
	void set_smallroi(Mat &src, Mat &ROI_Line);
	void sec_line_process(Mat &src, vector<Point>line1_points, vector<Point>line2_points);
	int DrawLine_color(Mat &src, Vec4f line_para);

public:
	Camera   *cam1;
	Mat     *image;
	Mat *mat_image;


	vector<string>Line_WidthInfo_vec;
	QString BubbleInfo_qstr;
	QString LineInfo_qstr;


signals:
	void Sig_ImageProcess(Mat * image);  //图像处理完毕信号，激活显示函数
	void Sig_BubbleInfo(QString BubbleInfo_qstr);
	void Sig_LineInfo(QString LineInfo_qstr);
};
