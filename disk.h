#ifndef DISK_H
#define DISK_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

/**
* \file disk.h
* \brief disk class
*
*
*  initialize keypressevent to start game using F1 key
*  initializes QPushButtons
*  initializes two slots, back() and startgame() both are void
*
*
*/

class disk : public QWidget
{
    Q_OBJECT

QPushButton *start;
QPushButton *goback;
QString uname;
QGridLayout *grid1;

public:
    explicit disk(QString& username, QWidget *parent = nullptr);
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

#endif // DISK_H
