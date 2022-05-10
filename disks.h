#ifndef DISKS_H
#define DISKS_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>

/**
* \file disks.h
* \brief disks class
*
*
*  initialize slot called move() which is a void
*  initialize QString to save username in
*
*
*/

class disks : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

QString uname;
public:
    disks(QString& username);


signals:
public slots:
    void move();
};

#endif // DISKS_H
