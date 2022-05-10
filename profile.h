#ifndef PROFILE_H
#define PROFILE_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QGraphicsScene>

/**
* \file profile.h
* \brief profile class
*
*
*  initialize slots called goback(), playgame1(), playgame2(), gohistory(), gohistory2() which are all void
*  initialize QStrings, QLabels, QPushbuttons
*
*
*/

class profile : public QWidget
{
    Q_OBJECT
public:
    QLabel *fullname;
    QLabel *name;
    QLabel *currenttime;
    QLabel *current;
    QLabel *countryname;
    QLabel *pp;
    QLabel *flag;
    QStringList s;
    QString uname;

    QPushButton *back;
    QPushButton *histor;
    QPushButton *histor2;
    QPushButton *play;
    QPushButton *play2;

    QGridLayout *grid1;
    QVBoxLayout *box;

public:
    explicit profile(QString& username, QWidget *parent = nullptr);

signals:
    private slots:
        void goback();
        void playgame1();
        void playgame2();
        void gohistory();
        void gohistory2();
};

#endif // PROFILE_H
