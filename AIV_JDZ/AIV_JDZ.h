#pragma once

#include <QtWidgets/QMainWindow>
#include<opencv2/opencv.hpp>
#include<qdebug.h>
#include<Qstring>
#include<iostream>
#include< QFileDialog>
#include<QDateTime>
#include<qthread.h>
#include "ui_AIV_JDZ.h"
#include "AIV_GreyPatternGenerator.h"
#include "AIV_ChessBoardGenerator.h"
#include "AIV_PhasePatternGenerator.h"

using namespace std;
using namespace cv;


class AIV_JDZ : public QMainWindow
{
	Q_OBJECT

public:
	AIV_JDZ(QWidget *parent = Q_NULLPTR);
private:
	int gpgPara[13];			//gpg��������ã�������Ӣ��
	int cbgPara[12];			//cbg����
	int ppgPara[13];
	float ppgPara_OPS;
	//void GetPara();//��ui��ȡ����
	vector<Mat> gpgImages;
	vector<Mat> cbgImages;
	vector<Mat> ppgImages;
	void Gpg_generateImage();//����GpgͼƬ
	void Gpg_saveImage();//����
	void Cbg_generateImage();
	void Cbg_saveImage();
	void Ppg_generateImage();
	void Ppg_saveImage();
	QString Gpg_dirPath;
	QString Cbg_dirPath;
	QString Ppg_dirPath;
	void gpgInitial();
	void cbgInitial();
	void ppgInitial();
public slots:
	void on_Gpg_generateBtn_clicked();
	void on_Gpg_saveBtn_clicked();
	void on_Cbg_generateBtn_clicked();
	void on_Cbg_saveBtn_clicked();
	void on_Ppg_generateBtn_clicked();
	void on_Ppg_saveBtn_clicked();
	
private:
	Ui::AIV_JDZClass ui;
};
