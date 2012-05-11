#pragma once

#include <QtGui>
#include <QVector>
#include "ticTacCell.h"

class TicTacToe : public QWidget
{
	Q_OBJECT
public:
	TicTacToe(int fieldSize = 3, QWidget* parent = 0);

public slots:
	void newStep(int row, int column, TicTacCell* cell);

protected:
	void gameOver();

	void checkRow(int row);
	void checkColumn(int column);
	void checkMainDiag();
	void checkSideDiag();

	void createLayout();

protected slots:
	void clear();

private:
	QGridLayout* layout;

	QSize const cellSize;
	int const side;
	TicTacCell::State nextStep;	

	QIcon unsetImage;
	QIcon xImage;
	QIcon oImage;

	QVector<QVector<TicTacCell::State> > states;
};
