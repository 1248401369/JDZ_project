#include"AIV_PhasePatternGenerator.h"

AIV_PhasePatternGenerator::AIV_PhasePatternGenerator(const int para[13],const float paraOPS) {
	Image_number = para[0];
	Image_rows = para[1];
	Image_cols = para[2];
	Pattern_1strow = para[3];
	Pattern_1stcol = para[4];
	Pattern_rows = para[5];
	Pattern_cols = para[6];
	period_lines = para[7];
	Mark_1strow = para[8];
	Mark_1stcol = para[9];
	Mark_rows = para[10];
	Mark_cols = para[11];
	_withmark = para[12];
	OriginalPhaseShift = paraOPS;
	generate();
}
AIV_PhasePatternGenerator::~AIV_PhasePatternGenerator() {

}
void AIV_PhasePatternGenerator::generate() {
	cv::Mat *images = new cv::Mat[Image_number]();
	cv::Mat *ROIimages = new cv::Mat[Image_number]();
	for (int i = 0; i < Image_number; i++)
	{
		images[i] = cv::Mat(Image_rows, Image_cols, CV_8UC3, cv::Scalar(0.0, 0.0, 0.0));
		ROIimages[i] = images[i](cv::Rect(Pattern_1stcol, Pattern_1strow, Pattern_cols, Pattern_rows));
	}

	//draw PhaseCode
	float unit_phase = 2 * CV_PI / period_lines;
	//uchar *pROI;
	for (int i = 0; i < Image_number; i++)
	{
		//pROI = ROIimages[i].data;
		float phaseShift = 2 * CV_PI * i / Image_number + OriginalPhaseShift;
		for (int row = 0; row < Pattern_rows; row++)
		{
			float phase = row % period_lines * unit_phase + phaseShift;
			for (int col = 0; col < Pattern_cols; col++)
			{
				float value = roundf(cosf(phase)*127.5 + 127.5);
				ROIimages[i].at<cv::Vec3b>(row, col) = cv::Vec3b(value, value, value);
			}
		}
	}


	//draw mark
	if (_withmark)
	{
		qDebug() << _withmark;
		for (int i = 0; i < Image_number; i++)
		{
			for (int row = Mark_1strow; row < Mark_1strow + Mark_rows; row++)
			{
				for (int col = Mark_1stcol; col < Mark_1stcol + Mark_cols; col++)
				{
					images[i].at<cv::Vec3b>(row, col) = cv::Vec3b(0, 0, 0);
				}
			}
		}
	}

	for (int i = 0; i < Image_number; i++) {
		ppgImages.push_back(images[i].clone());
	}
	
}