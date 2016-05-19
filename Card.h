#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <string>
#include "PaymentMethod.h"

class Card : public PaymentMethod
{
public :
    Card(std::string cardNumber, std::string expirationDate, std::string securityCode);
private :
    std::string m_cardNumber, m_expirationDate, m_securityCode;
};

#endif // CARD_H_INCLUDED
