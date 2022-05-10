#include "profile.h"
#include "signin.h"
#include "signin.cpp"
#include "history.h"
#include "history2.h"
#include "battleship.h"
#include "disk.h"
#include <QGraphicsScene>

/**
* \file profile.cpp
* \brief contains user profile which displays currect date & time, profile pic, full name, history of both games,
* buttons to play both games, and country flag depending on phone number inserted
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

profile::profile(QString& username, QWidget *parent) : QWidget(parent)
{

    this->setStyleSheet("background-color: grey; color: white;");  ///> change the profile background and text color

    this->setFixedSize(350,300);  ///> scales window to 350x300

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);  ///> moves window to the center of the screen when opened

    /**
    * initalizing all QLabels and QPushButtons to display on the screen
    */

    uname = username;
    name = new QLabel("Name");
    fullname = new QLabel();
    back = new QPushButton("Sign Out");
    back->setCursor(Qt::PointingHandCursor);
    currenttime = new QLabel();
    current = new QLabel("Current Date");
    histor = new QPushButton("Game 1 History");
    histor->setCursor(Qt::PointingHandCursor);
    histor2 = new QPushButton("Game 2 History");
    histor2->setCursor(Qt::PointingHandCursor);
    play = new QPushButton("Play Game 1!");
    play->setCursor(Qt::PointingHandCursor);
    play2 = new QPushButton("Play Game 2!");
    play2->setCursor(Qt::PointingHandCursor);

    countryname = new QLabel();
    QString countrycode;
    flag = new QLabel();

    pp = new QLabel();
    QString Date = QDate::currentDate().toString();
    QString s1;

    QFile file("/home/eece435l/Project435L/Database.txt");

    if(file.open(QIODevice::ReadOnly | QFile::Text)){ ///> check username to display that user's information

        QTextStream u1(&file);
        fullname->setText("Guest");

        while(!u1.atEnd()){
            QString line = u1.readLine();
            if((username == line.section("|",1,1))){
                fullname->setText(line.section("|",0,0));
                s1 = line.section("|",6,6);
                countrycode = line.section("|",4, 4);
                break;
        }

    }

        if (username != ""){

        s = countrycode.split("-");
}

    if (username.isEmpty()){ ///> if user plays as guest, username would not be found
        s1 = ":/profile.png"; ///> set default profile pic
        fullname->setText("Guest"); ///> set name as guest
    }

    pp->setPixmap(QPixmap(s1).scaled(100,100));

    //fullname->setText(username);

    currenttime->setText(Date); ///> set current date and time

    grid1 = new QGridLayout();
    box = new QVBoxLayout();

    box->addLayout(grid1);
    grid1->addWidget(pp, 0, 0);
    grid1->addWidget(name, 1, 0);
    grid1->addWidget(fullname, 1, 1);
    grid1->addWidget(current, 2, 0);
    grid1->addWidget(currenttime, 2, 1);
    grid1->addWidget(back, 0, 1);

    if (username != "" && s[0] == "+961"){ ///> set user's country flag based on phone number
    countryname->setText("Lebanon");
    grid1->addWidget(countryname, 3, 1);
    flag->setPixmap(QPixmap(":/lebanon.png").scaled(50,30));
    grid1->addWidget(flag, 3, 0);
    }

    else if (username != "" && s[0] == "+1"){ ///> set user's country flag based on phone number
    countryname->setText("USA");
    grid1->addWidget(countryname, 3, 1);
    flag->setPixmap(QPixmap(":/usa.png").scaled(50,30));
    grid1->addWidget(flag, 3, 0);
    }

    else if (username != "" && s[0] == "+966"){ ///> set user's country flag based on phone number
    countryname->setText("KSA");
    grid1->addWidget(countryname, 3, 1);
    flag->setPixmap(QPixmap(":/ksa.png").scaled(50,30));
    grid1->addWidget(flag, 3, 0);
    }

    else if (username != "" && s[0] == "+32"){ ///> set user's country flag based on phone number
    countryname->setText("Belgium");
    grid1->addWidget(countryname, 3, 1);
    flag->setPixmap(QPixmap(":/belgium.png").scaled(50,30));
    grid1->addWidget(flag, 3, 0);
    }

    else if (username != "" && s[0] == "+33"){ ///> set user's country flag based on phone number
    countryname->setText("France");
    grid1->addWidget(countryname, 3, 1);
    flag->setPixmap(QPixmap(":/france.jpg").scaled(50,30));
    grid1->addWidget(flag, 3, 0);
    }

    grid1->addWidget(histor, 4, 0);
    grid1->addWidget(histor2, 4, 1);
    grid1->addWidget(play, 5, 0);
    grid1->addWidget(play2, 5, 1);

    QObject::connect(back, SIGNAL(clicked(bool)), this, SLOT(goback())); ///> go back to sign in page by signing out
    QObject::connect(play, SIGNAL(clicked(bool)), this, SLOT(playgame1())); ///> play game1, battleship game
    QObject::connect(play2, SIGNAL(clicked(bool)), this, SLOT(playgame2())); ///> play game2, shooting discs game
    QObject::connect(histor, SIGNAL(clicked(bool)), this, SLOT(gohistory())); ///> check game1 history
    QObject::connect(histor2, SIGNAL(clicked(bool)), this, SLOT(gohistory2())); ///> check game2 history

    setLayout(grid1);
    setLayout(box);

}
}

/**
*
* \brief signs out and goes to the sign in page
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the user profile page is closed and a sign in page is opened
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/


void profile::goback()
{

    Signin *signin = new Signin();
    signin->show(); ///> open this instance of sign in page
    this->close(); ///> close this instance of profile page
}

/**
*
* \brief enters game1
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the user profile page is closed and battleship game page is opened
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void profile::playgame1()
{
    Battleship *bs = new Battleship(uname);
    bs->show(); ///> open this instance of battleship game page
    this->close(); ///> close this instance of profile page
}

/**
*
* \brief enters game1 history page
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the user profile page is closed and battleship game history page is opened
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void profile::gohistory()
{
    history *h = new history(uname);
    h->show(); ///> open this instance of battleship game history page
    this->close(); ///> close this instance of profile page
}

/**
*
* \brief enters game2 history page
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the user profile page is closed and shooting discs game history page is opened
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void profile::gohistory2()
{
    history2 *h2 = new history2(uname);
    h2->show(); ///> open this instance of shooting discs game history page
    this->close(); ///> close this instance of profile page
}

/**
*
* \brief enters game2
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the user profile page is closed and shooting discs game page is opened
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void profile::playgame2()
{
    disk *d = new disk(uname);
    d->show(); ///> open this instance of shooting discs game page
    this->close(); ///> close this instance of profile page
}

