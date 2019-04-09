#include "AIV_ChessBoardGenerator.h"

AIV_ChessBoardGenerator::AIV_ChessBoardGenerator(const int para[12]) {
	Image_rows = para[0];
	Image_cols = para[1];
	Chess_1strow = para[2];
	Chess_1stcol = para[3];
	Edge_rows = para[4];
	Edge_cols = para[5];
	Corner_rows = para[6];
	Corner_cols = para[7];
	Mark_1strow = para[8];
	Mark_1stcol = para[9];
	Mark_rows = para[10];
	Mark_cols = para[11];
	generateImages();

}

AIV_ChessBoardGenerator::~AIV_ChessBoardGenerator() {

}


void AIV_ChessBoardGenerator::generateImages() {
	cv::Mat chessBoard_positive(Image_rows, Image_cols, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::Mat chessBoard_negative(Image_rows, Image_cols, CV_8UC3, cv::Scalar(255, 255, 255));
	int ChessArea_rows = (Corner_rows + 1)*Edge_rows,
		ChessArea_cols = (Corner_cols + 1)*Edge_cols;
	cv::Mat chessROI_positive = chessBoard_positive(cv::Rect(Chess_1stcol, Chess_1strow, ChessArea_cols, ChessArea_rows));
	cv::Mat chessROI_negative = chessBoard_negative(cv::Rect(Chess_1stcol, Chess_1strow, ChessArea_cols, ChessArea_rows));
	//const int size = 50;
	for (int row = 0; row < ChessArea_rows; row++)
	{
		for (int col = 0; col < ChessArea_cols; col++)
		{
			int rownum = row / Edge_rows;
			int colnum = col / Edge_cols;
			if ((rownum + colnum) % 2 == 0)
			{
				chessROI_positive.at<cv::Vec3b>(row, col) = cv::Vec3b(0, 0, 0);
				chessROI_negative.at<cv::Vec3b>(row, col) = cv::Vec3b(255, 255, 255);
			}
			else
			{
				chessROI_positive.at<cv::Vec3b>(row, col) = cv::Vec3b(255, 255, 255);
				chessROI_negative.at<cv::Vec3b>(row, col) = cv::Vec3b(0, 0, 0);
			}
		}
	}

	//std::string filename_positive = filename + "_positive.bmp",
	//	filename_negative = filename + "_negative.bmp";

	 cbgImages.push_back(chessBoard_positive.clone());
	 cbgImages.push_back(chessBoard_negative.clone());
}
