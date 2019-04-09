#ifndef AIV_GREYPATTERNGENERATOR_H
#define AIV_GREYPATTERNGENERATOR_H
#include<opencv2/opencv.hpp>
#include<vector>
#include<qdebug.h>
class AIV_GreyPatternGenerator {

private:
	int Pattern_number;//���������ͼ��ģʽ��������������
	int Image_rows, Image_cols;//���������ͼ����������
	int Pattern_1strow, Pattern_1stcol;//������������ʼ����
	int Pattern_rows, Pattern_cols;//����������������
	int Code_lines;//һ��������ռ�����л�����
	//std::string Image_filename;//ͼ�񱣴���ļ���
	//std::string Table_filename;//��������ļ���
	int Mark_1strow, Mark_1stcol;//��־�������ʼ����
	int Mark_rows, Mark_cols;//��־�����������
	bool _withmark ;
public:
	std::vector<cv::Mat> gpgImages;
	AIV_GreyPatternGenerator(const int[13]);//Pattern_number;Pattern_rows;Pattern_cols;Pattern_1strow;
	                                        //Pattern_1stcol;Image_rows,Image_cols;Code_lines;Mark_rows;Mark_cols
	~AIV_GreyPatternGenerator();

	void generateImage();

	cv::Mat generateTable();
	static bool loadTable(std::vector<unsigned int> &_GreyLineCodeTable, const std::string _filename, const unsigned int _code_number);
};


#endif
#pragma once
