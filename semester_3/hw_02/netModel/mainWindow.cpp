#include "mainWindow.h"
#include "view.h"
#include "netModel.h"

#include "computers/linuxComputer.h"

#include <QToolBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	createView();
	createToolBar();
	qsrand(0);
	_timer.setInterval(1000);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createToolBar()
{
	_toolBar = new QToolBar(this);
	addToolBar(_toolBar);
	_toolBar->setFloatable(false);
	_toolBar->setMovable(false);
	_toolBar->setAllowedAreas(Qt::TopToolBarArea);

	createActions();
}

void MainWindow::createActions()
{
	_newLinux = _toolBar->addAction(QIcon(":/icons/linux.png"), "Linux");
	_newMac = _toolBar->addAction(QIcon(":/icons/mac.png"), "Mac");
	_newWindows = _toolBar->addAction(QIcon(":/icons/windows.png"), "Windows");
	_newConnection = _toolBar->addAction(QIcon(":/icons/connection.png"), "Connection");
	_start = _toolBar->addAction(QIcon(":/icons/start.png"),"Start");
	_stop = _toolBar->addAction(QIcon(":/icons/stop.png"),"Stop");
	_clear = _toolBar->addAction(QIcon(":/icons/clear.png"), "Clear");

	_newLinux->setCheckable(true);
	_newMac->setCheckable(true);
	_newWindows->setCheckable(true);
	_newConnection->setCheckable(true);
	_stop->setEnabled(false);

	createConnections();
}

void MainWindow::createConnections()
{
	connect(_toolBar, SIGNAL(actionTriggered(QAction*))
			, this, SLOT(handleAction(QAction*)));
	connect(_clear, SIGNAL(triggered()), _model, SLOT(clear()));
	connect(_start, SIGNAL(triggered()), &_timer, SLOT(start()));
	connect(_stop, SIGNAL(triggered()), &_timer, SLOT(stop()));
}

void MainWindow::createView()
{
	_view = new View(this);
	setCentralWidget(_view);

	_model = new NetModel(this);
	_model->setSceneRect(0, 0, 500, 500);
	_view->setScene(_model);
	connect(&_timer, SIGNAL(timeout()), _model, SLOT(nextStep()));
}

void MainWindow::handleAction(QAction *action)
{
	if (action == _newLinux || action == _newMac || action == _newWindows
			|| action == _newConnection) {
		bool checked = action->isChecked();
		_newLinux->setChecked(false);
		_newMac->setChecked(false);
		_newWindows->setChecked(false);
		_newConnection->setChecked(false);
		action->setChecked(checked);
		sendToView(action);
	} else if (action == _start) {
		_newLinux->setEnabled(false);
		_newMac->setEnabled(false);
		_newWindows->setEnabled(false);
		_newConnection->setEnabled(false);
		_clear->setEnabled(false);
		_start->setEnabled(false);
		_stop->setEnabled(true);
	} else if (action == _stop) {
		_newLinux->setEnabled(true);
		_newMac->setEnabled(true);
		_newWindows->setEnabled(true);
		_newConnection->setEnabled(true);
		_clear->setEnabled(true);
		_start->setEnabled(true);
		_stop->setEnabled(false);
	}
}

void MainWindow::sendToView(QAction *action)
{
	if (!action->isChecked()) {
		_view->setDrawMode(View::NoDraw);
		return;
	}

	if (action == _newLinux)
		_view->setDrawMode(View::LinuxDraw);
	else if (action == _newMac)
		_view->setDrawMode(View::MacDraw);
	else if (action == _newWindows)
		_view->setDrawMode(View::WindowsDraw);
	else if (action == _newConnection)
		_view->setDrawMode(View::ConnectionDraw);
}
