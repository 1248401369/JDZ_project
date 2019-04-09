#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <csignal>
#include <windows.h>

using namespace std;

void signalHandler(int signum)
{
	qDebug() << "Receiv signal (------------------------" << signum << ").";
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	signal(SIGINT, signalHandler);
	while (1) {
		qDebug() << "Go to sleep...";
		Sleep(1);
	}
	return a.exec();
}
