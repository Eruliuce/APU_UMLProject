#include "Controler.h"
#include "const.h"

Controler::Controler()
{
    m_lms = std::make_unique<LearningManagementSystem>();
    m_view = std::make_unique<ConsoleView>();

    m_lms->initDatabase();

    bool exit = false;

    while(!exit)
    {
        m_view->showMenue(m_lms->getUserStatus());
        switch(m_view->getChoice(m_lms->getUserStatus()))
        {
        case EXIT :
            exit = true;
            break;
        case BROWSE :
            m_view->showCourses(m_lms->browseCourses());
            break;
        case SEARCH :
            m_view->showCourses(m_lms->searchCourses(m_view->getKeyword()));
            break;
        case LOGIN :
        {
            std::vector<std::string> credentials = m_view->askCredentials();
            int res = m_lms->login(credentials.at(0), credentials.at(1));
            if(res == 1)
                m_view->showMess("Wrong login.");
            else if(res == 2)
                m_view->showMess("Bad password.");
            else
                m_view->showMess("Login successful.");
            break;
        }
        case SIGNIN :
        {
            std::vector<std::string> credentials = m_view->signin();
            int res = m_lms->signin(credentials.at(0), credentials.at(1), credentials.at(2), credentials.at(3), credentials.at(4), credentials.at(5), false);
            if(res == 0)
                m_view->showMess("You were successfully registered.");
            else
                m_view->showMess("Error : username already exists, please choose another username.");
            break;
        }
        case ADD_TO_CART :
            m_lms->addToCart(m_view->askTitle());
            m_view->showCart(m_lms->getCartContent());
            break;
        case REMOVE_FROM_CART :
            m_lms->removeFromCart(m_view->askTitle());
            m_view->showCart(m_lms->getCartContent());
            break;
        case PAY :
            m_lms->pay(m_view->askPaymentMethod());
            break;
        case SHOW_COURSES :
            m_view->showCourses(m_lms->getAssignedCourses());
            break;
        case DOWNLOAD :
        {
            std::string course = m_view->askTitle();
            if(m_lms->validCourse(course))
                m_view->showMess("Course downloaded.");
            else
                m_view->showMess("Error : you don't own this course, please buy it.");
            break;
        }
        case LOGOUT :
            m_lms->logout();
            m_view->showMess("Logout successful.");
            break;
        case CREATE_COURSE :
            if(m_lms->createCourse(m_view->askCourse(), m_view->askPrice()) == 0)
               m_view->showMess("Course added successfully.");
            else
                m_view->showMess("This course already exist, please use another title.");
            break;
        case ASSIGN_COURSE :
            m_lms->assignCourse(m_view->askUser(), m_view->askTitle());
            break;
        default :
            m_view->showMess("Incorrect value.");
            break;
        }
    }
}
