#ifndef CONSOLEVIEW_H_INCLUDED
#define CONSOLEVIEW_H_INCLUDED

#include <iostream>
#include <set>
#include <vector>
#include <memory>
#include <string>
#include <vector>
#include "const.h"
#include "Course.h"
#include "PaymentMethod.h"
#include "Card.h"
#include "Paypal.h"

class ConsoleView
{
public :
    void showMenue(ConnectStatus);
    Choice getChoice(ConnectStatus);
    void showCourses(std::set<std::shared_ptr<Course>>);
    std::string getKeyword();
    std::vector<std::string> askCredentials();
    void showMess(std::string mess);
    std::vector<std::string> signin();
    void showCart(std::vector<std::string>);
    std::string askTitle();
    std::unique_ptr<PaymentMethod> askPaymentMethod();
    std::vector<std::string> askCourse();
    float askPrice();
    std::string askUser();
private :

};

#endif // CONSOLEVIEW_H_INCLUDED
