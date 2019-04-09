#ifndef AIV_CHESSBOARDGENERATOR_H
#define AIV_CHESSBOARDGENERATOR_H
#include<opencv2/opencv.hpp>
#include<vector>

class AIV_ChessBoardGenerator {

private:
	int Image_rows, Image_cols;			// ������̸�ͼ����������
	int Chess_1strow, Chess_1stcol;		// ���̸�������ʼ����
	int Edge_rows, Edge_cols;			// ���̸�߳�
	int Corner_rows, Corner_cols;		// ���̸�ǵ�������				
	int Mark_1strow, Mark_1stcol;		// ��־�������ʼ����
	int Mark_rows, Mark_cols;			// ��־�����������
public:
	std::vector<cv::Mat> cbgImages;                  //���ɵ����̸�ͼƬ
	AIV_ChessBoardGenerator(const int para[12]);
	~AIV_ChessBoardGenerator();
	void generateImages();
};

#endif
#pragma once
