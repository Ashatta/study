#pragma once

#include <QGraphicsPixmapItem>

/** Represents a computer which can be in normal state or infected by a virus.
  * Every computer has an unique id.
  */
class Computer : public QGraphicsPixmapItem
{
public:
	Computer(QPixmap const &normal, QPixmap const &infected
			, QGraphicsItem *parent = 0);

	int id() { return _id; }
	bool isInfected() { return _isInfected; }
	/** Try to infect computer. Success chance depends on _infectionRisk value */
	bool tryToInfect();

protected:
	QPixmap _normal;
	QPixmap _infected;

	bool _isInfected;
	int _id;

	double _infectionRisk;

	static int uniqueComputers;
};
