#include "Course.h"

Course::Course(std::string title, std::string author, std::string duration, std::string description, float price) : m_title(title), m_author(author), m_duration(duration), m_description(description), m_price(price)
{

}

std::string Course::getTitle()
{
    return m_title;
}

float Course::getPrice()
{
    return m_price;
}
