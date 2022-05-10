#include "diskgame.h"
#include "disks.h"
#include "reddisk.h"
#include <QGraphicsScene>
#include <QBrush>
#include <QTimer>
#include <stdlib.h>
#include "disk.h"
#include "greendisk.h"
#include "bluedisk.h"

/**
* \file diskgame.cpp
* \brief contains diskgame class definition
*
*
*  sets disk pad at the bottom of the screen
*  disks spawn and move downwards every 1.5 sec
*  press right key to activate blue disk pad
*  press down key to activate green disk pad
*  press left key to activate red disk pad
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

int attempts = 3; ///> max number of attempts is 3
int red = 0; ///> red score initialized to 0
int blue = 0; ///> blue score initialized to 0
int green = 0; ///> green score initialized to 0
int totalscore = 0; ///> total score initialized to 0

diskgame::diskgame(QString& username)
{

    QRect screenGeometry = QApplication::desktop()->screenGeometry(); ///> get screen geometry
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    QApplication::desktop()->move(x,y); ///> move to center of the screen

    uname = username;
    //usname = username;
    QTimer *timer = new QTimer();
    QTimer *timer1 = new QTimer();
    QTimer *timer2 = new QTimer();
    QTimer *timer3 = new QTimer();
    reddisk *redd = new reddisk(uname);
    greendisk *greend = new greendisk();
    bluedisk *blued = new bluedisk();
    disks *diskspawn = new disks(uname);
    blued->setFlag(QGraphicsItem :: ItemIsFocusable);
    blued->setFocus();
    greend->setFlag(QGraphicsItem :: ItemIsFocusable);
    greend->setFocus();
    redd->setFlag(QGraphicsItem :: ItemIsFocusable);
    redd->setFocus();
    setBackgroundBrush(QBrush(QImage(":/background.jpg").scaledToHeight(200).scaledToWidth(400))); ///< add background image and scale it to the window size
    setSceneRect(0,0,200,400);

    this->addItem(redd); ///> add red disk to the scene
    this->addItem(greend); ///> add green disk to the scene
    this->addItem(blued); ///> add blue disk to the scene
    this->addItem(diskspawn);  ///> add disk spawner to the scene

    connect(timer, SIGNAL(timeout()), redd, SLOT(spawn())); ///> spawn a disk at the top every 1.5 sec
    connect(timer1, SIGNAL(timeout()), redd, SLOT(scene()->setFocus())); ///> set focus on red pad every 1 sec
    connect(timer2, SIGNAL(timeout()), blued, SLOT(scene()->setFocus())); ///> set focus on blue pad every 1.2 sec
    connect(timer3, SIGNAL(timeout()), greend, SLOT(scene()->setFocus())); ///> set focus on green pad every 1.4 sec
    timer->start(1500);
    timer1->start(1000);
    timer2->start(1200);
    timer3->start(1400);



}
