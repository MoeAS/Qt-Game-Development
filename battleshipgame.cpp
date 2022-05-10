#include "battleshipgame.h"
#include "battleship.h"

/**
* \file battleshipgame.cpp
* \brief contains battleshipgame class definition
*
*
*  it is the battleship game with 2 4x4 grids
*  the right 4x4 grid is the enemy, the left 4x4 grid is the player
*  allows player to play a strategy and thinking game by answering questions provided
*  if the player answers correctly, the playes shoots enemy ship
*  if player answers incorrectly, the player misses the shot and the enemy hits back randomly
*  if the player clicks on a box where an enemy ship is not present, it is a direct miss and attempts are lost every click
*  the player fails if 4 questions are answered incorrectly
*  the player wins if 7 out of 10 question are answered correctly
*  if attempts = 0, the player wins if number of questions correct are more than the incorrect questions answered
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/


int attempt = 16; ///> number of attempts is max 16
int correct = 0; ///> correct answers initialized to 0
int wrong = 0; ///> incorrect answers initialized to 0

battleshipgame::battleshipgame(QString& username, QWidget *parent) : QWidget(parent)
{

    uname = username;
    this->setFixedSize(550, 400);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);

    QPixmap q(":/sea.jpg");
    q = q.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, q);
    this->setPalette(palette);


    QLabel *good = new QLabel("Good Coding Practices");
    QLabel *space = new QLabel("‏‏‎ ‎‏‏‎ ‎‏‏‎ ‎‏‏‎ ‎‏‏‎ ‎‏‏‎ ‎‏‏‎ ‎‏‏‎ ‏‏‎ ‎‏‏‎ ‎‏‏‎ ‎‏‏‎ ‎‏‏‎ ‎‏‏‎ ‏‏‎ ‎‏‏‎ ‎‏‏‎ ‎‏‏‎ ‎‏‏‎ ‎‏‏‎ ‎‎‎");
    QLabel *bad = new QLabel("Bad Coding Practices");
    attempt = 16;
    wrong = 0;
    correct = 0;
    Attempts = new QLabel(QString::number(attempt));
    goback = new QPushButton("Exit Game");

    box = new QVBoxLayout();

    /** setting the 2 4x4 grids of the game */

    btn = new QPushButton("");
    btn1 = new QPushButton("");
    btn2 = new QPushButton("");
    btn3 = new QPushButton("");
    btn4 = new QPushButton("");
    btn5 = new QPushButton("");
    btn6 = new QPushButton("");
    btn7 = new QPushButton("");
    btn8 = new QPushButton("");
    btn9 = new QPushButton("");
    btn10 = new QPushButton("");
    btn11 = new QPushButton("");
    btn12 = new QPushButton("");
    btn13 = new QPushButton("");
    btn14 = new QPushButton("");
    btn15 = new QPushButton("");

    btn->setFixedSize(50,50);
    btn1->setFixedSize(50,50);
    btn2->setFixedSize(50,50);
    btn3->setFixedSize(50,50);
    btn4->setFixedSize(50,50);
    btn5->setFixedSize(50,50);
    btn6->setFixedSize(50,50);
    btn7->setFixedSize(50,50);
    btn8->setFixedSize(50,50);
    btn9->setFixedSize(50,50);
    btn10->setFixedSize(50,50);
    btn11->setFixedSize(50,50);
    btn12->setFixedSize(50,50);
    btn13->setFixedSize(50,50);
    btn14->setFixedSize(50,50);
    btn15->setFixedSize(50,50);

    nbtn = new QPushButton("");
    nbtn1 = new QPushButton("");
    nbtn2 = new QPushButton("");
    nbtn3 = new QPushButton("");
    nbtn4 = new QPushButton("");
    nbtn5 = new QPushButton("");
    nbtn6 = new QPushButton("");
    nbtn7 = new QPushButton("");
    nbtn8 = new QPushButton("");
    nbtn9 = new QPushButton("");
    nbtn10 = new QPushButton("");
    nbtn11 = new QPushButton("");
    nbtn12 = new QPushButton("");
    nbtn13 = new QPushButton("");
    nbtn14 = new QPushButton("");
    nbtn15 = new QPushButton("");

    nbtn->setFixedSize(50,50);
    nbtn1->setFixedSize(50,50);
    nbtn2->setFixedSize(50,50);
    nbtn3->setFixedSize(50,50);
    nbtn4->setFixedSize(50,50);
    nbtn5->setFixedSize(50,50);
    nbtn6->setFixedSize(50,50);
    nbtn7->setFixedSize(50,50);
    nbtn8->setFixedSize(50,50);
    nbtn9->setFixedSize(50,50);
    nbtn10->setFixedSize(50,50);
    nbtn11->setFixedSize(50,50);
    nbtn12->setFixedSize(50,50);
    nbtn13->setFixedSize(50,50);
    nbtn14->setFixedSize(50,50);
    nbtn15->setFixedSize(50,50);

    gr = new QGridLayout();
    box->addLayout(gr);

    good->setFixedSize(150, 20);
    space->setFixedSize(1000, 20);
    gr->addWidget(good, 0,1, Qt::AlignLeft);
    gr->addWidget(space, 0, 4, Qt::AlignHCenter);
    gr->addWidget(btn, 2, 0, Qt::AlignLeft);
    gr->addWidget(btn1, 2, 1, Qt::AlignLeft);
    gr->addWidget(btn2, 2, 2, Qt::AlignLeft);
    gr->addWidget(btn3, 2, 3, Qt::AlignLeft);
    gr->addWidget(btn4, 3, 0, Qt::AlignLeft);
    gr->addWidget(btn5, 3, 1, Qt::AlignLeft);
    gr->addWidget(btn6, 3, 2, Qt::AlignLeft);
    gr->addWidget(btn7, 3, 3, Qt::AlignLeft);
    gr->addWidget(btn8, 4, 0, Qt::AlignLeft);
    gr->addWidget(btn9, 4, 1, Qt::AlignLeft);
    gr->addWidget(btn10, 4, 2, Qt::AlignLeft);
    gr->addWidget(btn11, 4, 3, Qt::AlignLeft);
    gr->addWidget(btn12, 5, 0, Qt::AlignLeft);
    gr->addWidget(btn13, 5, 1, Qt::AlignLeft);
    gr->addWidget(btn14, 5, 2, Qt::AlignLeft);
    gr->addWidget(btn15, 5, 3, Qt::AlignLeft);


    bad->setFixedSize(150, 20);
    gr->addWidget(bad, 0,6, Qt::AlignRight);
    gr->addWidget(nbtn, 2, 5, Qt::AlignRight);
    gr->addWidget(nbtn1, 2, 6, Qt::AlignRight);
    gr->addWidget(nbtn2, 2, 7, Qt::AlignRight);
    gr->addWidget(nbtn3, 2, 8, Qt::AlignRight);
    gr->addWidget(nbtn4, 3, 5, Qt::AlignRight);
    gr->addWidget(nbtn5, 3, 6, Qt::AlignRight);
    gr->addWidget(nbtn6, 3, 7, Qt::AlignRight);
    gr->addWidget(nbtn7, 3, 8, Qt::AlignRight);
    gr->addWidget(nbtn8, 4, 5, Qt::AlignRight);
    gr->addWidget(nbtn9, 4, 6, Qt::AlignRight);
    gr->addWidget(nbtn10, 4, 7, Qt::AlignRight);
    gr->addWidget(nbtn11, 4, 8, Qt::AlignRight);
    gr->addWidget(nbtn12, 5, 5, Qt::AlignRight);
    gr->addWidget(nbtn13, 5, 6, Qt::AlignRight);
    gr->addWidget(nbtn14, 5, 7, Qt::AlignRight);
    gr->addWidget(nbtn15, 5, 8, Qt::AlignRight);

    gr->addWidget(Attempts, 8, 0, Qt::AlignLeft);
    gr->addWidget(goback, 10, 0, Qt::AlignLeft);

    setLayout(box);

    /** shoot by clicking on the right grid */

    QObject::connect(nbtn15, SIGNAL(clicked(bool)), this, SLOT(shoot()));
    QObject::connect(nbtn14, SIGNAL(clicked(bool)), this, SLOT(shoot2()));
    QObject::connect(nbtn13, SIGNAL(clicked(bool)), this, SLOT(shoot3()));
    QObject::connect(nbtn12, SIGNAL(clicked(bool)), this, SLOT(shoot4()));
    QObject::connect(nbtn11, SIGNAL(clicked(bool)), this, SLOT(shoot5()));
    QObject::connect(nbtn10, SIGNAL(clicked(bool)), this, SLOT(shoot6()));
    QObject::connect(nbtn9, SIGNAL(clicked(bool)), this, SLOT(shoot7()));
    QObject::connect(nbtn8, SIGNAL(clicked(bool)), this, SLOT(shoot8()));
    QObject::connect(nbtn7, SIGNAL(clicked(bool)), this, SLOT(shoot9()));
    QObject::connect(nbtn6, SIGNAL(clicked(bool)), this, SLOT(shoot10()));
    QObject::connect(nbtn5, SIGNAL(clicked(bool)), this, SLOT(shoot11()));
    QObject::connect(nbtn4, SIGNAL(clicked(bool)), this, SLOT(shoot12()));
    QObject::connect(nbtn3, SIGNAL(clicked(bool)), this, SLOT(shoot13()));
    QObject::connect(nbtn2, SIGNAL(clicked(bool)), this, SLOT(shoot14()));
    QObject::connect(nbtn1, SIGNAL(clicked(bool)), this, SLOT(shoot15()));
    QObject::connect(nbtn, SIGNAL(clicked(bool)), this, SLOT(shoot16()));

    QObject::connect(goback, SIGNAL(clicked(bool)), this, SLOT(exit()));
    goback->setFixedSize(70, 30);



    //q = new questions();
    //QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test(int)));

}

