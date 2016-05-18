#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include <string>
#include <memory>
#include <utility>
#include "PaymentMethod.h"

class Transaction
{
public :
    Transaction(std::unique_ptr<PaymentMethod> paymentMethod, std::string date, float amount);
private :
    std::string m_date;
    float m_amount;
    std::unique_ptr<PaymentMethod> m_paymentMethod;
};

#endif // TRANSACTION_H_INCLUDED
