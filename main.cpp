#include <QApplication>
#include <QPushButton>
#include "signin.h"
#include "profile.h"

/**
* \mainpage Project435L
* \author Mohamad Abou Salem
* \author Hadi Al Karhani
* \date 11-28-2021
*
* \brief sets the scale of the window, and shows the sign in page with buttons to navigate
* \return application execution
*/

int main(int argc, char ** argv){
    QApplication app(argc, argv);

    Signin *s1 = new Signin();
    s1->show();
    s1->setFixedSize(400,200);///< set window to fixed size 400x200

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-s1->width()) / 2;
    int y = (screenGeometry.height()-s1->height()) / 2;
    s1->move(x, y);



    return app.exec();
}
