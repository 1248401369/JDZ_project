#include "camera.h"
#include <QtCore\qtimer.h>
using namespace cv;

VideoCapture capture("4-10.avi");//获取视频源
int TotalFrame = capture.get(CV_CAP_PROP_FRAME_COUNT);

Camera::Camera() //camera构造函数
{
	stopRun = true; //停止标志
	isGrabing = false;//抓去标志，好像没什么用，我没用到
}

Camera::~Camera()
{
}

void Camera::run()
{
	while (!stopRun)
	{
		if (isGrabing == false)
		{
			while (1)
			{
				capture >> frame;//获取图像帧
				int CurrentFrame = capture.get(CV_CAP_PROP_POS_FRAMES);
				frameshow = frame.clone();//拷贝获取的帧
				emit Sig_imageToShow(&frameshow);//发射信号，触发标签显示函数
				if (a == 1)//在这里我用a代表处理进程的触发标志位，a=1的时候处理，a=0不处理
				{
					frameprocess = frameshow.clone();	//拷贝显示帧，用于处理
					if (CurrentFrame > 56&& CurrentFrame < 58)
						emit Sig_imageToProcess(&frameprocess);//发射信号，激活处理函数
					else
						emit Sig_Image_Process_Before(&frameprocess);//发射信号，显示处理之前的图片
				}
				msleep(200);//等待时间为30ms，每秒帧率约为33帧
				if (CurrentFrame == TotalFrame)
					stopRun = true;
			}
	
		}
	}
}

void Camera::grabimage()//开始处理
{
	a = 1;
}

void Camera::stopgrabimage()//停止处理
{
	a = 0;
}

bool Camera::startCamera()  // 打开相机
{
	stopRun = false;
	start();
	return true;
}

bool Camera::stopCamera()   //关闭相机
{
	stopRun = true;
	return true;
}