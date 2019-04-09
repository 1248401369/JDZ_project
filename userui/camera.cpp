#include "camera.h"
#include <QtCore\qtimer.h>
using namespace cv;

VideoCapture capture("4-10.avi");//��ȡ��ƵԴ
int TotalFrame = capture.get(CV_CAP_PROP_FRAME_COUNT);

Camera::Camera() //camera���캯��
{
	stopRun = true; //ֹͣ��־
	isGrabing = false;//ץȥ��־������ûʲô�ã���û�õ�
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
				capture >> frame;//��ȡͼ��֡
				int CurrentFrame = capture.get(CV_CAP_PROP_POS_FRAMES);
				frameshow = frame.clone();//������ȡ��֡
				emit Sig_imageToShow(&frameshow);//�����źţ�������ǩ��ʾ����
				if (a == 1)//����������a��������̵Ĵ�����־λ��a=1��ʱ����a=0������
				{
					frameprocess = frameshow.clone();	//������ʾ֡�����ڴ���
					if (CurrentFrame > 56&& CurrentFrame < 58)
						emit Sig_imageToProcess(&frameprocess);//�����źţ��������
					else
						emit Sig_Image_Process_Before(&frameprocess);//�����źţ���ʾ����֮ǰ��ͼƬ
				}
				msleep(200);//�ȴ�ʱ��Ϊ30ms��ÿ��֡��ԼΪ33֡
				if (CurrentFrame == TotalFrame)
					stopRun = true;
			}
	
		}
	}
}

void Camera::grabimage()//��ʼ����
{
	a = 1;
}

void Camera::stopgrabimage()//ֹͣ����
{
	a = 0;
}

bool Camera::startCamera()  // �����
{
	stopRun = false;
	start();
	return true;
}

bool Camera::stopCamera()   //�ر����
{
	stopRun = true;
	return true;
}