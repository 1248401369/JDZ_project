#include <inspectionsystem.h>
#include <QThread>

InspectionSystem::InspectionSystem()
{
	window = new userui();  //新建userui类指针对象 window
	window->show();         //窗口显示    

	camera = new Camera();  //新建Camera类指针对象camera
	task = new Task(camera);//新建Task类指针对象task
	connectSignal();        //连接各路信号
}

InspectionSystem::~InspectionSystem()//析构函数
{
	
}

void InspectionSystem::connectSignal()
{
	connect(window->ui.pushButton_1, SIGNAL(clicked()), this, SLOT(on_OpenCamera()));             //按钮1与槽函数打开摄像头连接
	connect(camera, SIGNAL(Sig_imageToShow(Mat *)), window, SLOT(on_ShowImage(Mat *)));           //摄像头中的显示信号与显示图片连接
	connect(window->ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_StartProcess()));           //按钮2与槽函数开始处理连接
	connect(camera, SIGNAL(Sig_imageToProcess(Mat *)), task, SLOT(process(Mat *)));               //摄像头发出的处理图像信号与任务线程中处理程序连接
	connect(camera, SIGNAL(Sig_Image_Process_Before(Mat *)), window, SLOT(on_ShowProcessedImage(Mat *)));//发出信号，没到处理的那帧
	connect(task, SIGNAL(Sig_ImageProcess(Mat *)), window, SLOT(on_ShowProcessedImage(Mat *)));   //任务处理完后，会发出信号激活显示函数
	connect(task, SIGNAL(Sig_BubbleInfo(QString)), window, SLOT(on_ShowBubbleInfo(QString )));//任务处理完，发出信号，显示气泡信息
	connect(task, SIGNAL(Sig_LineInfo(QString)), window, SLOT(on_ShowLineInfo(QString))); //任务处理完，发出信号，显示边缘信息
	connect(window->ui.pushButton_3, SIGNAL(clicked()), this, SLOT(on_StopProcess()));            //按钮3与槽函数停止处理连接
	 
}

void InspectionSystem::on_OpenCamera() //打开摄像头
{
	camera->startCamera();
}

void InspectionSystem::on_StartProcess()//开始处理
{
	
	camera->grabimage();
}

void InspectionSystem::on_StopProcess()//停止处理
{
	camera->stopgrabimage();
}
