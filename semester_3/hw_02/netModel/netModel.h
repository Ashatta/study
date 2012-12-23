#pragma once

#include "computers/computer.h"

#include <QGraphicsScene>

class NetModel : public QGraphicsScene
{
	Q_OBJECT

public:
	explicit NetModel(QObject *parent = 0);

	void addConnection(QPointF const &first, QPointF const &second);
	void addItem(QGraphicsItem *item);

public slots:
	/** Initiate random infection and distribute viruses over the network */
	void nextStep();
	void clear();

private:
	void initVirusItem();
	void distributeVirus();
	// Try to infection random non-infecteded computer
	void initiateNewInfection();
	// Makes virusItem "not exist" when there is no need in showing it
	void hideVirusItem();
	// @return list of computers connected to infected ones
	QList<Computer *> computersInDanger();

	QVector<QPair<int, int> > _connections;
	QMap<int, Computer *> _computers;

	QGraphicsPixmapItem *_virusItem;
};
