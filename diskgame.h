#ifndef DISKGAME_H
#define DISKGAME_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "disks.h"
#include "disk.h"

/**
* \file diskgame.h
* \brief diskagame class
*
*
*  initialize global variables attempts, red, blue, green, and totalscore
*
*
*/

class diskgame: public QGraphicsScene
{
    QString uname;

    Q_OBJECT
public:
    diskgame(QString& username);
};

extern int attempts;
extern int red;
extern int blue;
extern int green;
extern int totalscore;

#endif // DISKGAME_H
