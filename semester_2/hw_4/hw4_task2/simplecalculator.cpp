#include "simplecalculator.h"
#include "ui_simplecalculator.h"

SimpleCalculator::SimpleCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimpleCalculator)
{
    ui->setupUi(this);

    ui->operation->addItem("+");
    ui->operation->addItem("-");
    ui->operation->addItem("*");
    ui->operation->addItem("/");

    connect(ui->arg1, SIGNAL(valueChanged(int)), this, SLOT(recalculate()));
    connect(ui->arg2, SIGNAL(valueChanged(int)), this, SLOT(recalculate()));
    connect(ui->operation, SIGNAL(currentIndexChanged(int)), this, SLOT(recalculate()));
}

SimpleCalculator::~SimpleCalculator()
{
    delete ui;
}

void SimpleCalculator::recalculate()
{
    QString oper = ui->operation->currentText();
    int result = 0;
    int arg1 = ui->arg1->value();
    int arg2 = ui->arg2->value();

    switch (oper[0].toAscii())
    {
        case '+': result = arg1 + arg2;
              break;
        case '-': result = arg1 - arg2;
              break;
        case '*': result = arg1 * arg2;
              break;
        case '/': if (arg2 == 0)
          {
                    ui->result->setText(QString::fromUtf8("\u221E"));
            return;
          }
          else
            result = arg1 / arg2;
    }
    ui->result->setText(QString::number(result));
    return;
}
