#ifndef CONSOLEVIEW_H_INCLUDED
#define CONSOLEVIEW_H_INCLUDED

#include <iostream>
#include <set>
#include <memory>
#include <string>
#include "const.h"
#include "Course.h"

class ConsoleView
{
public :
    void showMenue(ConnectStatus);
    Choice getChoice(ConnectStatus);
    void showCourses(std::set<std::shared_ptr<Course>>);
    std::string getKeyword();
private :

};

#endif // CONSOLEVIEW_H_INCLUDED
