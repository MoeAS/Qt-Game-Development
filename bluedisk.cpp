#include "bluedisk.h"
#include "disks.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

/**
* \file bluedisk.cpp
* \brief contains disk pad of blue disk class definition
*
*
*  scales blue disk to a 40x40 scale
*  sets position of the blue disk pad at 160, 340
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

bluedisk::bluedisk()
{

    setPixmap((QPixmap(":/bluedisk.png").scaled(40,40))); ///> set scale
    setPos(160, 340); ///> set position
}
