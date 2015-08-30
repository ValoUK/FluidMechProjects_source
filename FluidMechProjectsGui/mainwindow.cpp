#include "mainwindow.h"
#include "MainCustomWidget.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent)
{
	this->resize(600, 300);
	init();
}

void MainWindow::init()
{
	_centralWidget = new MainCustomWidget(); /*QWidget(this);*/
	this->setCentralWidget(_centralWidget); //ownership passed

} //init

MainWindow::~MainWindow()
{
}
