#include "view.h"
#include "netModel.h"

#include "computers/linuxComputer.h"
#include "computers/macComputer.h"
#include "computers/windowsComputer.h"

#include <QMouseEvent>
#include <QDebug>

View::View(QWidget *parent)
	: QGraphicsView(parent)
	, _mode(NoDraw)
{
	setMouseTracking(true);
	setRenderHints(QPainter::Antialiasing);
}

void View::setScene(NetModel *model)
{
	_model = model;
	QGraphicsView::setScene(model);
}

void View::setDrawMode(DrawMode mode)
{
	_mode = mode;
	if (mode != ConnectionDraw)
		_line = QLine();
}

void View::mousePressEvent(QMouseEvent *event)
{
	Computer *computer = 0;
	switch (_mode) {
		case NoDraw:
			QGraphicsView::mousePressEvent(event);
			return;
		case LinuxDraw:
			computer = new LinuxComputer;
			break;
		case MacDraw:
			computer = new MacComputer;
			break;
		case WindowsDraw:
			computer = new WindowsComputer;
			break;
		case ConnectionDraw:
			drawConnection(event->pos());
			return;
	}

	computer->setPos(mapToScene(event->pos()));
	_model->addItem(computer);
}

void View::mouseMoveEvent(QMouseEvent *event)
{
	if (_mode == ConnectionDraw && _line != QLine())
		_line.setP2(event->pos());
	QGraphicsView::mouseMoveEvent(event);
}

void View::drawConnection(QPoint const &pos)
{
	if (!itemAt(pos)) {
		_line = QLine();
		return;
	}

	if (_line == QLine())
		_line.setPoints(pos, pos);
	else {
		_model->addConnection(mapToScene(_line.p1()), mapToScene(_line.p2()));
		_line = QLine();
	}
}
