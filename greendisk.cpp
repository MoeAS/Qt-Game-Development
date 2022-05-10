#include "greendisk.h"
#include "disks.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

/**
* \file greendisk.cpp
* \brief contains disk pad of green disk class definition
*
*
*  scales green disk to a 40x40 scale
*  sets position of the green disk pad at 80, 340
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/


greendisk::greendisk()
{

    setPixmap((QPixmap(":/greendisk.png").scaled(40,40))); ///> set scale
    setPos(80, 340); ///> set position
}
