#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

#include <map>
#include <memory>
#include "Course.h"

class Cart
{
public :
    Cart();
    void addToCart(std::shared_ptr<Course>);
    void removeFromCart(std::string title);
    void voidCart();
    float getPrice();
private :
    float m_totalPrice;
    std::map<std::string, std::shared_ptr<Course>> m_courses;
};

#endif // CART_H_INCLUDED
