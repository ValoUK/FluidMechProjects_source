
#ifndef MAINCUSTOMWIDGET_H
#define MAINCUSTOMWIDGET_H

#include "../FluidMechanicsProjectsDll/REE/RadialEquilibriumEquationSolver.h"
#include <string> //std::string
#include <map> //std::map
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QtWidgets/qpushbutton.h>

class MainCustomWidget: public QWidget
{
	Q_OBJECT
public:
	MainCustomWidget(QWidget *parent = 0);

private:
	void init();
	void setupLayout();
	void connectSignals();
	void updateData();

	REESolver _reeSolver;
	QPushButton* _runButton;
	std::map<std::string, std::string> _inputDataMap;
	
	//QLineEdit* _nStationEdit;
	//QLineEdit* _nStreamEdit;
	//QLineEdit* _indexLeEdit;
	//QLineEdit* _indexTeEdit;

	QLineEdit* _gammaEdit;
	QLineEdit* _gasConstEdit;

	QLabel* _gammaLabel;
	QLabel* _gasConstLabel;
	//QLineEdit* _cpEdit;

	public slots:
	void onRunButtonClicked();
	void onValueGammaChanged();
	void onValueGasConstChanged();
};

#endif // MAINCUSTOMWIDGET_H
