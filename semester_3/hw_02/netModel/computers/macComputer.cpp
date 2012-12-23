#include "macComputer.h"

MacComputer::MacComputer(QGraphicsItem *parent)
	: Computer(QPixmap(":/icons/macComputerNormal.png")
	, QPixmap(":/icons/macComputerInfected.png")
	, parent)
{
	_infectionRisk = 0.2;
}
