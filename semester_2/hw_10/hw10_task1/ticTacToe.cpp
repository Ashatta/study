#include "ticTacToe.h"

TicTacToe::TicTacToe(int fieldSide, QWidget* parent)
	: QWidget(parent), layout(new QGridLayout)
	, cellSize(QSize(50, 50)), side(fieldSide), nextStep(TicTacCell::X)
	, unsetImage("unsetImage.png"), xImage("xImage.png")
	, oImage("oImage.png") , states(QVector<QVector<TicTacCell::State> >(side))
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
		states[i].fill(TicTacCell::Unset, side);

	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
		{
			TicTacCell* cell = dynamic_cast<TicTacCell*>
					(layout->itemAtPosition(i, j)->widget());
			cell->setState(TicTacCell::Unset);
		}
	
	nextStep = TicTacCell::X;
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
		}
		else
		{
			cell->setState(TicTacCell::O);
			states[row][column] = TicTacCell::O;
			nextStep = TicTacCell::X;
		}

		checkRow(row);
		checkColumn(column);
		checkMainDiag();
		checkSideDiag();
	}
}

void TicTacToe::gameOver()
{
	QMessageBox message;

	QString text("The game is over. ");
	text += (nextStep == TicTacCell::X)? "O" : "X";
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
	gameOver();
}

void TicTacToe::checkColumn(int column)
{
	for (int i = 1; i < side; i++)
		if (states[i][column] != states[0][column])
			return;
	gameOver();
}

void TicTacToe::checkMainDiag()
{
	if (states[0][0] == TicTacCell::Unset)
		return;

	for (int i = 1; i < side; i++)
		if (states[i][i] != states[0][0])
			return;
	gameOver();
}

void TicTacToe::checkSideDiag()
{
	if (states[0][side - 1] == TicTacCell::Unset)
		return;

	for (int i = 1; i < side; i++)
		if (states[i][side - i - 1] != states[0][side - 1])
			return;
	gameOver();
}

