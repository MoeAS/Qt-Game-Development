#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QGraphicsScene>

/**
* \file questions.h
* \brief questions class
*
*
*  initialize slots called submit() which is an int
*  initialize signal called sigemit() which is an int
*  initialize QRadioButton, QLabels, QPushbuttons
*
*
*/

class questions : public QWidget
{
    Q_OBJECT

    QRadioButton *True;
    QRadioButton *False;
    QGridLayout *grid;
    QLabel *ques;
    QPushButton *ok;

public:
    questions(QWidget *parent = nullptr);
    signals:
        //int submit();
        int sigemit(int x);
    public slots:
        int submit();

};

#endif // QUESTIONS_H
