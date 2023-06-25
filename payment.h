
// This header file defines the Payment class, which represents a payment made by a guest.

#include <iostream>
#include <string>
#pragma once
#include "reservation.h"
class Payment
{
private:
    float totalAmountDue;
    float paymentMethod;

public:
    // Constructor
    Payment(float totalAmountDue);
    // Destructor
    ~Payment();

    // Getters
    float getTotalAmountDue() const; // Returns the total amount due for the reservation
    float getPaymentMethod() const;  // Returns the payment method used

    void setPaymentMethod(float paymentMethod);    // Sets the payment method used
    void setDiscountApplied(bool discountApplied); // Sets whether a discount has been applied or not
    void setIsPaid(bool isPaid);                   // Sets whether the payment has been made or not

    void printInfoPayment(std::ostream &os); // Prints information about the payment
};