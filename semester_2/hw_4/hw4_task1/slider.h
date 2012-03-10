#pragma once
#include <QWidget>

namespace Ui {
class Slider;
}

class Slider : public QWidget
{
    Q_OBJECT
    
public:
    explicit Slider(QWidget *parent = 0);
    ~Slider();
    
private:
    Ui::Slider *ui;
};
