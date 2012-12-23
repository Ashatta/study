#pragma once

#include <QGraphicsView>
#include <QLine>

class NetModel;

class View : public QGraphicsView
{
public:
	enum DrawMode { NoDraw = 0, LinuxDraw, MacDraw, WindowsDraw, ConnectionDraw };

	explicit View(QWidget *parent = 0);

	void setScene(NetModel *model);
	void setDrawMode(DrawMode mode);

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private:
	void drawConnection(QPoint const &pos);

	NetModel *_model;
	DrawMode _mode;

	QLine _line;
};
