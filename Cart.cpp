#include "Cart.h"

Cart::Cart()
{

}

void Cart::addToCart(std::shared_ptr<Course> course)
{
    m_courses.insert(std::make_pair(course->getTitle(), course));
}

void Cart::removeFromCart(std::string title)
{
    m_courses.erase(m_courses.find(title));
}

void Cart::voidCart()
{
    m_courses.clear();
}

float Cart::getPrice()
{
    float price = 0.;
    for(std::map<std::string, std::shared_ptr<Course>>::const_iterator i = m_courses.begin(); i != m_courses.end(); ++i)
        price += i->second->getPrice();
    return price;
}

std::vector<std::string> Cart::getContent()
{
    std::vector<std::string> s;
    std::string tmp;
    for(auto i = m_courses.begin(); i != m_courses.end(); ++i)
    {
        s.push_back(i->second->getTitle() + " - " + std::to_string(i->second->getPrice()) + "MYR");
    }
    s.push_back("Total price : " + std::to_string(getPrice()) + "MYR");
    return s;
}

bool Cart::isEmpty()
{
    return m_courses.empty();
}

std::shared_ptr<std::map<std::string, std::shared_ptr<Course>>> Cart::getCourses()
{
    return std::make_shared<std::map<std::string, std::shared_ptr<Course>>>(m_courses);
}

