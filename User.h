#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
#include <map>
#include <set>
#include <memory>
#include <utility>
#include "Cart.h"
#include "Transaction.h"

class User
{
public :
    User(std::string username, std::string password, std::string name, std::string firstname, std::string email, std::string phone, bool isAdmin);
    void assignCourse(std::shared_ptr<Course>);
    void removeCourse(std::string title);
    int pay(std::unique_ptr<PaymentMethod> paymentMethod, std::string date); // 0 : payment successful, 1 : empty cart
    bool verifyPassword(std::string password); //return 0 if good password
    bool isAdmin();
    std::vector<std::string> getCartContent();
    void addToCart(std::shared_ptr<Course>);
    void removeFromCart(std::string);
    std::set<std::shared_ptr<Course>> getAssignedCourses();
    bool posseses(std::string);
private :
    std::string m_username, m_password, m_name, m_firstname, m_email, m_phone;
    bool m_isAdmin;
    std::map<std::string, std::shared_ptr<Course>> m_assignedCourses;
    std::unique_ptr<Cart> m_cart;
    std::set<std::unique_ptr<Transaction>> m_transactions;
};

#endif // USER_H_INCLUDED
