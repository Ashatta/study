#include "linuxComputer.h"

LinuxComputer::LinuxComputer(QGraphicsItem *parent)
	: Computer(QPixmap(":/icons/linuxComputerNormal.png")
	, QPixmap(":/icons/linuxComputerInfected.png")
	, parent)
{
	_infectionRisk = 0.02;
}
