#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QSignalMapper>

/** Class Calculator provides calculation of expressions of real numbers
 *  and operations +, -, *, /.
 */
class Calculator : public QWidget
{
    Q_OBJECT
    
public:
    /** Constructor of Calculator creates form of the application and maps signals
     *  emitted by buttons with its own slot clicked.
     */
    explicit Calculator(QWidget *parent = 0);
    ~Calculator() {}
    
private slots:
    /** Slot clicked handles a click on any button of form. */
    void clicked(const QString &);

private:
    QLineEdit * result;
    QSignalMapper * signalMapper;
    QString expression; ///< An expression to calculate.
};
