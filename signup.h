#ifndef SIGNUP_H
#define SIGNUP_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

/**
* \file sigup.h
* \brief sigup class
*
*
*  initialize slots called submitreg(), goback(), browse() which is are void
*  initialize QRadioButton, QLabels, QPushbuttons, etc...
*
*
*/

class SignUp : public QWidget
{
    Q_OBJECT
public:
    QLabel *firstname;
    QLineEdit *firstnametxt;

    QLabel *lastname;
    QLineEdit *lastnametxt;

    QLabel *username;
    QLineEdit *usernametxt;

    QLabel *password;
    QLineEdit *passwordtxt;

    QLabel *gender;
    QRadioButton *male;
    QRadioButton *female;

    QLabel *dob;
    QDateTimeEdit *dobtxt;

    QLabel *profilepicture;
    QPushButton *profilepicturebr;

    QGroupBox *group;

    QLabel *phonenumber;
    QLineEdit *phonenumbertxt;

    QPushButton *submit;

    QString s1;

    QPushButton *back;

    QGridLayout *grid1;
    QVBoxLayout *box;

    QCheckBox *showpass;

    QLineEdit *fullname;
    QComboBox *countrycode;

public:
    explicit SignUp(QWidget *parent = nullptr);

signals:
    private slots:
        void goback();
        void submitreg();
        void browse();
};

#endif // SIGNUP_H
