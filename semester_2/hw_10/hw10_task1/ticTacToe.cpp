#include "ticTacToe.h"

TicTacToe::TicTacToe(int fieldSide, QWidget* parent)
	: QWidget(parent), layout(new QGridLayout)
	, cellSize(QSize(50, 50)), side(fieldSide), nextStep(TicTacCell::X)
	, unsetImage("unsetImage.png"), xImage("xImage.png")
	, oImage("oImage.png") , states(QVector<QVector<TicTacCell::State> >(side))
	, steps(0)
{
	
	for (int i = 0; i < side; i++)
		states[i].fill(TicTacCell::Unset, side);

	createLayout();

	setLayout(layout);
	setFixedSize(layout->sizeHint());
}

void TicTacToe::clear()
{
	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
		{
			states[i][j] = TicTacCell::Unset;

			TicTacCell* cell = dynamic_cast<TicTacCell*>
					(layout->itemAtPosition(i, j)->widget());
			cell->setState(TicTacCell::Unset);
		}
	
	nextStep = TicTacCell::X;
	steps = 0;
}

void TicTacToe::createLayout()
{
	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
		{
			TicTacCell* cell = new TicTacCell(i, j
					, unsetImage, xImage, oImage, "");
			cell->setIconSize(cellSize);

			connect(cell, SIGNAL(click(int, int, TicTacCell*))
					, this, SLOT(newStep(int, int, TicTacCell*)));

			layout->addWidget(cell, i, j);
		}
}

void TicTacToe::newStep(int row, int column, TicTacCell* cell)
{
	if (states[row][column] == TicTacCell::Unset)
	{
		if (nextStep == TicTacCell::X)
		{
			cell->setState(TicTacCell::X);
			states[row][column] = TicTacCell::X;
			nextStep = TicTacCell::O;
			steps++;
		}
		else
		{
			cell->setState(TicTacCell::O);
			states[row][column] = TicTacCell::O;
			nextStep = TicTacCell::X;
			steps++;
		}

		checkRow(row);
		checkColumn(column);
		if (row == column)
			checkMainDiag();
		if (row + column == side - 1)
			checkSideDiag();

		if (steps == side * side)
			gameOver(0);
	}
}

void TicTacToe::gameOver(int winner)
{
	QMessageBox message;

	QString text("The game is over. ");
	switch (winner)
	{
		case 0: text += "No one";
				break;
		case 1: text += "X";
				break;
		case 2: text += "O";
	}
	text += " wins.";

	message.setText(text);
	message.setInformativeText("Would you like to start a new game?");

	QPushButton* newGame = message.addButton("New Game", QMessageBox::ActionRole);
	QPushButton* end = message.addButton("Close", QMessageBox::ActionRole);

	message.exec();

	if (message.clickedButton() == newGame)
		clear();
	else if (message.clickedButton() == end)
		close();
}

void TicTacToe::checkRow(int row)
{
	for (int i = 1; i < side; i++)
		if (states[row][i] != states[row][0])
			return;
	gameOver(states[row][0]);
}

void TicTacToe::checkColumn(int column)
{
	for (int i = 1; i < side; i++)
		if (states[i][column] != states[0][column])
			return;
	gameOver(states[0][column]);
}

void TicTacToe::checkMainDiag()
{
	if (states[0][0] == TicTacCell::Unset)
		return;

	for (int i = 1; i < side; i++)
		if (states[i][i] != states[0][0])
			return;
	gameOver(states[0][0]);
}

void TicTacToe::checkSideDiag()
{
	if (states[0][side - 1] == TicTacCell::Unset)
		return;

	for (int i = 1; i < side; i++)
		if (states[i][side - i - 1] != states[0][side - 1])
			return;
	gameOver(states[0][side - 1]);
}

