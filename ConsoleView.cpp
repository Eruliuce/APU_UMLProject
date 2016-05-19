#include "ConsoleView.h"

using namespace std;

void ConsoleView::showMenue(ConnectStatus cs)
{
    cout << "Make a choice..." << endl;
    cout << "0 : exit" << endl;
    cout << "1 : browse courses" << endl;
    cout << "2 : search courses" << endl;
    if(cs == NOT_CONNECTED)
    {
        cout << "3 : login" << endl;
        cout << "4 : sign in" << endl;
    }
    if(cs == USER)
    {
        cout << "3 : add course to cart" << endl;
        cout << "4 : remove course from cart" << endl;
        cout << "5 : pay" << endl;
        cout << "6 : show assigned courses" << endl;
        cout << "7 : download assigned course" << endl;
        cout << "8 : logout" << endl;
    }
    if(cs == ADMIN)
    {
        cout << "3 : create course" << endl;
        cout << "4 : assign a course to a user" << endl;
        cout << "5 : logout" << endl;
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
            return SIGNIN;
        else if(cs == USER)
            return REMOVE_FROM_CART;
        else
            return ASSIGN_COURSE;
    case 5 :
        if(cs == USER)
            return PAY;
        else if(cs == ADMIN)
            return LOGOUT;
        else
            return NONE;
    case 6 :
        if(cs == USER)
            return SHOW_COURSES;
        else
            return NONE;
    case 7 :
        if(cs == USER)
            return DOWNLOAD;
        else
            return NONE;
    case 8 :
        if(cs == USER)
            return LOGOUT;
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

std::vector<string> ConsoleView::askCredentials()
{
    std::string username, password;
    cout << "Enter your username : ";
    cin >> username;
    cout << "Enter your password : ";
    cin >> password;
    std::vector<string> res;
    res.push_back(username);
    res.push_back(password);
    return res;
}

void ConsoleView::showMess(string mess)
{
    cout << mess << endl;
}

std::vector<std::string> ConsoleView::signin()
{
    std::string username, password, name, firstname, email, phone;
    cout << "Enter your username : ";
    cin >> username;
    cout << "Enter your password : ";
    cin >> password;
    cout << "Enter your last name : ";
    cin >> name;
    cout << "Enter your first name : ";
    cin >> firstname;
    cout << "Enter your email : ";
    cin >> email;
    cout << "Enter your phone number : ";
    cin >> phone;
    std::vector<string> res;
    res.push_back(username);
    res.push_back(password);
    res.push_back(name);
    res.push_back(firstname);
    res.push_back(email);
    res.push_back(phone);
    return res;
}

std::string ConsoleView::askTitle()
{
    std::string title;
    cout << "Enter title : ";
    cin >> title;
    return title;
}

void ConsoleView::showCart(std::vector<std::string> s)
{
    if(s.empty())
        cout << "Cart is empty" << endl;
    else
    {
        cout << "Cart content :" << endl;
        for(size_t i = 0; i < s.size(); ++i)
        {
            cout << s.at(i) << endl;
        }
    }
}

unique_ptr<PaymentMethod> ConsoleView::askPaymentMethod()
{
    int choice;
    unique_ptr<PaymentMethod> pm;
    cout << "1 : card ; 2 : paypal >> ";
    cin >> choice;
    if(choice == 1)
    {
        string number, expir, code;
        cout << "Card number : ";
        cin >> number;
        cout << "Expiration date : ";
        cin >> expir;
        cout << "3-digit code : ";
        cin >> code;
        pm = make_unique<Card>(number, expir, code);
    }
    else
    {
        string mail;
        cout << "mail of the paypal account : ";
        cin >> mail;
        pm = make_unique<Paypal>(mail);
    }
    return std::move(pm);
}

std::vector<std::string> ConsoleView::askCourse()
{
    std::string title, author, duration, description;
    cout << "Title : ";
    cin >> title;
    cout << "Author : ";
    cin >> author;
    cout << "Duration : ";
    cin >> duration;
    cout << "Description : ";
    cin >> description;
    std::vector<std::string> v;
    v.push_back(title);
    v.push_back(author);
    v.push_back(duration);
    v.push_back(description);
    return v;
}

float ConsoleView::askPrice()
{
    float p;
    cout << "Price : ";
    cin >> p;
    return p;
}

std::string ConsoleView::askUser()
{
    std::string user;
    cout << "Username : ";
    cin >> user;
    return user;
}

