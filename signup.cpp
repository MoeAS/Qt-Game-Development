#include "signup.h"
#include "signin.h"
#include <QFile>

/**
* \file signup.cpp
* \brief contains sign up class definition
*
*
*  allows user to sign up and saves the data provided in a txt file called Database.txt
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

SignUp::SignUp(QWidget *parent) : QWidget(parent)
{

    this->setStyleSheet("background-color: grey; color: white;"); ///> change the sign up background and text color

    this->setFixedSize(400,300); ///> scales window to 400x300

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y); ///> moves window to the center of the screen when opened

    //showpass = new QCheckBox("Show Password");

    /**
    * initalizing all QLabels, QLineEdits, QRadioButtons, and QPushButtons to display on the screen
    */

    username = new QLabel("Username");
    usernametxt = new QLineEdit();
    password = new QLabel("Password");
    passwordtxt = new QLineEdit();
    passwordtxt->setEchoMode(QLineEdit::Password);
    //passwordtxt->setEchoMode(showpass->checkState() == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password);
    submit = new QPushButton("Submit");
    submit->setCursor(Qt::PointingHandCursor);
    gender = new QLabel("Gender");
    male = new QRadioButton("Male");
    female = new QRadioButton("Female");
    firstname = new QLabel("First Name");
    firstnametxt = new QLineEdit();
    lastname = new QLabel("Last Name");
    lastnametxt = new QLineEdit();
    profilepicturebr = new QPushButton("Browse");
    profilepicturebr->setCursor(Qt::PointingHandCursor);
    profilepicture = new QLabel("Profile Picture");
    countrycode = new QComboBox();
    phonenumber = new QLabel("Phone Number");
    QValidator *v = new QIntValidator(0, 9999999999, this);
    phonenumbertxt = new QLineEdit();
    this->phonenumbertxt->setValidator(v);
    dob = new QLabel("Date of Birth");
    dobtxt = new QDateTimeEdit();
    dobtxt->setDisplayFormat("MM-dd-yyyy");
    back = new QPushButton("<-- Go Back");
    back->setCursor(Qt::PointingHandCursor);
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addStretch(1);

    countrycode->addItem(QIcon(":/lebanon.png"), "+961");
    countrycode->addItem(QIcon(":/usa.png"), "+1");
    countrycode->addItem(QIcon(":/ksa.png"), "+966");
    countrycode->addItem(QIcon(":/belgium.png"), "+32");
    countrycode->addItem(QIcon(":/france.jpg"), "+33");


    grid1 = new QGridLayout();
    box = new QVBoxLayout();

    box->addLayout(grid1);


    grid1->addWidget(firstname, 0, 0);
    grid1->addWidget(firstnametxt, 0, 1);
    grid1->addWidget(lastname, 1, 0);
    grid1->addWidget(lastnametxt, 1, 1);
    grid1->addWidget(dob, 0, 6);
    grid1->addWidget(dobtxt, 1, 6);


    grid1->addWidget(username, 2, 0);
    grid1->addWidget(usernametxt, 2, 1);
    grid1->addWidget(password, 3, 0);
    grid1->addWidget(passwordtxt, 3, 1);
    //grid1->addWidget(showpass, 3, 2, 1, 5);

    grid1->addWidget(gender, 4, 0);
    grid1->addWidget(male, 4, 1);
    grid1->addWidget(female, 5, 1);

    grid1->addItem(new QSpacerItem(50,10), 0, 3, 1, 1);

    grid1->addWidget(phonenumber, 7, 0, 1, 5);
    grid1->addWidget(countrycode, 7, 1);
    grid1->addWidget(phonenumbertxt, 7, 2, 1, 5);

    grid1->addWidget(profilepicture, 8, 0);
    grid1->addWidget(profilepicturebr, 8, 1);

    grid1->addWidget(back, 13, 0);

    //grid1->addWidget(name, 2, 0);
    //grid1->addWidget(nametxt, 2, 1);

    box->addLayout(grid1);

    //grid1->addItem(new QSpacerItem(50,10), 8, 3, 1, 1);
    grid1->addItem(new QSpacerItem(50,10), 8, 3, 1, 1);
    grid1->addWidget(submit, 11, 1);

    grid1->addItem(new QSpacerItem(50,10), 8, 3, 1, 1);

    QObject::connect(back, SIGNAL(clicked(bool)), this, SLOT(goback())); ///> navigate back to the sign in page which is the main page of this program
    QObject::connect(submit, SIGNAL(clicked(bool)), this, SLOT(submitreg())); ///> user submits the provided data
    QObject::connect(profilepicturebr, SIGNAL(clicked(bool)), this, SLOT(browse())); ///> browse the computer to insert a picture

    setLayout(grid1);
    setLayout(box);

}

