#include "signin.h"
#include "signup.h"
#include "profile.h"

/**
* \file signin.cpp
* \brief contains sign in class definition
*
*
*  allows user to sign in and checks username and password in a txt file called Database.txt if the credentials are correct or invalid
*  user can play as a guest if they don't want to sign up
*  user can navigate to the sign up page
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

Signin::Signin(QWidget *parent) : QWidget(parent)
{


    this->setStyleSheet("background-color: grey; color: white;"); ///> change the sign in background and text color

    this->setFixedSize(400,200); ///> scales window to 400x200

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y); ///> moves window to the center of the screen when opened

    /**
    * initalizing all QLabels, QLineEdits, QRadioButtons, and QPushButtons to display on the screen
    */

    username = new QLabel("Username");
    usernametxt = new QLineEdit();
    password = new QLabel("Password");
    passwordtxt = new QLineEdit();
    passwordtxt->setEchoMode(QLineEdit::Password);
    submit = new QPushButton("Sign In");
    submit->setCursor(Qt::PointingHandCursor);
    signup = new QPushButton("Sign Up");
    signup->setCursor(Qt::PointingHandCursor);
    guest = new QPushButton("Play As A Guest");
    guest->setCursor(Qt::PointingHandCursor);
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addStretch(1);


    grid1 = new QGridLayout();
    box = new QVBoxLayout();

    box->addLayout(grid1);

    grid1->addWidget(username, 1, 3);
    grid1->addWidget(usernametxt, 2, 3);
    grid1->addWidget(password, 4, 3);
    grid1->addWidget(passwordtxt, 5, 3);
    //grid1->addWidget(name, 2, 0);
    //grid1->addWidget(nametxt, 2, 1);

    box->addLayout(grid1);

    //grid1->addItem(new QSpacerItem(50,10), 8, 3, 1, 1);
    grid1->addWidget(submit, 7, 3);
    grid1->addWidget(signup, 9, 0);

    grid1->addWidget(guest, 9, 8);

    QObject::connect(signup, SIGNAL(clicked(bool)), this, SLOT(signuppage())); ///> navigate to the sign up page
    QObject::connect(submit, SIGNAL(clicked(bool)), this, SLOT(signinvalidation())); ///> checks if the input credentials are correct
    QObject::connect(guest, SIGNAL(clicked(bool)), this, SLOT(playasguest())); ///> user can play as a guest if they don't want to sign up

    setLayout(grid1);
    setLayout(box);

}

/**
*
* \brief goes to the sign up page
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the sign in page is closed and a sign up page is opened
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void Signin::signuppage()
{

    SignUp *signup = new SignUp();
    Signin *signin;
    signin->close(); ///> close this instance of sign in page
    signup->show(); ///> open new instance of sign up page

}

/**
*
* \brief checks whether the input credentials are correct or invalid
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the Database.txt file is checked if username and password match of the user input
*  checks if all fields are filled and not empty
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void Signin::signinvalidation()
{

    if(this->usernametxt->text().isEmpty()){ ///> check username field if empty
        QMessageBox msg;
        msg.setText("Enter a username!");
        msg.exec();
        return;
    }
    else if(this->passwordtxt->text().isEmpty()){ ///> check password field if empty
        QMessageBox msg;
        msg.setText("Enter a password!");
        msg.exec();
        return;
    }

    QFile file("/home/eece435l/Project435L/Database.txt"); ///> open text file

    if(file.open(QIODevice::ReadOnly | QFile::Text)){

        QTextStream u1(&file);
        bool si = false;

        while(!u1.atEnd()){
            QString line = u1.readLine();
            if((this->usernametxt->text()== line.section("|",1,1)) && (this->passwordtxt->text()== line.section("|",2,2))){ ///> check if the username and password are correct
                si = true;
                break;
        }

    }
        if (si == true){
            QMessageBox msg;
            msg.setText("Account Signed in!"); ///> if correct sign in and go to the profile page
            msg.exec();


            QString uname = this->usernametxt->text();

            profile *p1 = new profile(uname);
            this->close();
            p1->show();
        }
        else {
            QMessageBox msg;
            msg.setText("Wrong username or password!"); ///> if incorrect, prompt the user with a message
            msg.exec();
        }

        file.close();

}

}

/**
*
* \brief user can play as a guest without signing up
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the sign in page is closed and a profile page is opened
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void Signin::playasguest()
{
    QString uname = this->usernametxt->text();

    profile *p1 = new profile(uname);
    this->close(); ///> sign in instance is closed
    p1->show(); ///> profile instance is opened

}




