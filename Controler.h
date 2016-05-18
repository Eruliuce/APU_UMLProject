#ifndef CONTROLER_H_INCLUDED
#define CONTROLER_H_INCLUDED

#include <memory>

class Controler
{
public :
    Controler();
private :
    std::unique_ptr<LearningManagementSystem> m_lms;
    std::unique_ptr<ConsoleView> m_view;
};

#endif // CONTROLER_H_INCLUDED
