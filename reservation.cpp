#include "reservation.h"
// Constructor
Reservation::Reservation(std::string pet_name, std::string AnimalType, std::string RoomType,
                         std::string check_in_date, std::string check_out_date,
                         int num_days, int RoomNumber, int id)
{
    this->pet_name_ = pet_name;
    this->RoomType = RoomType;
    this->room_number_ = RoomNumber;
    this->check_in_date_ = check_in_date;
    this->check_out_date_ = check_out_date;
    this->num_days_ = num_days;
    this->Animaltype = AnimalType;
    this->id = id;
    this->payment_status_ = "Not Paid";
}

// Constructor for the Reservation class. Initializes the member variables with the provided values.
// Parameters:
// - pet_name: The name of the pet for the reservation.
// - AnimalType: The type of animal for the reservation.
// - RoomType: The type of room for the reservation.
// - check_in_date: The check-in date for the reservation.
// - check_out_date: The check-out date for the reservation.
// - num_days: The number of days for the reservation.
// - RoomNumber: The number of the room for the reservation.
// - id: The ID of the reservation.

// Destructor
Reservation::~Reservation()
{
    // Destructor implementation (if needed)
}

// Getters
std::string Reservation::getPetName() const
{
    return pet_name_;
}

// Returns the name of the pet for the reservation.

int Reservation::getId() const
{
    return id;
}

// Returns the ID of the reservation.

std::string Reservation::GetAnimalType() const
{
    return Animaltype;
}

// Returns the type of animal for the reservation.

float Reservation::DeterminePrice(std::unordered_map<std::string, float> PriceList)
{
    PriceToPay = PriceList[this->RoomType] * this->num_days_;
    return PriceToPay;
}

// Calculates and returns the price to pay for the reservation based on the room type and number of days.

float Reservation::getPriceToPay() const
{
    return PriceToPay;
}

// Returns the price to pay for the reservation.

void Reservation::MarkPaid(Payment &payment)
{
    PriceToPay -= payment.getTotalAmountDue();
    updatePaymentStatus();
}

// Updates the price to pay for the reservation by deducting the payment amount and updates the payment status accordingly.

void Reservation::AddService(std::string Service)
{
    extraServices.push_back(Service);
    PriceToPay += 100;
    updatePaymentStatus();
}

// Adds an extra service to the reservation, increases the price to pay by 100, and updates the payment status.

void Reservation::updatePaymentStatus()
{
    if (PriceToPay == 0)
    {
        payment_status_ = "Paid";
    }
    else if (PriceToPay > 0)
    {
        payment_status_ = "Not Paid";
    }
    else if (PriceToPay < 0)
    {
        payment_status_ = "Overpaid";
    }
}

// Updates the payment status based on the price to pay.

std::vector<std::string> Reservation::GetExtraServices() const
{
    return extraServices;
}

// Returns the vector of extra services for the reservation.

std::string Reservation::getCheckInDate() const
{
    return check_in_date_;
}

// Returns the check-in date for the reservation.

std::string Reservation::getCheckOutDate() const
{
    return check_out_date_;
}

// Returns the check-out date for the reservation.

int Reservation::getRoomNumber() const
{
    return room_number_;
}

// Returns the number of the room for the reservation.

std::string Reservation::getRoomType() const
{
    return this->RoomType;
}

// Returns the type of room for the reservation.

int Reservation::getNumDays() const
{
    return num_days_;
}

// Returns the number of days for the reservation.

void Reservation::printInfoRes(std::ostream &os) const
{
    os << "Pet Name: " << pet_name_ << std::endl;
    os << "Check-in Date: " << check_in_date_ << std::endl;
    os << "Check-out Date: " << check_out_date_ << std::endl;
    os << "Room Number: " << room_number_ << std::endl;
    os << "Price to pay: " << PriceToPay << std::endl;
    os << "Payment Status: " << payment_status_ << std::endl;
    os << "Number of Days: " << num_days_ << std::endl;
}

// Prints the information of the reservation instance to the provided output stream.
