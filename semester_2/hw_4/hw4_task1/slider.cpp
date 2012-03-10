#include "slider.h"
#include "ui_slider.h"

Slider::Slider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Slider)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->progressBar, SLOT(setValue(int)));
}

Slider::~Slider()
{
    delete ui;
}
