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

bool Cart::isEmpty()
{
    return m_courses.empty();
}

