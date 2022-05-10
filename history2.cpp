#include "history2.h"
#include "profile.h"

/**
* \file history2.cpp
* \brief contains user history of game2 which is the shooting discs game
*
* keeps track of user scores which are saved in Scores2.txt file
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

history2::history2(QString& username, QWidget *parent) : QWidget(parent)
{

    uname = username;

    this->setFixedSize(600, 300);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);

    grid = new QGridLayout();

    hist = new QLabel();

    QLabel *scores = new QLabel("Scores: ");

    back = new QPushButton("Go Back");

    QFile file("/home/eece435l/Project435L/Scores2.txt"); ///> check Scores2.txt file to display on screen

    if(file.open(QIODevice::ReadOnly | QFile::Text)){

        QTextStream u1(&file);



        while(!u1.atEnd()){
            QString line = u1.readLine();
            if((username == line.section("|",0,0))){

                QStringList histlist = line.split("|");

                int i = 1;
                while (i < histlist.length()){


                    QString elements = histlist.at(i);

                    QString temp = hist->text();

                    temp.append(elements + "\n");

                    hist->setText(temp);

                    i++;
                }

        }
        }


    file.close();

    }

    grid->addWidget(scores, 0, 0);
    grid->addWidget(hist, 1, 0);
    grid->addWidget(back, 4, 0);

    setLayout(grid);

    QObject::connect(back, SIGNAL(clicked(bool)), this, SLOT(goback())); ///> go back to user profile page

}

/**
*
* \brief goes back to profile page
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the user history of game2 page is closed and profile page is opened
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void history2::goback(){
    profile *p = new profile(uname);
    p->show();
    this->close();

}

