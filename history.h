#ifndef HISTORY_H
#define HISTORY_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QGraphicsScene>

/**
* \file history.h
* \brief history class
*
*
*  initialize slot called goback() which is a void
*  initialize QStrings, QLabels, QPushbuttons
*
*
*/

class history : public QWidget
{
    Q_OBJECT

    QString uname;
    QLabel *hist;
    QGridLayout *grid;
    QPushButton *back;

public:
    history(QString& username, QWidget *parent = nullptr);

public slots:
        void goback();
};

#endif // HISTORY_H
