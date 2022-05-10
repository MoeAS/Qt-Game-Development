#ifndef GREENDISK_H
#define GREENDISK_H


#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "disks.h"
#include "diskgame.h"

/**
* \file greendisk.h
* \brief greendisk class
*
*
*  initialize keypressevent to know when disks collide with each other of the same colors using the down key and updates counters totalscore and green
*
*
*/

class greendisk: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    greendisk();
    void keyPressEvent(QKeyEvent * event){

        if (event->key() == Qt :: Key_Down) {
            QList<QGraphicsItem *> colliding_items = collidingItems();
            for (int i = 0, x = colliding_items.size(); i < x ; i++){
                if (typeid(*(colliding_items[i])) == typeid(disks)){
                    scene()->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    green += 5;
                    totalscore += 5;
                }
    }
  }
}
};

#endif // GREENDISK_H
