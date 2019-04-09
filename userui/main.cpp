#include "userui.h"
#include <QtWidgets/QApplication>
#include <inspectionsystem.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	InspectionSystem w;//定义综合类，处理系统w
	return a.exec();   //主函数将线程交给qt
}
