#ifndef REDDISK_H
#define REDDISK_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "diskgame.h"
#include "disks.h"

/**
* \file reddisk.h
* \brief reddisk class
*
*
*  initialize keypressevent to know when disks collide with each other of the same colors using the left key and updates counters totalscore and red
*  initialize slot called spawn() which is a void
*
*
*/

class reddisk: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

QString uname;
public:
    reddisk(QString& username);
    void keyPressEvent(QKeyEvent * event){
        if (event->key() == Qt :: Key_Left) {

            QList<QGraphicsItem *> colliding_items = collidingItems();
            for (int i = 0, x = colliding_items.size(); i < x ; i++){
                if (typeid(*(colliding_items[i])) == typeid(disks)){
                    scene()->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    red += 3;
                    totalscore += 3;
                }
    }
  }
}

signals:
public slots:
    void spawn();
};

#endif // REDDISK_H
