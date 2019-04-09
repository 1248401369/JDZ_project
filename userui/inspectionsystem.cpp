#include <inspectionsystem.h>
#include <QThread>

InspectionSystem::InspectionSystem()
{
	window = new userui();  //�½�userui��ָ����� window
	window->show();         //������ʾ    

	camera = new Camera();  //�½�Camera��ָ�����camera
	task = new Task(camera);//�½�Task��ָ�����task
	connectSignal();        //���Ӹ�·�ź�
}

InspectionSystem::~InspectionSystem()//��������
{
	
}

void InspectionSystem::connectSignal()
{
	connect(window->ui.pushButton_1, SIGNAL(clicked()), this, SLOT(on_OpenCamera()));             //��ť1��ۺ���������ͷ����
	connect(camera, SIGNAL(Sig_imageToShow(Mat *)), window, SLOT(on_ShowImage(Mat *)));           //����ͷ�е���ʾ�ź�����ʾͼƬ����
	connect(window->ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_StartProcess()));           //��ť2��ۺ�����ʼ��������
	connect(camera, SIGNAL(Sig_imageToProcess(Mat *)), task, SLOT(process(Mat *)));               //����ͷ�����Ĵ���ͼ���ź��������߳��д����������
	connect(camera, SIGNAL(Sig_Image_Process_Before(Mat *)), window, SLOT(on_ShowProcessedImage(Mat *)));//�����źţ�û���������֡
	connect(task, SIGNAL(Sig_ImageProcess(Mat *)), window, SLOT(on_ShowProcessedImage(Mat *)));   //��������󣬻ᷢ���źż�����ʾ����
	connect(task, SIGNAL(Sig_BubbleInfo(QString)), window, SLOT(on_ShowBubbleInfo(QString )));//�������꣬�����źţ���ʾ������Ϣ
	connect(task, SIGNAL(Sig_LineInfo(QString)), window, SLOT(on_ShowLineInfo(QString))); //�������꣬�����źţ���ʾ��Ե��Ϣ
	connect(window->ui.pushButton_3, SIGNAL(clicked()), this, SLOT(on_StopProcess()));            //��ť3��ۺ���ֹͣ��������
	 
}

void InspectionSystem::on_OpenCamera() //������ͷ
{
	camera->startCamera();
}

void InspectionSystem::on_StartProcess()//��ʼ����
{
	
	camera->grabimage();
}

void InspectionSystem::on_StopProcess()//ֹͣ����
{
	camera->stopgrabimage();
}
