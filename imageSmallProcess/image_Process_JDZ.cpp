#include"image_Process_JDZ.h"

void twoImageToOneImage(Mat &Dst, Mat src, Point start_point) {//��src���ƽ�Dst��StartΪ�������
	Mat roi = Dst(Rect(int(start_point.x),int(start_point.y), src.cols, src.rows));
	Mat mask(roi.rows, roi.cols, roi.depth(), Scalar(1));
	src.copyTo(roi, mask);
}