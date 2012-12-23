#pragma once

#include <QtGui/QMainWindow>
#include <QTimer>

class QToolBar;
class QAction;
class View;
class NetModel;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	/** Inform the _view about action and enable/disable _toolBar actions */
	void handleAction(QAction *action);

private:
	void createToolBar();
	void createActions();
	void createConnections();
	void createView();
	/** Sends information about new computers or connections to draw */
	void sendToView(QAction *action);

	QToolBar *_toolBar;

	QAction *_newLinux;
	QAction *_newMac;
	QAction *_newWindows;
	QAction *_newConnection;
	QAction *_start;
	QAction *_stop;
	QAction *_clear;

	View *_view;
	NetModel *_model;

	QTimer _timer;
};
