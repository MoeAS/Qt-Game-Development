#include "reddisk.h"
#include "disks.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "disk.h"

/**
* \file reddisk.cpp
* \brief contains disk pad of red disk class definition
*
*
*  scales red disk to a 40x40 scale
*  sets position of the red disk pad at 0, 340
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

reddisk::reddisk(QString& username)
{
    uname = username;
    setPixmap((QPixmap(":/reddisk.png").scaled(40,40))); ///> set scale
    setPos(0, 340); ///> set position

}

/**
*
* \brief spawn disks and add them to the scene for them to fall from above and checks number of attempts
*
*
*  checks for number of attempts
*  if attempts reach zero the player wins or loses depending on the score
*  the score is saved in Scores2.txt file
*
*  spawns disk depending on timer used in diskgame.cpp which is set to 1500 ms
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void reddisk::spawn(){

    if (attempts == 0){  ///> when attempts reach zero it checks if the player wins or loses
        disk *d = new disk(uname);
        d->show();
        this->scene()->deleteLater();
        if (totalscore < 150){  ///> if less than 150 points player loses and his/her score is saved in Scores2.txt
        QMessageBox msg;
        msg.setText("Your score is: "+QString::number(totalscore) + ", You Lose!");
        msg.exec();

        QFile file("/home/eece435l/Project435L/Scores2.txt"); ///> open text file to save score


        if(file.open(QIODevice::ReadWrite | QFile::Text)){

            QTextStream out(&file);

             out << uname + "|";
             out << "red points = " + QString::number(red) + "; " + "blue points = " + QString::number(blue) + "; " + "green points = " + QString::number(green) + "; " + "total score = " + QString::number(totalscore) + "|";
             out << "\n";
        }
        }
        else { ///> if greater than 150 points player wins and his/her score is saved in Scores2.txt along with the bonus points
            QMessageBox msg;
            msg.setText("Your score is: "+QString::number(totalscore) + ", You Win!");
            msg.exec();

            QFile file("/home/eece435l/Project435L/Scores2.txt"); ///> open text file to save score


            if(file.open(QIODevice::ReadWrite | QFile::Text)){

                QTextStream out(&file);

                 out << uname + "|";
                 out << "red points = " + QString::number(red) + "; " + "blue points = " + QString::number(blue) + "; " + "green points = " + QString::number(green) + "; " + "total score = " + QString::number(totalscore) + "; Bonus Points Gained = " + QString::number(totalscore - 150) + "|";
                 out << "\n";
            }
        }



        return;
    }

        disks *d = new disks(uname); ///> spawns a new disk each timer which is set to 1.5 seconds
        scene()->addItem(d); ///> adds disk to the scene

}

