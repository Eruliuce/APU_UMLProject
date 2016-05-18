#include "Controler.h"
#include "const.h"

Controler::Controler()
{
    m_lms = std::make_unique<LearningManagementSystem>();
    m_view = std::make_unique<ConsoleView>();

    bool exit = false;

    while(!exit)
    {
        m_view->showMenue(m_lms->getUserStatus());
        switch(m_view->getChoice(m_lms->getUserStatus()))
        {
        case EXIT :
            exit = true;
            break;
        case BROWSE :
            m_view->showCourses(m_lms->browseCourses());
            break;
        case SEARCH :
            m_view->showCourses(m_lms->searchCourses(m_view->getKeyword()));
            break;
        case LOGIN :
            /// TODO
            break;
        }
    }
}
