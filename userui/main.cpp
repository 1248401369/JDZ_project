#include "userui.h"
#include <QtWidgets/QApplication>
#include <inspectionsystem.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	InspectionSystem w;//�����ۺ��࣬����ϵͳw
	return a.exec();   //���������߳̽���qt
}
