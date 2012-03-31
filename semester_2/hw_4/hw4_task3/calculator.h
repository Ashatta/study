#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QSignalMapper>

class Calculator : public QWidget
{
    Q_OBJECT
    
public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator() {}
    
private slots:
    void clicked(const QString &);

private:
    QLineEdit * result;
    QSignalMapper * signalMapper;
    QString expression;
};
