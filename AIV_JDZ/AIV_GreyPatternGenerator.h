#ifndef AIV_GREYPATTERNGENERATOR_H
#define AIV_GREYPATTERNGENERATOR_H
#include<opencv2/opencv.hpp>
#include<vector>
#include<qdebug.h>
class AIV_GreyPatternGenerator {

private:
	int Pattern_number;//输出格雷码图案模式数，不包含正反
	int Image_rows, Image_cols;//输出格雷码图案的行列数
	int Pattern_1strow, Pattern_1stcol;//格雷码区域起始行列
	int Pattern_rows, Pattern_cols;//格雷码区域行列数
	int Code_lines;//一个格雷码占像素行或列数
	//std::string Image_filename;//图像保存的文件名
	//std::string Table_filename;//表单保存的文件名
	int Mark_1strow, Mark_1stcol;//标志区域的起始行列
	int Mark_rows, Mark_cols;//标志区域的行列数
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
