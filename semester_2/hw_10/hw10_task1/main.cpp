#include <QtGui>
#include "ticTacToe.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	TicTacToe field;
	field.show();

	return app.exec();
}
