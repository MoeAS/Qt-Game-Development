#ifndef SIGNIN_H
#define SIGNIN_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

/**
* \file sigin.h
* \brief sigin class
*
*
*  initialize slots called signuppage(), signinvalidation(), playasguest() which is are void
*  initialize QRadioButton, QLabels, QPushbuttons, etc...
*
*
*/

class Signin : public QWidget
{
    Q_OBJECT

public:
    QLabel *username;
    QLineEdit *usernametxt;

    QLabel *password;
    QLineEdit *passwordtxt;

    QPushButton *signup;

    QPushButton *guest;

    QPushButton *submit;

    QGridLayout *grid1;
    QVBoxLayout *box;

public:
    explicit Signin(QWidget *parent = nullptr);

signals:
    private slots:
        void signuppage();
        void signinvalidation();
        void playasguest();
};

#endif // SIGNIN_H
