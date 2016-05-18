#include "Transaction.h"

Transaction::Transaction(std::unique_ptr<PaymentMethod> paymentMethod, std::string date, float amount)
{
    m_paymentMethod = std::move(paymentMethod);
    m_date = date;
    m_amount = amount;
}
