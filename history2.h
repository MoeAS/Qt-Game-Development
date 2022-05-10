#ifndef HISTORY2_H
#define HISTORY2_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QGraphicsScene>

/**
* \file history2.h
* \brief history2 class
*
*
*  initialize slot called goback() which is a void
*  initialize QStrings, QLabels, QPushbuttons
*
*
*/

class history2 : public QWidget
{
    Q_OBJECT

    QString uname;
    QLabel *hist;
    QGridLayout *grid;
    QPushButton *back;

public:
    history2(QString& username, QWidget *parent = nullptr);

public slots:
        void goback();
};

#endif // HISTORY2_H
