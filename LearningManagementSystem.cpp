#include "LearningManagementSystem.h"

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
    if(m_courses.find(title) != m_courses.end())
    {
        return 1; //title already exists
    }

    m_courses.insert(std::make_pair(title, std::make_shared<Course>(title, author, duration, description, price)));
    return 0;
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
