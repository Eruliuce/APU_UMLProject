#ifndef PAYPAL_H_INCLUDED
#define PAYPAL_H_INCLUDED

#include <string>
#include "PaymentMethod.h"

class Paypal : public PaymentMethod
{
public :
    Paypal(std::string mail);
private :
    std::string m_mail;
};

#endif // PAYPAL_H_INCLUDED
