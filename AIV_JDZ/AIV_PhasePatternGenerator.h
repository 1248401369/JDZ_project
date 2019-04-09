#ifndef AIV_PHASEPATTERNGENERATOR_H
#define AIV_PHASEPATTERNGENERATOR_H
#include<opencv2/opencv.hpp>
#include<vector>
#include<qdebug.h>
class AIV_PhasePatternGenerator {
private:
	int Image_number;//输出相位码图案张数
	int Image_rows, Image_cols;//输出相位码图案的行列数
	int Pattern_1strow, Pattern_1stcol;//相位码区域起始行列
	int Pattern_rows, Pattern_cols;//相位码区域行列数
	int period_lines;//一个周期相位码占像素行或列数
	int Mark_1strow, Mark_1stcol;//标志区域的起始行列
	int Mark_rows, Mark_cols;//标志区域的行列数
	float OriginalPhaseShift;//初始相移
	bool _withmark;
public:
	AIV_PhasePatternGenerator(const int para[13],const float para_OPs);
	~AIV_PhasePatternGenerator();
	void generate();
	std::vector<cv::Mat> ppgImages;

};

#endif
#pragma once
