#include <task.h>
#include<iostream>
#include<vector>
using namespace cv;
using namespace std;

Task::Task(Camera *cam)  //将摄像头类对象，传参给Task
{
	cam1 = cam;
}

Task::~Task()
{
}
int start_points[14] = { 0, 0, 35, 0, 70, 0, 105, 0, 140, 0, 175, 0, 210, 0 };//每条线段的起始相对坐标
int Current_roi = 1;   //当前的roi

void Task::process(Mat *image)
{
	Mat src = *image;
	if (src.empty())
		printf("could not load image...\n");
	Mat ROI_Bubble;
	Mat ROI_Line;
	Rect rect1(0, 0, 300, 700);
	Rect rect2(330, 130, 245, 50);
	src(rect1).copyTo(ROI_Bubble);
	src(rect2).copyTo(ROI_Line);//把ROI区域复制出来
	ROI_Bubble_process(src, ROI_Bubble);//ROI1气泡处理
	ROI_Line_process(src, ROI_Line);//ROI边缘处理
	emit Sig_ImageProcess(&src);//发出处理完毕信号，激活userui显示函数
	emit Sig_BubbleInfo(BubbleInfo_qstr);//发出Bubble信息完成信号，激活usweui显示气泡信息
	emit Sig_LineInfo(LineInfo_qstr);//发出边缘信息完成信号，激活usweui显示边缘信息
}

void Task::ROI_Bubble_process(Mat &src, Mat &ROI_Bubble)//气泡处理函数
{
	vector<string>Bubble_Info_vec;//定义每帧中的气泡信息容器
	
	Mat  ROI_Bubble_binary;
	cvtColor(ROI_Bubble, ROI_Bubble, COLOR_BGR2GRAY);//颜色格式转换
	threshold(ROI_Bubble, ROI_Bubble_binary, 210, 255, THRESH_BINARY);//阈值化处理


	Mat k = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	morphologyEx(ROI_Bubble_binary, ROI_Bubble_binary, MORPH_OPEN, k);
	morphologyEx(ROI_Bubble_binary, ROI_Bubble_binary, MORPH_CLOSE, k);  //形态学操作,光滑边缘

	Mat ROI_Bubble_labeled;
	Mat ROI_Bubble_labeled_stats, ROI_Bubble_labeled_centroids;
	int ROI_Bubble_labeled_number = connectedComponentsWithStats(ROI_Bubble_binary, ROI_Bubble_labeled, ROI_Bubble_labeled_stats, ROI_Bubble_labeled_centroids, 8, 4);
	// 连通域处理，得到每个气泡的信息

	int ii = 0;
	int tt = 1;
	for (int i = 1; i<ROI_Bubble_labeled_number; i++)
	{
		Vec2d pt = ROI_Bubble_labeled_centroids.at<Vec2d>(i, 0);
		int x = ROI_Bubble_labeled_stats.at<int>(i, CC_STAT_LEFT);
		int y = ROI_Bubble_labeled_stats.at<int>(i, CC_STAT_TOP);
		int width = ROI_Bubble_labeled_stats.at<int>(i, CC_STAT_WIDTH);
		int height = ROI_Bubble_labeled_stats.at<int>(i, CC_STAT_HEIGHT);//CC_STAT,连通域矩形坐标,长宽
		int area = ROI_Bubble_labeled_stats.at<int>(i, CC_STAT_AREA);//连通域面积
		if (ROI_Bubble_labeled_stats.at<int>(i, CC_STAT_AREA) < 300)//设置气泡面积的最小阈值
		{
			ii++;
			continue;

		}
		circle(src, Point(pt[0], pt[1]), 1, Scalar(0, 0, 255), -1, 8, 0);       //标记连通域中心
		rectangle(src, Rect(x, y, width, height), Scalar(0, 0, 255), 0.5, 8, 0);//标记矩形框
		string str1 = "[" + format("%d", tt) + "," + format("%.3d", ROI_Bubble_labeled_stats.at<int>(i, CC_STAT_AREA)) + "," + "(" + (format("%.f", pt[0])) + "," + format("%.f", pt[1]) + ")" + "]";
		string str2 = format("%d", tt);
		Bubble_Info_vec.push_back(str1);
		Bubble_Info_vec.push_back(string("\n"));//依次存储气泡信息并换行
		Point Point_Bubble_text1(pt[0] + width*0.5, pt[1] - height*0.5);//文本标记位置
		putText(src, str2, Point_Bubble_text1, FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0, 0, 255), 1, 8);//在图片中标记气泡信息
		tt++;
	}
	string sum = accumulate(Bubble_Info_vec.begin(), Bubble_Info_vec.end(), string("\n"));//将每个气泡信息汇总
	BubbleInfo_qstr = QString::fromStdString(sum);//字符串格式转换
}


