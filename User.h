#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
#include <map>
#include <set>
#include <memory>
#include "Cart.h"
#include "Transaction.h"

class User
{
public :
    User(std::string username, std::string password, std::string name, std::string firstname, std::string email, std::string phone, bool isAdmin);
    void assignCourse(std::shared_ptr<Course>);
    void removeCourse(std::string title);
    void pay();
    int verifyPassword(std::string password); //return 0 if good password
private :
    std::string m_username, m_password, m_name, m_firstname, m_email, m_phone;
    bool m_isAdmin;
    std::map<std::string, std::shared_ptr<Course>> m_assignedCourses;
    std::unique_ptr<Cart> m_cart;
    std::set<std::unique_ptr<Transaction>> m_transactions;
};

#endif // USER_H_INCLUDED
