#include"image_Process_JDZ.h"

void twoImageToOneImage(Mat &Dst, Mat src, Point start_point) {//把src复制进Dst，Start为起点坐标
	Mat roi = Dst(Rect(int(start_point.x),int(start_point.y), src.cols, src.rows));
	Mat mask(roi.rows, roi.cols, roi.depth(), Scalar(1));
	src.copyTo(roi, mask);
}