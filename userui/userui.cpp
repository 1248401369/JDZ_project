#include "userui.h"

userui::userui()
{
	ui.setupUi(this);
}

userui::~userui()
{

}

void userui::on_ShowImage(Mat *image)
{
	Mat frame = *image;     //����������imageָ���е�ͼ�񣬿�����frame
	cvtColor(frame, frame, CV_BGR2GRAY); // Mat תΪQImageʱ ���ȱ��� ��bgrתΪrgb 
	QImage src = QImage((const unsigned char*)(frame.data), frame.cols, frame.rows, frame.cols*frame.channels(), QImage::Format_Grayscale8);//Mat תΪ Qimage
	QImage resultImg = src.scaled(ui.label_1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//ͼƬ����Ӧ��ǩ��С���ȱ�������
	ui.label_1->setPixmap(QPixmap::fromImage(resultImg));
	ui.label_1->show();
}


void userui::on_ShowProcessedImage(Mat *image)
{
	Mat frame = *image;
	cvtColor(frame, frame, CV_BGR2RGB); 
	QImage src = QImage((const unsigned char*)(frame.data), frame.cols, frame.rows, frame.cols*frame.channels(), QImage::Format_RGB888);
	QImage resultImg = src.scaled(ui.label_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	ui.label_2->setPixmap(QPixmap::fromImage(resultImg));
	ui.label_2->show();
}
void userui::on_ShowBubbleInfo(QString bubbleinfo)
{
	ui.label->setText(bubbleinfo);
}
void userui::on_ShowLineInfo(QString lineinfo)
{
	ui.label_4->setText(lineinfo);
}
