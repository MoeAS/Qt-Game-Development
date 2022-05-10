#include "battleship.h"
#include "battleshipgame.h"
#include "profile.h"

/**
* \file battleship.cpp
* \brief contains battleship class definition
*
*
*  it is the game menu of the battleship game
*  allows player to start game or go back to the profile page
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

Battleship::Battleship(QString& username, QWidget *parent) : QWidget(parent)
{
    uname = username;
    this->setFixedSize(500, 300);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);

    QPixmap q(":/shipmenu.JPG");
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
    grid1->addWidget(goback, 0, 0, 0, 0, Qt::AlignLeft);
    //goback->setGeometry(0, 290, 60, 20);


    QObject::connect(goback, SIGNAL(clicked(bool)), this, SLOT(back())); ///> go back to profile page
    QObject::connect(start, SIGNAL(clicked(bool)), this, SLOT(startgame())); ///> start playing the game

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

void Battleship::back()
{
    profile *pf = new profile(uname);
    pf->show();
    this->close();
}

/**
*
* \brief enters game1 and starts playing
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the game menu page is closed and battleship game page is opened
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void Battleship::startgame()
{
    battleshipgame *bsg = new battleshipgame(uname);
    bsg->show();
    this->close();
}
