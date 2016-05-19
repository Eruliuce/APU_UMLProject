#include "LearningManagementSystem.h"

#include <iostream> //temp

LearningManagementSystem::LearningManagementSystem()
{
    m_currentUser = nullptr;
}

int LearningManagementSystem::login(std::string username, std::string password)
{
    if(m_users.find(username) == m_users.end())
    {
        return 1; //user does not exist
    }
    else if(!(m_users.find(username)->second->verifyPassword(password)))
    {
        return 2; //wrong password
    }

    m_currentUser = m_users.find(username)->second;
    return 0;
}

int LearningManagementSystem::signin(std::string username, std::string password, std::string name, std::string firstname, std::string email, std::string phone, bool isAdmin)
{
    if(m_users.find(username) != m_users.end())
    {
        return 1; //user already exist
    }

    m_users.insert(std::make_pair(username, std::make_shared<User>(username, password, name, firstname, email, phone, isAdmin)));
    return 0;
}

std::set<std::shared_ptr<Course>> LearningManagementSystem::browseCourses()
{
    std::set<std::shared_ptr<Course>> coursesList;
    for(std::map<std::string, std::shared_ptr<Course>>::const_iterator i = m_courses.begin(); i != m_courses.end(); ++i)
    {
        coursesList.insert(i->second);
    }
    return coursesList;
}

std::set<std::shared_ptr<Course>> LearningManagementSystem::searchCourses(std::string keyword)
{
    std::set<std::shared_ptr<Course>> coursesList;
    for(std::map<std::string, std::shared_ptr<Course>>::const_iterator i = m_courses.begin(); i != m_courses.end(); ++i)
    {
        if(i->first.find(keyword) != std::string::npos)
            coursesList.insert(i->second);
    }
    return coursesList;
}

int LearningManagementSystem::addCourse(std::string title, std::string author, std::string duration, float price, std::string description)
{
    std::cout << "test10" << std::endl;
    if(m_courses.find(title) != m_courses.end())
    {
        return 1; //title already exists
    }

    m_courses.insert(std::make_pair(title, std::make_shared<Course>(title, author, duration, description, price)));
    return 0;
}

void LearningManagementSystem::assignCourse(std::shared_ptr<User> user, std::string title)
{
    user->assignCourse(m_courses.find(title)->second);
}

void LearningManagementSystem::assignCourse(std::string title)
{
    m_currentUser->assignCourse(m_courses.find(title)->second);
}

void LearningManagementSystem::assignCourse(std::string user, std::string title)
{
    m_users.find(user)->second->assignCourse(m_courses.find(title)->second);
}

ConnectStatus LearningManagementSystem::getUserStatus()
{
    if(m_currentUser == nullptr)
        return NOT_CONNECTED;
    else if(m_currentUser->isAdmin())
        return ADMIN;
    else
        return USER;
}

std::vector<std::string> LearningManagementSystem::getCartContent()
{
    return m_currentUser->getCartContent();
}

void LearningManagementSystem::addToCart(std::string title)
{
    m_currentUser->addToCart(m_courses.find(title)->second);
}

void LearningManagementSystem::removeFromCart(std::string title)
{
    m_currentUser->removeFromCart(title);
}

int LearningManagementSystem::pay(std::unique_ptr<PaymentMethod> pm)
{
    return m_currentUser->pay(std::move(pm), "today");
}

std::set<std::shared_ptr<Course>> LearningManagementSystem::getAssignedCourses()
{
    return m_currentUser->getAssignedCourses();
}

bool LearningManagementSystem::validCourse(std::string course)
{
    return m_currentUser->posseses(course);
}

void LearningManagementSystem::logout()
{
    m_currentUser = nullptr;
}

int LearningManagementSystem::createCourse(std::vector<std::string> s, float p)
{
    std::cout << "test1" << std::endl;
    return addCourse(s.at(0), s.at(1), s.at(2), p, s.at(3));
}

void LearningManagementSystem::initDatabase()
{
    signin("admin", "admin", "Admin", "Nistor", "nistor.admin@falsemail.com", "0000000000", true);
    signin("user", "pwd", "1", "1", "1", "1", false);
    addCourse("course1", "Admin Nistor", "3 days", 42., "A course to learn how to learn courses.");
    addCourse("course2", "Admin Nistor", "3 days", 1337., "A course to learn how to make courses.");
}

