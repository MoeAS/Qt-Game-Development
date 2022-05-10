#include "disk.h"
#include "profile.h"
#include "diskgame.h"

/**
* \file disk.cpp
* \brief contains disk class definition
*
*
*  it is the game menu of the shooting discs
*  allows player to start game or go back to the profile page
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

disk::disk(QString& username, QWidget *parent) : QWidget(parent)
{

    uname = username;
    this->setFixedSize(193, 347);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);

    QPixmap q(":/diskmenu.JPG"); ///> set window background
    q = q.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, q);
    this->setPalette(palette);


    goback = new QPushButton("Go Back");
    start = new QPushButton("Start");
    grid1 = new QGridLayout();
    goback->setFixedSize(60, 20);
    start->setFixedSize(60, 20);

    grid1->addWidget(start, 5, 0, 0, 0, Qt::AlignCenter);
    grid1->addWidget(goback, 0, 0, 0, 0, Qt::AlignCenter);
    //goback->setGeometry(0, 290, 60, 20);


    QObject::connect(goback, SIGNAL(clicked(bool)), this, SLOT(back()));
    QObject::connect(start, SIGNAL(clicked(bool)), this, SLOT(startgame()));

    setLayout(grid1);

}

/**
*
* \brief go back to the user profile page
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the user profile page is opened and the game menu is closed
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void disk::back()
{
    profile *pf = new profile(uname);
    pf->show();
    this->close();
}

/**
*
* \brief enters game2 and starts playing
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the game menu page is closed and shooting discs game scene page is opened
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void disk::startgame()
{
    QGraphicsView *v1 = new QGraphicsView();
    diskgame *dg = new diskgame(uname);
    attempts = 3;
    red = 0;
    blue = 0;
    green = 0;
    totalscore = 0;
    v1->setScene(dg);
    v1->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));///< turn off horizontal scrollbar
    v1->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));///< turn off vertical scrollbar
    v1->show();
    v1->setFixedSize(200, 400);///< set window to fixed size 200x400
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    v1->move(x,y);

    this->close();
}
