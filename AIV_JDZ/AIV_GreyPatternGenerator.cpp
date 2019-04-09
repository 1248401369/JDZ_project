#include "AIV_GreyPatternGenerator.h"

AIV_GreyPatternGenerator::AIV_GreyPatternGenerator(const int para[13]) {
	Pattern_number = para[0];
	Code_lines = para[1];
	Image_rows = para[2];
	Image_cols = para[3];
	Pattern_1strow = para[4];
	Pattern_1stcol = para[5];
	Pattern_rows = para[6];
	Pattern_cols = para[7];
	Mark_1strow = para[8];
	Mark_1stcol = para[9];
	Mark_rows = para[10];
	Mark_cols = para[11];
	_withmark = para[12];
	generateImage();
}

AIV_GreyPatternGenerator::~AIV_GreyPatternGenerator() {

}

void AIV_GreyPatternGenerator::generateImage() {
	const uchar ImageNumber = 2 * Pattern_number;
	const float CodeLines = Pattern_rows / powf(2.0, Pattern_number);
	std::vector<cv::Mat> images(ImageNumber);
	std::vector<cv::Mat> ROIimages(ImageNumber);
	for (int i = 0; i < ImageNumber; i++)
	{
		images[i] = cv::Mat(Image_rows, Image_cols, CV_8UC1, cv::Scalar(0.0));
		ROIimages[i] = images[i](cv::Rect(Pattern_1stcol, Pattern_1strow, Pattern_cols, Pattern_rows));
	}
	for (int index = 0; index < Pattern_number; index++)
	{
		const int positive_index = 2 * index,
			negative_index = 2 * index + 1;
		for (int y = 0; y < Pattern_rows; y++)
		{
			int value = (int(y * pow(2.0, index) / Pattern_rows + 0.5)) % 2;
			for (int x = 0; x < Pattern_cols; x++)
			{
				//generation equation
				ROIimages[positive_index].at<uchar>(y, x) = 255 * value;
				ROIimages[negative_index].at<uchar>(y, x) = 255 * (1 - value);
			}
		}
	}
	//////draw mark//////
	if (_withmark)
	{
		for (int index = 0; index < ImageNumber; index++)
		{
			for (int y = Mark_1strow; y < Mark_1strow + Mark_rows; y++)
			{
				for (int x = Mark_1stcol; x < Mark_1stcol + Mark_cols; x++)
				{
					images[index].at<uchar>(y, x) = 0;
				}
			}
		}
	}

	cv::Mat saveimage(Image_rows, Image_cols, CV_8UC3, cv::Scalar(255.0, 255.0, 255.0));
	gpgImages.push_back(saveimage.clone());
	for (int index = 0; index < ImageNumber; index++)
	{
		cv::cvtColor(images[index], saveimage, CV_GRAY2BGR);
		gpgImages.push_back(saveimage.clone());
	}
	return;
}
