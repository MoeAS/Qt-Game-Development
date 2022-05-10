#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

/**
* \file battleship.h
* \brief battleship class
*
*
*  initialize Keypressevent, a public slot called back() which is a void, a public slot called startgame() which is a void
*
*
*/

class Battleship : public QWidget
{

    Q_OBJECT

QPushButton *start;
QPushButton *goback;
QString uname;
QGridLayout *grid1;

public:
   explicit Battleship(QString& username, QWidget *parent = nullptr); ///> pres F1 to start the game
    void keyPressEvent(QKeyEvent * event){
        if (event->key() == Qt :: Key_F1) {
            startgame();
        }
    }

signals:
    public slots:
        void back();
        void startgame();
};

#endif // BATTLESHIP_H
