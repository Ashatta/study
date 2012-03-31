#include "calculator.h"
#include <QLayout>
#include <QPushButton>
#include <sstream>
#include "stackmachine.h"
#include "polish_conv.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    result(new QLineEdit()),
    signalMapper(new QSignalMapper(this))
{
    setWindowTitle("Calculator");

    QStringList buttonNames;
    buttonNames << "7" << "8" << "9" << "+" << "4" << "5" << "6" << "-"
        << "1" << "2" << "3" << "*" << "0" << "." << "=" << "/";

    QGridLayout * layout = new QGridLayout(this);
    layout->setHorizontalSpacing(6);
    layout->setVerticalSpacing(6);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    result->setReadOnly(true);
    layout->addWidget(result, 0, 0, 1, 4);

    for (int i = 0; i < buttonNames.size(); i++)
    {
        QPushButton * button = new QPushButton(buttonNames[i]);
        button->setMaximumSize(55, 55);
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(button, buttonNames[i]);
        layout->addWidget(button, i / 4 + 1, i % 4);
    }

    connect(signalMapper, SIGNAL(mapped(const QString&)),
            this, SLOT(clicked(const QString&)));

    setLayout(layout);
}

void Calculator::clicked(const QString &button)
{
    static bool point = false;
    static bool needClearance = false; // need to clear result field after every calculation
    if (button[0] >= '0' && button[0] <= '9')
    {
        if (needClearance)
        {
            expression = "";
            needClearance = false;
        }
        expression += button[0];
        result->setText(expression);
        return;
    }
    if (expression.length() == 0)
        return;
    if (expression[expression.length() - 1] >= '0' &&
        expression[expression.length() - 1] <= '9')
    {
        if (button[0] == '.')
        {
            if (!point)
                if (!needClearance)
                {
                    expression += button[0];
                    point = true;
                }
        }
        else if (button[0] == '=')
        {
            point = false;
            needClearance = true;

            std::stringstream buf;
            std::stringstream buf2;

            buf << expression.toStdString();

            StackMachine stackMachine;
            PolishConverter converter;

            converter.convert(buf, buf2);
            expression = QString::number(stackMachine.calculate(buf2));
        }
        else if (!needClearance)
        {
            point = false;
            expression += ' ' + button[0] + ' ';
        }
    }
    result->setText(expression);
    return;
}
