#include "netModel.h"

NetModel::NetModel(QObject *parent)
	: QGraphicsScene(parent)
{
	initVirusItem();
}

void NetModel::addConnection(QPointF const &first, QPointF const &second)
{
	Computer *comp1 = dynamic_cast<Computer *>(itemAt(first));
	Computer *comp2 = dynamic_cast<Computer *>(itemAt(second));
	if (comp1 && comp2 && comp1 != comp2
			&& !_connections.contains(QPair<int, int>(comp1->id(), comp2->id()))
			&& !_connections.contains(QPair<int, int>(comp2->id(), comp1->id()))) {

		_connections << QPair<int, int>(comp1->id(), comp2->id());
		QGraphicsLineItem *line = new QGraphicsLineItem(QLineF(first, second));
		line->setZValue(-1000);
		line->setPen(QPen(QColor(Qt::black), 2));
		addItem(line);
	}
}

void NetModel::addItem(QGraphicsItem *item)
{
	QGraphicsScene::addItem(item);
	Computer *comp = dynamic_cast<Computer *>(item);
	if (comp)
		_computers.insert(comp->id(), comp);
}

void NetModel::nextStep()
{
	hideVirusItem();
	distributeVirus();
	initiateNewInfection();
}

void NetModel::initVirusItem()
{
	_virusItem = new QGraphicsPixmapItem(QPixmap(":/icons/newVirus.png"));
	hideVirusItem();
	addItem(_virusItem);
}

void NetModel::clear()
{
	QGraphicsScene::clear();
	initVirusItem();
	_computers.clear();
	_connections.clear();
}

void NetModel::distributeVirus()
{
	foreach (Computer *comp, computersInDanger())
		comp->tryToInfect();
}

void NetModel::initiateNewInfection()
{
	Computer *comp = _computers.value(qrand() % _computers.size());
	if (comp && !comp->isInfected()) {
		if (comp->tryToInfect()) {
			_virusItem->setPos(comp->pos());
			_virusItem->setVisible(true);
			_virusItem->setZValue(1000);
		}
	}
}

void NetModel::hideVirusItem()
{
	_virusItem->setVisible(false);
	_virusItem->setZValue(-1000);
}

QList<Computer *> NetModel::computersInDanger()
{
	typedef QPair<int, int> Pair;

	QList<Computer *> inDanger;
	foreach (Pair connection, _connections) {
		Computer *first = _computers.value(connection.first);
		Computer *second = _computers.value(connection.second);

		if (first->isInfected() && !inDanger.contains(second))
			inDanger << second;
		if (second->isInfected() && !inDanger.contains(first))
			inDanger << first;
	}
	return inDanger;
}
