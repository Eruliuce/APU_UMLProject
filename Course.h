#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include <string>
#include <map>

class Course
{
public :
    Course(std::string title, std::string author, std::string duration, std::string description, float price);
    std::string getTitle();
    std::string getAuthor();
    std::string getDuration();
    std::string getDescription();
    float getPrice();
private :
    std::string m_title, m_author, m_duration, m_description;
    float m_price;
};

#endif // COURSE_H_INCLUDED
