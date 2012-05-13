#include <QtGui/QApplication>
#include <QDeclarativeView>
#include <QDeclarativeEngine>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	QDeclarativeView view(QUrl("qrc:///tictactoe.qml"));
	view.setResizeMode(QDeclarativeView::SizeRootObjectToView);
	QObject::connect(view.engine(), SIGNAL(quit()), &view, SLOT(close()));
	view.show();

	return app.exec();
}

