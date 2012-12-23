#include "windowsComputer.h"

WindowsComputer::WindowsComputer(QGraphicsItem *parent)
	: Computer(QPixmap(":/icons/windowsComputerNormal.png")
	, QPixmap(":/icons/windowsComputerInfected.png")
	, parent)
{
	_infectionRisk = 0.65;
}
