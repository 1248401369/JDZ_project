#ifndef AIV_CHESSBOARDGENERATOR_H
#define AIV_CHESSBOARDGENERATOR_H
#include<opencv2/opencv.hpp>
#include<vector>

class AIV_ChessBoardGenerator {

private:
	int Image_rows, Image_cols;			// 输出棋盘格图案的行列数
	int Chess_1strow, Chess_1stcol;		// 棋盘格区域起始行列
	int Edge_rows, Edge_cols;			// 棋盘格边长
	int Corner_rows, Corner_cols;		// 棋盘格角点行列数				
	int Mark_1strow, Mark_1stcol;		// 标志区域的起始行列
	int Mark_rows, Mark_cols;			// 标志区域的行列数
public:
	std::vector<cv::Mat> cbgImages;                  //生成的棋盘格图片
	AIV_ChessBoardGenerator(const int para[12]);
	~AIV_ChessBoardGenerator();
	void generateImages();
};

#endif
#pragma once
