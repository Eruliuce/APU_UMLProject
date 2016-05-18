#include "Controler.h"

Controler::Controler()
{
    m_lms = std::make_unique<LearningManagementSystem>();
    m_view = std::make_unique<ConsoleView>();
}
