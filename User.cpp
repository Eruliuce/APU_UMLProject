#include "user.h"

User::User(std::string username, std::string password, std::string name, std::string firstname, std::string email, std::string phone, bool isAdmin) : m_username(username), m_password(password), m_name(name), m_firstname(firstname), m_email(email), m_phone(phone), m_isAdmin(isAdmin)
{
    m_cart = std::make_unique<Cart>();
}

void User::assignCourse(std::shared_ptr<Course> course)
{
    m_assignedCourses.insert(std::make_pair(course->getTitle(), course));
}

void User::removeCourse(std::string title)
{
    m_assignedCourses.erase(m_assignedCourses.find(title));
}

int User::pay(std::unique_ptr<PaymentMethod> paymentMethod, std::string date)
{
    if(m_cart->isEmpty())
    {
        return 1;
    }

    m_transactions.insert(std::make_unique<Transaction>(std::move(paymentMethod), date, m_cart->getPrice()));
    m_cart->voidCart();

    return 0;
}

bool User::verifyPassword(std::string password)
{
    return m_password.compare(password) == 0;
}