/**
*
* \brief shoot by clicking one of the right grid squares
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the questions page pops up and if answered correctly its a hit, if answered incorrectly its a miss
*  if no ship is there then its an instant miss
*  the number of attempts are decreased by 1 of every trial
*  miss icon and hit icons are shown for the corresponding situation
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void battleshipgame::shoot(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png"); ///> miss icon when ship is not there
    QIcon ButtonIcon(pixmap);


    ///> randomly see if ship is there or not and do accordingly
    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn15->setIcon(ButtonIcon); nbtn15->setIconSize(QSize(50,50)); nbtn15->setEnabled(false);} ///> if missed then decrease attempt and declare as miss

    if (random == 0){ ///> if not missed then open up the question
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test(int)));}

}

void battleshipgame::shoot2(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn14->setIcon(ButtonIcon); nbtn14->setIconSize(QSize(50,50)); nbtn14->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test2(int)));}
}

void battleshipgame::shoot3(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn13->setIcon(ButtonIcon); nbtn13->setIconSize(QSize(50,50)); nbtn13->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test3(int)));}
}

void battleshipgame::shoot4(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn12->setIcon(ButtonIcon); nbtn12->setIconSize(QSize(50,50)); nbtn12->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test4(int)));}
}

void battleshipgame::shoot5(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn11->setIcon(ButtonIcon); nbtn11->setIconSize(QSize(50,50)); nbtn11->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test5(int)));}
}

void battleshipgame::shoot6(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn10->setIcon(ButtonIcon); nbtn10->setIconSize(QSize(50,50)); nbtn10->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test6(int)));}
}

void battleshipgame::shoot7(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn9->setIcon(ButtonIcon); nbtn9->setIconSize(QSize(50,50)); nbtn9->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test7(int)));}
}

void battleshipgame::shoot8(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn8->setIcon(ButtonIcon); nbtn8->setIconSize(QSize(50,50)); nbtn8->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test8(int)));}
}

void battleshipgame::shoot9(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn7->setIcon(ButtonIcon); nbtn7->setIconSize(QSize(50,50)); nbtn7->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test9(int)));}
}

void battleshipgame::shoot10(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn6->setIcon(ButtonIcon); nbtn6->setIconSize(QSize(50,50)); nbtn6->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test10(int)));}
}

void battleshipgame::shoot11(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn5->setIcon(ButtonIcon); nbtn5->setIconSize(QSize(50,50)); nbtn5->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test11(int)));}
}

void battleshipgame::shoot12(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn4->setIcon(ButtonIcon); nbtn4->setIconSize(QSize(50,50)); nbtn4->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test12(int)));}
}

void battleshipgame::shoot13(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn3->setIcon(ButtonIcon); nbtn3->setIconSize(QSize(50,50)); nbtn3->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test13(int)));}
}

void battleshipgame::shoot14(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn2->setIcon(ButtonIcon); nbtn2->setIconSize(QSize(50,50)); nbtn2->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test14(int)));}
}

void battleshipgame::shoot15(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn1->setIcon(ButtonIcon); nbtn1->setIconSize(QSize(50,50)); nbtn1->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test15(int)));}
}

void battleshipgame::shoot16(){
    int random = rand() % 2;

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    if (random == 1) {Attempts->setText(QString::number(attempt-=1)); nbtn->setIcon(ButtonIcon); nbtn->setIconSize(QSize(50,50)); nbtn->setEnabled(false);}

    if (random == 0){
    q = new questions();
    q->show();
    QObject::connect(q, SIGNAL(sigemit(int)), this, SLOT(test16(int)));}
}

/**
*
* \brief shoot by clicking one of the right grid squares
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the questions page pops up and if answered correctly its a hit, if answered incorrectly its a miss
*  if no ship is there then its an instant miss
*  the number of attempts are decreased by 1 of every trial
*  miss icon and hit icons are shown for the corresponding situation
*  when attempts = 0 the game is closed and declared if winner or loser
*  prompts message to the user if won or lost
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void battleshipgame::test(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);


    if (x == 1){ nbtn15->setIcon(ButtonIcon2); nbtn15->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;} ///> if hit then declare as hit and increase correct counter and decrease attempt counter
    else {nbtn15->setIcon(ButtonIcon); nbtn15->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); wrong += 1; ///> if wrong then declare as miss and increase wrong counter and decrease attempt counter
        int i = 1;
    while (i == 1){  ///> if wrong then randomly shoot a square from the grid from the user side
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
    else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
    else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
    else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
    else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
   else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
    else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
    else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
    else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
    else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
    else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
    else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
    else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
    else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
    else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
    else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
    }
    }
    nbtn15->setEnabled(false);

    if (wrong == 4){ ///> check number of wrongs if exceeded
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){ ///> check number of corrects if exceeded
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){ ///> check number of attempts if reached
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }

}

void battleshipgame::test2(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn14->setIcon(ButtonIcon); nbtn14->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
    else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
    else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
    else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
    else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
   else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
    else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
    else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
    else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
    else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
    else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
    else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
    else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
    else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
    else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
    else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
    }
    }
    nbtn14->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

void battleshipgame::test3(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn13->setIcon(ButtonIcon2); nbtn13->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn13->setIcon(ButtonIcon); nbtn13->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
    else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
    else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
    else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
    else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
   else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
    else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
    else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
    else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
    else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
    else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
    else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
    else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
    else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
    else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
    else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
    }
    }
    nbtn13->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}


void battleshipgame::test4(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn12->setIcon(ButtonIcon2); nbtn12->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn12->setIcon(ButtonIcon); nbtn12->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
    else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
    else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
    else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
    else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
   else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
    else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
    else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
    else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
    else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
    else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
    else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
    else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
    else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
    else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
    else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
    }
    }
    nbtn12->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

void battleshipgame::test5(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn11->setIcon(ButtonIcon2); nbtn11->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn11->setIcon(ButtonIcon); nbtn11->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
    else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
    else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
    else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
    else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
   else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
    else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
    else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
    else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
    else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
    else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
    else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
    else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
    else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
    else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
    else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
    }
    }
    nbtn11->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

void battleshipgame::test6(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn10->setIcon(ButtonIcon2); nbtn10->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn10->setIcon(ButtonIcon); nbtn10->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
    else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
    else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
    else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
    else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
   else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
    else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
    else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
    else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
    else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
    else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
    else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
    else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
    else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
    else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
    else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
    }
    }
    nbtn10->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

void battleshipgame::test7(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn9->setIcon(ButtonIcon2); nbtn9->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn9->setIcon(ButtonIcon); nbtn9->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
    else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
    else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
    else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
    else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
   else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
    else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
    else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
    else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
    else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
    else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
    else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
    else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
    else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
    else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
    else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
    }
    }
    nbtn9->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

void battleshipgame::test8(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn8->setIcon(ButtonIcon2); nbtn8->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn8->setIcon(ButtonIcon); nbtn8->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
    else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
    else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
    else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
    else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
   else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
    else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
    else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
    else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
    else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
    else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
    else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
    else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
    else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
    else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
    else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
    }
    }
    nbtn8->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

void battleshipgame::test9(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn7->setIcon(ButtonIcon2); nbtn7->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn7->setIcon(ButtonIcon); nbtn7->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
        else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
        else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
        else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
        else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
       else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
        else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
        else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
        else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
        else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
        else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
        else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
        else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
        else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
        else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
        else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
        }
    }
    nbtn7->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

void battleshipgame::test10(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn6->setIcon(ButtonIcon2); nbtn6->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn6->setIcon(ButtonIcon); nbtn6->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
        else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
        else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
        else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
        else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
       else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
        else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
        else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
        else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
        else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
        else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
        else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
        else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
        else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
        else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
        else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
        }
    }
    nbtn6->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

void battleshipgame::test11(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn5->setIcon(ButtonIcon2); nbtn5->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn5->setIcon(ButtonIcon); nbtn5->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
        else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
        else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
        else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
        else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
       else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
        else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
        else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
        else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
        else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
        else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
        else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
        else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
        else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
        else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
        else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
        }
    }
    nbtn5->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

void battleshipgame::test12(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn4->setIcon(ButtonIcon2); nbtn4->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn4->setIcon(ButtonIcon); nbtn4->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
        else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
        else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
        else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
        else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
       else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
        else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
        else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
        else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
        else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
        else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
        else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
        else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
        else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
        else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
        else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
        }
    }
    nbtn4->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

void battleshipgame::test13(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn3->setIcon(ButtonIcon2); nbtn3->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn3->setIcon(ButtonIcon); nbtn3->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
        else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
        else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
        else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
        else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
       else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
        else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
        else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
        else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
        else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
        else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
        else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
        else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
        else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
        else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
        else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
        }
    }
    nbtn3->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

void battleshipgame::test14(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn2->setIcon(ButtonIcon2); nbtn2->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn2->setIcon(ButtonIcon); nbtn2->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
        else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
        else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
        else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
        else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
       else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
        else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
        else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
        else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
        else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
        else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
        else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
        else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
        else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
        else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
        else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
        }
    }
    nbtn2->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

void battleshipgame::test15(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn1->setIcon(ButtonIcon2); nbtn1->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn1->setIcon(ButtonIcon); nbtn1->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
        else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
        else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
        else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
        else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
       else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
        else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
        else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
        else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
        else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
        else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
        else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
        else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
        else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
        else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
        else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
        }
    }
    nbtn1->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

void battleshipgame::test16(int x){

    QPixmap pixmap(":/miss.png");
    QIcon ButtonIcon(pixmap);

    QPixmap pixmap2(":/hit.jpg");
    QIcon ButtonIcon2(pixmap2);

    if (x == 1){ nbtn->setIcon(ButtonIcon2); nbtn->setIconSize(QSize(50,50)); Attempts->setText(QString::number(attempt-=1)); correct+=1;}
    else {nbtn->setIcon(ButtonIcon); nbtn->setIconSize(QSize(50,50));Attempts->setText(QString::number(attempt-=1)); wrong += 1;
        int i = 1;
    while (i == 1){
    int random = rand() % 16;
    if (random == 0 && btn->isEnabled() == true) {btn->setIcon(ButtonIcon2); btn->setIconSize(QSize(50,50)); btn->setEnabled(false);i = 2; break;}
        else if (random == 1&& btn1->isEnabled() == true) {btn1->setIcon(ButtonIcon2); btn1->setIconSize(QSize(50,50)); btn1->setEnabled(false); i = 2; break;}
        else if (random == 2&& btn2->isEnabled() == true) {btn2->setIcon(ButtonIcon2); btn2->setIconSize(QSize(50,50)); btn2->setEnabled(false);i = 2; break;}
        else if (random == 3&& btn3->isEnabled() == true) {btn3->setIcon(ButtonIcon2); btn3->setIconSize(QSize(50,50)); btn3->setEnabled(false);i = 2; break;}
        else if (random == 4&& btn4->isEnabled() == true) {btn4->setIcon(ButtonIcon2); btn4->setIconSize(QSize(50,50)); btn4->setEnabled(false);i = 2; break;}
       else  if (random == 5&& btn5->isEnabled() == true) {btn5->setIcon(ButtonIcon2); btn5->setIconSize(QSize(50,50)); btn5->setEnabled(false);i = 2; break;}
        else if (random == 6&& btn6->isEnabled() == true) {btn6->setIcon(ButtonIcon2); btn6->setIconSize(QSize(50,50)); btn6->setEnabled(false);i = 2; break;}
        else if (random == 7&& btn7->isEnabled() == true) {btn7->setIcon(ButtonIcon2); btn7->setIconSize(QSize(50,50)); btn7->setEnabled(false);i = 2; break;}
        else if (random == 8&& btn8->isEnabled() == true) {btn8->setIcon(ButtonIcon2); btn8->setIconSize(QSize(50,50)); btn8->setEnabled(false);i = 2; break;}
        else if (random == 9&& btn9->isEnabled() == true) {btn9->setIcon(ButtonIcon2); btn9->setIconSize(QSize(50,50)); btn9->setEnabled(false);i = 2; break;}
        else if (random == 10&& btn10->isEnabled() == true) {btn10->setIcon(ButtonIcon2); btn10->setIconSize(QSize(50,50)); btn10->setEnabled(false);i = 2; break;}
        else if (random == 11&& btn11->isEnabled() == true) {btn11->setIcon(ButtonIcon2); btn11->setIconSize(QSize(50,50)); btn11->setEnabled(false);i = 2; break;}
        else if (random == 12&& btn12->isEnabled() == true) {btn12->setIcon(ButtonIcon2); btn12->setIconSize(QSize(50,50)); btn12->setEnabled(false);i = 2; break;}
        else if (random == 13&& btn13->isEnabled() == true) {btn13->setIcon(ButtonIcon2); btn13->setIconSize(QSize(50,50)); btn13->setEnabled(false);i = 2; break;}
        else if (random == 14&& btn14->isEnabled() == true) {btn14->setIcon(ButtonIcon2); btn14->setIconSize(QSize(50,50)); btn14->setEnabled(false);i = 2; break;}
        else if (random == 15&& btn15->isEnabled() == true) {btn15->setIcon(ButtonIcon2); btn15->setIconSize(QSize(50,50)); btn15->setEnabled(false);i = 2; break;}
        }
    }
    nbtn->setEnabled(false);

    if (wrong == 4){
        QMessageBox msg;
        msg.setText("Better luck next time!");
        msg.exec();
        exit();
    }

    else if (correct == 7){
        QMessageBox msg;
        msg.setText("Good Job!");
        msg.exec();
        exit();
    }

    else if (attempt == 0){
        if (correct > wrong){
                QMessageBox msg;
                msg.setText("Good job!");
                msg.exec();
                exit();
        }
        else{
            QMessageBox msg;
            msg.setText("Better luck next time!");
            msg.exec();
            exit();
        }
    }
}

/**
*
* \brief player exits when game is done and scores are saved
*
*
*  when the player finishes the trials the scores are saved in Scores.txt file
*  battleship game closes and opens the game menu
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void battleshipgame::exit(){

    QFile file("/home/eece435l/Project435L/Scores.txt"); ///> opens text file


    if(file.open(QIODevice::ReadWrite | QFile::Text)){
            //QMessageBox::information(0,"Error",file.errorString());
        QTextStream out(&file);

         out << uname + "|";
         out << QString::number(correct) + "correct & " + QString::number(wrong) + "wrong" + "|"; ///> saves number of correct and wrong answers answered
         out << "\n";
    }

    Battleship *b = new Battleship(uname);
    b->show();
    this->close(); ///> closes game
}

/*
int battleshipgame::question()
{
    QRadioButton *True = new QRadioButton("True");
    QRadioButton *False = new QRadioButton("False");

    QLabel *ques = new QLabel("");


    QFile file("/home/eece435l/Project435L/Questions.txt");

    if(file.open(QIODevice::ReadOnly | QFile::Text)){

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

    }
    int j = 1;
    while(j == 1){
        if (True->isChecked()){
            if(file.open(QIODevice::ReadOnly | QFile::Text)){
                    //QMessageBox::information(0,"Error",file.errorString());
                QTextStream out(&file);
            while(!out.atEnd()){
                QString line = out.readLine();
                if((ques->text() == line.section("|",1,1) && "True" == line.section("|",2,2))){
                    file.close();
                    j=0;
                    return 1;
            }

        }

        }
        }
        else if(False->isChecked()) {
                if(file.open(QIODevice::ReadOnly | QFile::Text)){
                        //QMessageBox::information(0,"Error",file.errorString());
                    QTextStream out(&file);
                while(!out.atEnd()){
                    QString line = out.readLine();
                    if((ques->text() == line.section("|",1,1) && "False" == line.section("|",2,2))){
                        file.close();
                        j=0;
                        return 0;
                }

            }

            }
        }
        file.close();

}

}
*/
