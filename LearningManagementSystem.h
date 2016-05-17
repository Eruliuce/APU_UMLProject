#ifndef LEARNINGMANAGEMENTSYSTEM_H_INCLUDED
#define LEARNINGMANAGEMENTSYSTEM_H_INCLUDED

#include <string>
#include <set>
#include <map>
#include <memory>
#include "Course.h"
#include "User.h"

class LearningManagementSystem
{
public :
    LearningManagementSystem();
    int login(std::string username, std::string password); //return 0 if logged successful, 1 if user don't exist, 2 if bad password
    int signin(std::string username, std::string password, std::string name, std::string firstname, std::string email, std::string phone, bool isAdmin); //return 0 if successful, 1 username already exist
    std::set<std::shared_ptr<Course>> browseCourses(); //return the list of all courses;
    std::set<std::shared_ptr<Course>> searchCourses(std::string keyword); //return the list of courses containing a keyword
    int addCourse(std::string title, std::string author, std::string duration, float price, std::string description); // 0 Ok, 1 title already exists
    void assignCourse(std::string user, std::string title);
private :
    std::shared_ptr<User> m_currentUser;
    std::map<std::string, std::shared_ptr<Course>> m_courses;
    std::map<std::string, std::shared_ptr<User>> m_users;
};

#endif // LEARNINGMANAGEMENTSYSTEM_H_INCLUDED