////-----------------------------直线边缘拟合方法---------------------
void Task::ROI_Line_process(Mat &src, Mat &ROI_Line)//
{
	set_smallroi(src, ROI_Line);
	imwrite("src_roi.jpg", ROI_Line);
}

void Task::set_smallroi(Mat &src, Mat &ROI_Line)// 设置7个小区域函数
{
	//imshow("ROI_Line", ROI_Line);
	vector<string>Line_info;//设置存储每条线段信息的容器
	Mat roi1;
	Mat roi2;
	Mat roi3;
	Mat roi4;
	Mat roi5;
	Mat roi6;
	Mat roi7;
	Rect rect1(0, 0, 35, 50);
	Rect rect2(35, 0, 35, 50);
	Rect rect3(70, 0, 35, 50);
	Rect rect4(105, 0, 35, 50);
	Rect rect5(140, 0, 35, 50);
	Rect rect6(175, 0, 35, 50);
	Rect rect7(210, 0, 35, 50);
	ROI_Line(rect1).copyTo(roi1);
	ROI_Line(rect2).copyTo(roi2);
	ROI_Line(rect3).copyTo(roi3);
	ROI_Line(rect4).copyTo(roi4);
	ROI_Line(rect5).copyTo(roi5);
	ROI_Line(rect6).copyTo(roi6);
	ROI_Line(rect7).copyTo(roi7);
	small_roi_process(src, roi1, 60,1);
	small_roi_process(src, roi2, 50,2);
	small_roi_process(src, roi3, 50,3);
	small_roi_process(src, roi4, 60,4);
	small_roi_process(src, roi5, 50,5);
	small_roi_process(src, roi6, 50,6);
	small_roi_process(src, roi7,30,7);//调用每个小区域的处理函数
	string sun = accumulate(Line_WidthInfo_vec.begin(), Line_WidthInfo_vec.end(), string("\n"));//汇总直线信息
	LineInfo_qstr = QString::fromStdString(sun); //格式转换
	Current_roi = 1;//处理完7个小区域后，进行复位
	Line_WidthInfo_vec.clear();//清空线段存储容器
	imshow("src_processed", src); //330, 130, 245, 50
	imwrite("src_processed.jpg", src);
	Mat imageROI = src(Range(130, 130 + 50),
		Range(330, 330 + 245));
	imshow("imageROI", imageROI);
	imwrite("roi_processed.jpg", imageROI);
}


