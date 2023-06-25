
#include <iostream>
#include "payment.h"

// Constructor
Payment::Payment(float totalAmountDue)
{
    this->totalAmountDue = totalAmountDue;
    paymentMethod = 0.0f; // Initialize to 0 by default
}

// Constructor for the Payment class. Initializes the totalAmountDue with the provided value.
// Parameters:
// - totalAmountDue: The total amount due for the payment.

// Destructor
Payment::~Payment()
{
    // Destructor implementation (if needed)
}

// Getters
float Payment::getTotalAmountDue() const
{
    return totalAmountDue;
}

// Returns the total amount due for the payment.

float Payment::getPaymentMethod() const
{
    return this->paymentMethod;
}

// Returns the payment method used for the payment.

// Setters
void Payment::setPaymentMethod(float paymentMethod)
{
    this->paymentMethod = paymentMethod;
}

// Sets the payment method for the payment.

// Other Methods:

void Payment::printInfoPayment(std::ostream &os)
{
    os << "Total Amount Due: " << totalAmountDue << std::endl;
    os << "Payment Method: " << paymentMethod << std::endl;
}

// Prints the information of the payment instance to the provided output stream.
