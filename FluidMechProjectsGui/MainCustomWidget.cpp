#include "MainCustomWidget.h"
#include "../FluidMechanicsProjectsDll/REE/radialEquilibriumEquationSolverData.h"
#include <QtWidgets/qboxlayout.h>

MainCustomWidget::MainCustomWidget(QWidget *)
{
	init();
	setupLayout();
}

void MainCustomWidget::init()
{
	//Physical Properties Group
	_gammaEdit = new QLineEdit(this);
	_gammaLabel = new QLabel("Gamma [-]",this);
	_gasConstEdit = new QLineEdit(this);
	_gasConstLabel = new QLabel("Gas Constant [?]", this);

	//Buttons and Controls
	_runButton = new QPushButton("&Run",this);
	connectSignals();
} // init 

void MainCustomWidget::setupLayout()
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(_runButton);
	QGroupBox* physicalPropertiesGroupBox = new QGroupBox("Fluid Properties",this);
	QGridLayout* gridLayout = new QGridLayout(this);
	gridLayout->addWidget(_gammaEdit, 0, 1);
	gridLayout->addWidget(_gammaLabel, 0, 0);
	gridLayout->addWidget(_gasConstEdit, 1, 1);
	gridLayout->addWidget(_gasConstLabel, 1, 0);
	physicalPropertiesGroupBox->setLayout(gridLayout);
	mainLayout->addWidget(physicalPropertiesGroupBox);
	
	this->setLayout(mainLayout);
}

void MainCustomWidget::connectSignals()
{
	QObject::connect(_runButton, SIGNAL(clicked()), this, SLOT(onRunButtonClicked()));
	QObject::connect(_gammaEdit, SIGNAL(editingFinished()), this, SLOT(onValueGammaChanged()));
	QObject::connect(_gasConstEdit, SIGNAL(editingFinished()), this, SLOT(onValueGasConstChanged()));
} // connectSignals

void MainCustomWidget::onRunButtonClicked()
{
	updateData();
	_reeSolver.setData(_inputDataMap);
	_reeSolver.runREESolver();
}// onRunButtonClicked

void MainCustomWidget::onValueGasConstChanged()
{//overwrites the value?
	_inputDataMap[REE_GAS_CONSTANT] = _gasConstEdit->text().toLocal8Bit().constData();
}// onValueGasConstChanged

void MainCustomWidget::onValueGammaChanged()
{//overwrites the value... or just adds another one?
	_inputDataMap[REE_PERFECT_GAS_RATIO] = _gammaEdit->text().toLocal8Bit().constData();
}// onValueGammaChanged
