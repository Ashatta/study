#pragma once
#include <QWidget>

namespace Ui {
class SimpleCalculator;
}

class SimpleCalculator : public QWidget
{
    Q_OBJECT
    
public:
    explicit SimpleCalculator(QWidget *parent = 0);
    ~SimpleCalculator();
    
private:
    Ui::SimpleCalculator *ui;

public slots:
    void recalculate();
};
