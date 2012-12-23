#include "computer.h"

Computer::Computer(QPixmap const &normal, QPixmap const &infected
		, QGraphicsItem *parent)
	: QGraphicsPixmapItem(normal, parent)
	, _normal(normal), _infected(infected), _isInfected(false)
	, _id(++uniqueComputers), _infectionRisk(0.5)
{
}

int Computer::uniqueComputers = 0;

bool Computer::tryToInfect()
{
	if (qrand() < RAND_MAX * _infectionRisk) {
		_isInfected = true;
		setPixmap(_infected);
		return true;
	}
	return false;
}
