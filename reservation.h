#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#pragma once
#include "payment.h"
#include "room.h"
#include "pet.h"
class Payment;
class Reservation
{
private:
    std::string pet_name_;                  // name of the pet being reserved for
    std::string Animaltype;                 // Animal Type
    std::string check_in_date_;             // check-in date of the reservation
    std::string check_out_date_;            // check-out date of the reservation
    int room_number_;                       // room number reserved
    std::string RoomType;                   // type of the room required
    float PriceToPay = 0;                   // PriceToPay of the reservation
    std::vector<std::string> extraServices; // list of extra services for reservation
    int num_days_;                          // number of days of the reservation

    int id; // id of the reservation

    void updatePaymentStatus(); // updates payment status in dependence of PriceToPay value
public:
    std::string payment_status_; // payment status of the reservation

    // constructor
    Reservation(std::string pet_name, std::string AnimalType, std::string RoomType,
                std::string check_in_date, std::string check_out_date, int num_days, int RoomNumber, int id);

    ~Reservation(); // destructor

    // takes the price list and determines the price of the reservation
    float DeterminePrice(
        std::unordered_map<std::string, float> PriceList);

    // getter for pet name
    std::string getPetName() const;

    // getter for check-in date
    std::string getCheckInDate() const;

    // getter for check-out date
    std::string getCheckOutDate() const;

    // getter for room number reserved
    int getRoomNumber() const;

    // getter for id
    int getId() const;

    // getter for room type
    std::string getRoomType() const;

    // getter for PriceToPay of the reservation
    float getPriceToPay() const;

    // getter for the number of days of the reservation
    int getNumDays() const;

    // simulates that client have paid for reservation
    void MarkPaid(Payment &payment);

    // Adds an additional service
    void AddService(std::string service);

    // Getter for extra services
    std::vector<std::string> GetExtraServices() const;

    // getter for animal type
    std::string GetAnimalType() const;

    // prints the information of the reservation instance
    void printInfoRes(std::ostream &os) const;
};