/**
*
* \brief goes back to the sign in page which is the main page
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the sign up page is closed and a sign in page is opened
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void SignUp::goback()
{

    Signin *signin = new Signin();
    signin->show(); ///> show instance of the sign in page
    this->close(); ///> close this instance of sign up page
}

/**
*
* \brief Submits the data provided from the user to sign up and checks if username is taken or not
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the sign up page is closed and a sign in page is opened
*  the data is stored in txt file called Database.txt
*  it checks whether the username is taken since the username is a unique key
*  it checks if all of the fields are filled, and for valid phone number
*  and password of at least 8 characters and contains at least one number, upper, and lower case letters
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void SignUp::submitreg()
{


    QMessageBox msg;
    //QTextStream out(&file);
    int upper = 0;
    int lower = 0;
    int digit = 0;

    if (this->firstnametxt->text().isEmpty()){ ///> check if firstname field is empty
        msg.setText("Please enter your firstname!");
        msg.exec();
        return;
    }

    if (this->lastnametxt->text().isEmpty()){ ///> check if lastname field is empty
        msg.setText("Please enter your lastname!");
        msg.exec();
        return;
    }

    if (this->usernametxt->text().isEmpty()){ ///> check if username field is empty
        msg.setText("Please enter a username!");
        msg.exec();
        return;
    }

    if (this->passwordtxt->text().isEmpty()){ ///> check if password field is empty
        msg.setText("Please enter a password!");
        msg.exec();
        return;
    }

    if (this->phonenumbertxt->text().isEmpty()){ ///> check if phonenumber field is empty
        msg.setText("Please enter your phone number!");
        msg.exec();
        return;
    }

    if (this->countrycode->currentText() == "+961" && this->phonenumbertxt->text().length() != 8){ ///> check if phonenumber field is valid for country specified, here it is Lebanon
        msg.setText("Please enter a valid phone number!");
        msg.exec();
        return;
    }
    else if(this->countrycode->currentText() == "+1" && this->phonenumbertxt->text().length() != 10){ ///> check if phonenumber field is valid for country specified, here it is USA
        msg.setText("Please enter a valid phone number!");
        msg.exec();
        return;
    }
    else if(this->countrycode->currentText() == "+966" && this->phonenumbertxt->text().length() != 9){ ///> check if phonenumber field is valid for country specified, here it is Saudi Arabia
        msg.setText("Please enter a valid phone number!");
        msg.exec();
        return;
    }
    else if(this->countrycode->currentText() == "+32" && this->phonenumbertxt->text().length() != 9){ ///> check if phonenumber field is valid for country specified, here it is Belgium
        msg.setText("Please enter a valid phone number!");
        msg.exec();
        return;
    }
    else if(this->countrycode->currentText() == "+33" && this->phonenumbertxt->text().length() != 9){ ///> check if phonenumber field is valid for country specified, here it is France
        msg.setText("Please enter a valid phone number!");
        msg.exec();
        return;
    }


    if (this->dobtxt->text().isEmpty()){ ///> check if date of birth field is empty
        msg.setText("Please enter your date of birth!");
        msg.exec();
        return;
    }


    if (this->passwordtxt->text().length() < 8){ ///> check if password requirements are met
        msg.setText("Password should contain at least 8 characters, at least one digit, upper and lower case characters!");
        msg.exec();
        return;
    }

    for ( const auto& character : passwordtxt->text() )
    {
        if ( character.isUpper() )
        {
            upper++;
        }
        else if ( character.isLower() )
        {
            lower++;
        }
        else if ( character.isDigit() )
        {
            digit++;
        }
    }


    if (upper < 1)
    {
        msg.setText("Password should contain at least 8 characters, at least one digit, upper and lower case characters!");
        msg.exec();
        return;
    }
    if (lower < 1)
    {
        msg.setText("Password should contain at least 8 characters, at least one digit, upper and lower case characters!");
        msg.exec();
        return;
    }
    if (digit < 1)
    {
        msg.setText("Password should contain at least 8 characters, at least one digit, upper and lower case characters!");
        msg.exec();
        return;
    }

    QFile file("/home/eece435l/Project435L/Database.txt"); ///> text file is open to save the data input


    if(file.open(QIODevice::ReadWrite | QFile::Text)){
            //QMessageBox::information(0,"Error",file.errorString());
        QTextStream out(&file);
        bool si = true;

        while(!out.atEnd()){
            QString line = out.readLine();
            if((this->usernametxt->text() == line.section("|",1,1))){ ///> check if username already taken
                si = false;
                break;
        }

    }
        if (si == false){
            msg.setText("Error: Username already taken!"); ///> if username take prompt user with message
            msg.exec();
        }
        else { ///> if not taken then save all the data in the text file

         out << this->firstnametxt->text()+" ";
         out << this->lastnametxt->text()+"|";
         out << this->usernametxt->text()+"|";
         out << this->passwordtxt->text()+"|";
         if (male->isChecked())
         {

         out << "Male""|";
     }
         else if (female->isChecked())
         {
             out << "Female""|";
         }
         else {out << "Not Selected""|";}

         out << this->countrycode->currentText()+"-"+this->phonenumbertxt->text()+"|";

         out << this->dobtxt->text()+"|";

         if (s1 == ""){
             out << ":/profile.png";
             out << '\n';
         }
         else{out << s1+'\n';}


         msg.setText("Account Created!");
         msg.exec();

         Signin *signin = new Signin();
         signin->show();
         this->close();


         /*

         dobtxt->clear();

         firstnametxt->clear();
         lastnametxt->clear();
         usernametxt->clear();
         passwordtxt->clear();
         phonenumbertxt->clear();

         if (male->isChecked())
         {
         male->setAutoExclusive(false);
         male->setChecked(false);
         male->setAutoExclusive(true);
     }
         else if (female->isChecked())
         {
             female->setAutoExclusive(false);
             female->setChecked(false);
             female->setAutoExclusive(true);
         }*/
        }
    }
    file.close();
}

/**
*
* \brief browses the computer to insert a profile picture
*
*
*  its a function SLOT which is signaled by a press of a button
*  when pressed the user is prompted a file explorer window to navigate to the desired picture of choice
*  if none are given, a default profile picture is set
*
*
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
*/

void SignUp::browse(){

    s1 =
        QFileDialog::getOpenFileName(this, "Open a file", "directoryToOpen",
            "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)");

}
