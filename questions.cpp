#include "questions.h"
#include "battleshipgame.h"

/**
* \file questions.cpp
* \brief contains questions to be asked at every turn of the battleship game
*
*
*  provides questions at random saved in Questions.txt
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

questions::questions(QWidget *parent) : QWidget(parent)
{

    /**
    * initalizing all QLabels, QRadioButtons, and QPushButtons to display on the screen
    */

    True = new QRadioButton("True");
    False = new QRadioButton("False");
    ok = new QPushButton("Submit");

    ques = new QLabel("");

    grid = new QGridLayout();

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y); ///> move window to center of the screen

    QFile file("/home/eece435l/Project435L/Questions.txt"); ///> read questions from txt file

    if(file.open(QIODevice::ReadOnly | QFile::Text)){

        QTextStream u1(&file);
        int i = 0;
        int random = rand() % 9;

        while(!u1.atEnd()){
            QString line = u1.readLine();
            if (i == random && line!=""){
                ques->setText(line.section("|",0,0));
                break;
            }
            i++;

        }

    }

    grid->addWidget(ques, 0, 0);
    grid->addWidget(True, 1, 0);
    grid->addWidget(False, 1, 1);
    grid->addWidget(ok, 3, 0);


    setLayout(grid);

    QObject::connect(ok, SIGNAL(clicked(bool)), this, SLOT(submit())); ///> when submitted it checks if answered correctly or not

}

/**
*
* \brief Submits the input provided from the user and checks if answered correctly
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the window closes and returns to the battleship game
*  the questions are stored in txt file called Questions.txt
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

int questions::submit(){

    QFile file("/home/eece435l/Project435L/Questions.txt"); ///> open text file

   /* if(file.open(QIODevice::ReadOnly | QFile::Text)){

        QTextStream u1(&file);
        int i = 0;
        int random = rand() % 12;

        while(!u1.atEnd()){
            QString line = u1.readLine();
            QStringList list = line.split("|");
            if (i == random){
                ques->setText(line.section("|",1,1));
                break;
            }


        }

    }*/
        if (True->isChecked()){ ///> checks answer if user inputs True
            if(file.open(QIODevice::ReadOnly | QFile::Text)){
                    //QMessageBox::information(0,"Error",file.errorString());
                QTextStream out(&file);
            while(!out.atEnd()){
                QString line = out.readLine();
                if((ques->text() == line.section("|",0,0) && "True" == line.section("|",1,1))){
                    file.close();
                    this->close();
                    emit sigemit(1);
                    return 1;
            }

        }
            file.close();
            this->close();
            emit sigemit(-1);
            return -1;

        }
        }
        else if(False->isChecked()) { ///> checks answer if user inputs False
                if(file.open(QIODevice::ReadOnly | QFile::Text)){
                        //QMessageBox::information(0,"Error",file.errorString());
                    QTextStream out(&file);
                while(!out.atEnd()){
                    QString line = out.readLine();
                    if((ques->text() == line.section("|",0,0) && "False" == line.section("|",1,1))){
                        file.close();
                        this->close();
                        emit sigemit(1);
                        return 1;
                }

            }
                file.close();
                this->close();
                emit sigemit(-1);
                return -1;

            }
        }


        file.close();

}
