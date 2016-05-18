#ifndef PAYPAL_H_INCLUDED
#define PAYPAL_H_INCLUDED

#include <string>
#include "PaymentMethod.h"

class Paypal : public PaymentMethod
{
public :

private :
    std::string mail;
};

#endif // PAYPAL_H_INCLUDED
