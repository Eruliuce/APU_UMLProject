#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <string>
#include "PaymentMethod.h"

class Card : public PaymentMethod
{
    std::string cardNumber, expirationDate, securityCode;
};

#endif // CARD_H_INCLUDED
