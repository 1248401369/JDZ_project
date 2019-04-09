#ifndef AIV_PHASEPATTERNGENERATOR_H
#define AIV_PHASEPATTERNGENERATOR_H
#include<opencv2/opencv.hpp>
#include<vector>
#include<qdebug.h>
class AIV_PhasePatternGenerator {
private:
	int Image_number;//�����λ��ͼ������
	int Image_rows, Image_cols;//�����λ��ͼ����������
	int Pattern_1strow, Pattern_1stcol;//��λ��������ʼ����
	int Pattern_rows, Pattern_cols;//��λ������������
	int period_lines;//һ��������λ��ռ�����л�����
	int Mark_1strow, Mark_1stcol;//��־�������ʼ����
	int Mark_rows, Mark_cols;//��־�����������
	float OriginalPhaseShift;//��ʼ����
	bool _withmark;
public:
	AIV_PhasePatternGenerator(const int para[13],const float para_OPs);
	~AIV_PhasePatternGenerator();
	void generate();
	std::vector<cv::Mat> ppgImages;

};

#endif
#pragma once