//------------------------------------小区域处理--------------------------
void Task::small_roi_process(Mat &src, Mat &roi, int Canny_threshold,int i)
{
	string s1 = to_string(i);
	Mat roi_copy(roi.rows,roi.cols,CV_8UC1,Scalar::all(0));
	//imshow("roi_"+s1, roi);
	imwrite("roi_"+s1+".jpg", roi);
	GaussianBlur(roi, roi, Size(3, 3), 0, 0, BORDER_DEFAULT);// 高斯滤波，去除噪声

	Mat roi_canny;

	cvtColor(roi, roi, COLOR_BGR2GRAY);
	//imshow("roi_gaus_"+s1, roi);
	imwrite("roi_gauss_"+s1+".jpg", roi);

	Canny(roi, roi_canny, 0.4*Canny_threshold, Canny_threshold);//Canny提取划痕边缘
	//imshow("roi_canny_"+s1, roi_canny);
	imwrite("roi_canny_"+s1+".jpg", roi_canny);

	Mat kk0 = getStructuringElement(MORPH_RECT, Size(1, 2));
	erode(roi_canny, roi_canny, kk0, Point(-1, -1), 2);// 设置竖的结构元，腐蚀掉水平线段

	Mat kk = getStructuringElement(MORPH_RECT, Size(1, 2));
	dilate(roi_canny, roi_canny, kk, Point(-1, -1), 8);// 设置竖的结构元，膨胀联通边缘线段，
	//imshow("erode_dilate_roi_"+s1, roi_canny);
	imwrite("erode_dilate_roi_"+s1+".jpg", roi_canny);


	Mat roi_labeled_stats;             //定义连通域信息数组
	Mat roi_labeled_centroids;         //定义连通域中心坐标
	Mat roi_labeled;                   //标记出来的连通域图像
	Mat roi_temp = Mat::zeros(roi.size(), CV_8U);

	int roi_labeled_number = connectedComponentsWithStats(roi_canny, roi_labeled, roi_labeled_stats, roi_labeled_centroids, 8, 4);//连通域处理
	//imshow("roi_labeled_"+s1, roi_labeled);
	imwrite("roi_labeled_"+s1+".jpg", roi_labeled);
	vector<int>label_area_vec;
	for (int a = 1; a <roi_labeled_number; a++)
	{
		if (roi_labeled_stats.at<int>(a, CC_STAT_AREA) >25)//连通域阈值
			label_area_vec.push_back(roi_labeled_stats.at<int>(a, CC_STAT_AREA));
	}                             //记录连通域面积

	vector<Point>roi_line1_pointdata_vec;
	vector<Point>roi_line2_pointdata_vec;
	int roi_linenumber = 1;
	if (label_area_vec.size() >= 2)
	{
		int a0, a1;
		//printf("Current_roi:%d\n", Current_roi);
		sort(label_area_vec.begin(), label_area_vec.end(), greater<int>());
		int p0 = label_area_vec[0];
		int p1 = label_area_vec[1];
		//printf("p1:%d,p0:%d\n", p1, p0);
		int i = 1;
		for (int a = 0; a <roi_labeled_number; a++)
		{

			if (p0 != p1)
			{
				if (roi_labeled_stats.at<int>(a, CC_STAT_AREA) == p0)
					a0 = a;
				if (roi_labeled_stats.at<int>(a, CC_STAT_AREA) == p1)
					a1 = a;
			}
			else
			{
				if (roi_labeled_stats.at<int>(a, CC_STAT_AREA) == p0 && i == 1)
				{
					a0 = a;
					i = 0;
				}
				if (roi_labeled_stats.at<int>(a, CC_STAT_AREA) == p1)
					a1 = a;
			}
		}
		for (int i = 0; i < roi_labeled.rows; i++)
		{
			for (int j = 0; j < roi_labeled.cols; j++)
			{
				if (roi_labeled.at<int>(i, j) == a0) {
					roi_line1_pointdata_vec.push_back(Point(i, j));
					roi_copy.at<uchar>(i, j) = 255;
				}
				if (roi_labeled.at<int>(i, j) == a1) {
					roi_line2_pointdata_vec.push_back(Point(i, j));
					roi_copy.at<uchar>(i, j) = 255;
				}
					
			}
		}
		sec_line_process(src, roi_line1_pointdata_vec, roi_line2_pointdata_vec);//二次处理，用两个直线的夹角判断
		Current_roi++;
	}
	else
	{
		string str0 = "0 ,";
		Line_WidthInfo_vec.push_back(str0);
		Current_roi++;
	}//如果检测出符合条件的区域小于2个，则置0
	imwrite("roi_twoMax_line"+s1+".jpg", roi_copy);
}

void Task::sec_line_process(Mat &src, vector<Point>line1_points, vector<Point>line2_points)//第二次处理函数
{
	Vec4f line1_para;
	Vec4f line2_para;//直线信息变量
	fitLine(line1_points, line1_para, DIST_L1, 0, 0.01, 0.01);
	fitLine(line2_points, line2_para, DIST_L1, 0, 0.01, 0.01);//最小二乘拟合
	double theta1 = atan2(line1_para[1], line1_para[0]) * 180;//直线1角度
	double theta2 = atan2(line2_para[1], line2_para[0]) * 180;//直线2角度
	double theta = abs(theta1 - theta2);
	int aa;
	if (theta>15)//如果两条直线的家教大于20则边缘算作未检测出,线宽置0
		aa = 0;
	else
	     aa = abs(DrawLine_color(src, line2_para) - DrawLine_color(src, line1_para));
	string str1 = format("%d", aa) + " ,";
	Line_WidthInfo_vec.push_back(str1);//存储每条直线的信息
}

//-------------------------------------标线函数--------------------------------------------
int Task::DrawLine_color(Mat &src, Vec4f line_para) //输入被标记图像，直线信息
{
	int rect_x = 330;
	int rect_y = 123;//ROI2相对坐标

	Point pointxy(Point(rect_x, rect_y) + Point(start_points[2 * Current_roi - 2], start_points[2 * Current_roi - 1]));
	Point point0, point1, point2,point3;
	point0.x = line_para[3];
	point0.y = line_para[2];
	double kk = line_para[0] / line_para[1];//直线斜率
	point1.y = 0;
	point1.x = 1 / kk * (point1.y - point0.y) + point0.x;//直线起点
	point2.y = 50;
	point2.x = 1 / kk * (point2.y - point0.y) + point0.x;//直线终点
	point3.y = 25;
	point3.x = 1 / kk * (point3.y - point0.y) + point0.x;//线段中点坐标,用于计算宽度
	line(src, point1 + pointxy, point2 + pointxy, Scalar(0, 0, 255), 1, 8, 0);//作图
	return point3.x;
}