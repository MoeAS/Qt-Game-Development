#include "disks.h"
#include "diskgame.h"
#include "reddisk.h"
#include "greendisk.h"
#include "bluedisk.h"
#include <stdlib.h>
#include <QList>
#include "disk.h"

/**
* \file disks.cpp
* \brief contains disks class definition
*
*
*  spawns disks at fixed speeds depending on the score, but random spawn times
*  run move() function initially at 70 ms and decreasing when score increases
*  player wins at score of 150 points, and gains bonus points after that
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/


disks::disks(QString& username): QObject()
{
    uname = username;

    int random_disk = rand() % 3; ///> random number to choose between which disk to spawn
    if (random_disk == 0){
        setPixmap((QPixmap(":/bluedisk.png").scaled(30,30)));
        setPos(160, 0);
    }
    else if (random_disk == 1){
        setPixmap((QPixmap(":/reddisk.png").scaled(30,30)));
        setPos(0, 0);
    }
    else if (random_disk == 2){
        setPixmap((QPixmap(":/greendisk.png").scaled(30,30)));
        setPos(80, 0);
    }


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));  ///> disks move at a certain speed depending on timer
    if (totalscore < 30){
        timer->start(70);
    }

    else if (totalscore == 30){
        timer->start(35);  ///> speed doubles
    }

    else if (totalscore == 60){
        timer->start(17);  ///> speed doubles
    }

    else if (totalscore == 90){
        timer->start(8); ///> speed doubles
    }

    else if (totalscore == 120){
        timer->start(4); ///> speed doubles
    }

    else if (totalscore == 150){
        timer->start(2); ///> speed doubles
    }

}

/**
*
* \brief move the disks downwards to a certain level then deletes from memory and scene
*
*
*  the disks are moving at a fixed speed on the y axis downwards
*  when reaching the bottom of the screen the disks are deleted from memory and removed from the scene
*  when reaching the bottom and removed it is considered a miss so the user loses one attempt each time
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void disks::move(){

    setPos(x(), y()+7);
    if (pos().y()-380 > 0) {
        scene()->removeItem(this); ///> disk is removed from memory and scene when it reaches the bottom of the screen to save memory
        delete this;
        attempts-=1;
    }

}
