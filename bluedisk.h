#ifndef BLUEDISK_H
#define BLUEDISK_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "disks.h"
#include "diskgame.h"

/**
* \file bluedisk.h
* \brief bluedisk class
*
*
*  initialize keypressevent to know when disks collide with each other of the same colors using the right key and updates counters totalscore and blue
*
*
*/

class bluedisk: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bluedisk();
    void keyPressEvent(QKeyEvent * event){ ///> check if pressed then check if disks collide
        if (event->key() == Qt :: Key_Right) {
            QList<QGraphicsItem *> colliding_items = collidingItems();
            for (int i = 0, x = colliding_items.size(); i < x ; i++){
                if (typeid(*(colliding_items[i])) == typeid(disks)){
                    scene()->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    blue += 7;
                    totalscore += 7;
                }
    }
  }
}
};

#endif // BLUEDISK_H
