#include "image_Process_JDZ.h"

int main() {
	string s1 = "../userui/roi_gauss_";
	string s2 = "../userui/roi_canny_";
	string s3 = "../userui/erode_dilate_roi_";
	string s4 = "../userui/roi_twoMax_line";
	string s = "../userui/src_roi.jpg";
	Mat Dst = imread(s);
	Mat roi_gauss;
	Mat roi_canny;
	Mat roi_erode_dilate;
	Mat roi_twoMax_line;
	Dst.copyTo(roi_gauss);
	Dst.copyTo(roi_canny);
	Dst.copyTo(roi_erode_dilate);
	Dst.copyTo(roi_twoMax_line);
	for (int i = 0; i < 7; ++i) {
		//Mat src1 = imread("../userui/roi_gauss_"+to_string(i+1)+".jpg");
		//Mat src2 = imread("../userui/roi_canny_" + to_string(i + 1) + ".jpg");
		//Mat src3 = imread("../userui/erode_dilate_roi_" + to_string(i + 1) + ".jpg");
		/*Mat src4 = imread("../userui/roi_twoMax_line" + to_string(i + 1) + ".jpg");*/
		//twoImageToOneImage(roi_gauss, src1, Point(35*i, 0));
		//twoImageToOneImage(roi_canny, src2, Point(35 * i, 0));
		//twoImageToOneImage(roi_erode_dilate, src3, Point(35 * i, 0));
		/*twoImageToOneImage(roi_twoMax_line, src4, Point(35 * i, 0));*/
	}
	//imshow("roi_gauss", roi_gauss);
	//imwrite("roi_gauss.jpg", roi_gauss);
	//imshow("roi_canny", roi_canny);
	//imwrite("roi_canny.jpg", roi_canny);
	//imshow("roi_erode_dilate", roi_erode_dilate);
	//imwrite("roi_erode_dilate.jpg", roi_erode_dilate);
	imshow("roi_twoMax_line", roi_twoMax_line);
	imwrite("roi_twoMax_line.jpg", roi_twoMax_line);
	waitKey(0);
	return 0;
}