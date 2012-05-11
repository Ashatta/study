#pragma once

#include <QPushButton>

class TicTacCell : public QPushButton
{
	Q_OBJECT
public:
	enum State { Unset, X, O };

	TicTacCell(int const row, int const column
			, QIcon const &unset, QIcon const &x, QIcon const &o
			, QString const &text, QWidget* parent = 0);

	void setState(State s);

protected slots:
	void clicked()
	{
		emit click(mRow, mColumn, this);
	}

signals:
	void click(int, int, TicTacCell*);

private:
	int mRow;
	int mColumn;

	QIcon unsetImage;
	QIcon xImage;
	QIcon oImage;
};
