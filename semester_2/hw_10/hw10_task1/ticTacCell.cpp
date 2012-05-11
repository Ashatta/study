#include "ticTacCell.h"

TicTacCell::TicTacCell(int const row, int const column
		, QIcon const &unset, QIcon const &x, QIcon const &o
		, QString const &text, QWidget* parent)
	: QPushButton(unset, text, parent)
	, mRow(row), mColumn(column), unsetImage(unset), xImage(x), oImage(o)
{
	connect(this, SIGNAL(clicked()), this, SLOT(clicked()));
}


void TicTacCell::setState(State s)
{
	if (s == X)
		setIcon(xImage);
	else if (s == O)
		setIcon(oImage);
	else
		setIcon(unsetImage);
}

