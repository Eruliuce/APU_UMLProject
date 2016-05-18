#include "ConsoleView.h"

using namespace std;

void ConsoleView::showMenue(ConnectStatus cs)
{
    cout << "Make a choice..." << endl;
    cout << "0 : exit" << endl;
    cout << "1 : browse courses" << endl;
    cout << "2 : search courses" << endl;
    if(cs == NOT_CONNECTED)
        cout << "3 : login" << endl;
    if(cs == USER)
    {
        cout << "3 : add course to cart" << endl;
        cout << "4 : remove course from cart" << endl;
        cout << "5 : pay" << endl;
    }
    if(cs == ADMIN)
    {
        cout << "3 : create course" << endl;
        cout << "4 : assign course to user" << endl;
    }
    cout << ">> ";
}

Choice ConsoleView::getChoice(ConnectStatus cs)
{
    int choice;
    cin >> choice;
    switch(choice)
    {
    case 0 :
        return EXIT;
    case 1 :
        return BROWSE;
    case 2 :
        return SEARCH;
    case 3 :
        if(cs == NOT_CONNECTED)
            return LOGIN;
        else if(cs == USER)
            return ADD_TO_CART;
        else
            return CREATE_COURSE;
    case 4 :
        if(cs == NOT_CONNECTED)
            return NONE;
        else if(cs == USER)
            return REMOVE_FROM_CART;
        else
            return ASSIGN_COURSE;
    case 5 :
        if(cs == USER)
            return PAY;
        else
            return NONE;
    default :
        return NONE;
    }
}

void ConsoleView::showCourses(std::set<std::shared_ptr<Course>> courses)
{
    if(courses.size() == 0)
        cerr << "No course to show." << endl;
    else
    {
        for(auto i = courses.begin(); i != courses.end(); ++i)
        {
            cout << "Title : " << (*i)->getTitle() << endl;
            cout << "Author : " << (*i)->getAuthor() << endl;
            cout << "Duration : " << (*i)->getDuration() << endl;
            cout << "Price : " << (*i)->getPrice() << endl;
            cout << "Description : " << (*i)->getDescription() << endl;
            cout << endl;
        }
    }
}

std::string ConsoleView::getKeyword()
{
    std::string keyword;
    cout << "Type keyword : ";
    cin >> keyword;
    return keyword;
}

