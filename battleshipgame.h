#ifndef BATTLESHIPGAME_H
#define BATTLESHIPGAME_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QTextTableCell>
#include "questions.h"

/**
* \file battleshipgame.h
* \brief battleshipgame class
*
*
*  initialize global variables attempts, wrong, correct, a public slot called exit() which is a void, public slot called shoot() which is a void, public slots called test() which is a void
*
*
*/


class battleshipgame : public QWidget
{
    Q_OBJECT

    QPushButton *goback;
    QString uname;
    QVBoxLayout *box;
    QGridLayout *gr;
    QTableWidget *table;
    QPushButton *btn;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btn10;
    QPushButton *btn11;
    QPushButton *btn12;
    QPushButton *btn13;
    QPushButton *btn14;
    QPushButton *btn15;
    QPushButton *nbtn;
    QPushButton *nbtn1;
    QPushButton *nbtn2;
    QPushButton *nbtn3;
    QPushButton *nbtn4;
    QPushButton *nbtn5;
    QPushButton *nbtn6;
    QPushButton *nbtn7;
    QPushButton *nbtn8;
    QPushButton *nbtn9;
    QPushButton *nbtn10;
    QPushButton *nbtn11;
    QPushButton *nbtn12;
    QPushButton *nbtn13;
    QPushButton *nbtn14;
    QPushButton *nbtn15;
    questions *q;
    QLabel *Attempts;


public:
    battleshipgame(QString& username, QWidget *parent = nullptr);


//signals:
    //private slots:
        //void exit();
        //int question();

public slots:
    void shoot();
    void shoot2();
    void shoot3();
    void shoot4();
    void shoot5();
    void shoot6();
    void shoot7();
    void shoot8();
    void shoot9();
    void shoot10();
    void shoot11();
    void shoot12();
    void shoot13();
    void shoot14();
    void shoot15();
    void shoot16();
    void test(int x);
    void test2(int x);
    void test3(int x);
    void test4(int x);
    void test5(int x);
    void test6(int x);
    void test7(int x);
    void test8(int x);
    void test9(int x);
    void test10(int x);
    void test11(int x);
    void test12(int x);
    void test13(int x);
    void test14(int x);
    void test15(int x);
    void test16(int x);
    void exit();


};
extern int attempt; ///> global variable number of attempts
extern int correct; ///> global variable number of correct answers
extern int wrong; ///> global variable number of incorrect answers
#endif // BATTLESHIPGAME_H
