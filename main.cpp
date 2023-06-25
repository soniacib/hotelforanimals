#include <iostream>
#include <cstring>
#include <cassert>
#include <sstream>
#include "pet.h"
#include "payment.h"
#include "room.h"
#include "reservation.h"
#include "hotel.h"
void PetTest()
{
    // Create a Pet instance
    Pet myPet("Fluffy", "Cat", "Persian", 3, 8);

    // Test the getter methods
    assert(myPet.getName() == "Fluffy");
    assert(myPet.getSpecies() == "Cat");
    assert(myPet.getBreed() == "Persian");
    assert(myPet.getAge() == 3);

    // Test the printInfoPet method by redirecting output to a string stream
    std::stringstream ss;
    myPet.printInfoPet(ss);
    std::string petInfo = ss.str();
    std::string expectedInfo = "ID: 8\nName: Fluffy\nSpecies: Cat\nBreed: Persian\nAge: 3\n";
    assert(petInfo == expectedInfo);

    std::cout << "Pet test passed" << std::endl;
}
void testPaymentClass()
{
    // Create a Payment instance
    Payment myPayment(100.0);

    // Test the getter methods
    assert(myPayment.getTotalAmountDue() == 100.0);
    assert(myPayment.getPaymentMethod() == 0.0);

    // Test the setter methods
    myPayment.setPaymentMethod(1.5);
    assert(myPayment.getPaymentMethod() == 1.5);

    std::cout << "Payment tests passed" << std::endl;
}

void testReservationClass()
{
    // Create a Reservation instance
    Reservation myReservation("Fluffy", "Parot", "Standart", "2023-06-01", "2023-06-07", 7, 1, 89);

    // Test the getter methods
    assert(myReservation.getPetName() == "Fluffy");
    assert(myReservation.getCheckInDate() == "2023-06-01");
    assert(myReservation.getCheckOutDate() == "2023-06-07");
    assert(myReservation.payment_status_ == "Not Paid");
    assert(myReservation.getNumDays() == 7);

    // createing a price list
    std::unordered_map<std::string, float> packageInfo = {
        {"Econom", 50.0},
        {"Standart", 100.0},
        {"Business", 150.0}};
    // Determine price testing
    myReservation.DeterminePrice(packageInfo);

    assert(myReservation.getPriceToPay() == 700);
    // testing payment logic
    Payment p(200);
    myReservation.MarkPaid(p);
    assert(myReservation.getPriceToPay() == 500);
    assert(myReservation.payment_status_ == "Not Paid");
    Payment p2(600);
    myReservation.MarkPaid(p2);
    assert(myReservation.getPriceToPay() == -100);
    assert(myReservation.payment_status_ == "Overpaid");
    // testing adding extra services
    myReservation.AddService("4-pack beer");
    assert(myReservation.GetExtraServices().size() == 1);
    assert(myReservation.GetExtraServices()[0] == "4-pack beer");
    assert(myReservation.getPriceToPay() == 0);
    assert(myReservation.payment_status_ == "Paid");
    std::cout
        << "Reservation tests passed" << std::endl;
}
void testRoomClass()
{
    // Create a Room instance
    int roomNumber = 101;
    std::string animalType = "Dog";
    std::vector<std::string> amenities = {"TV", "Bed", "Toys"};
    int capacity = 2;
    std::string RoomType = "Standart";

    Room myRoom(roomNumber, animalType, amenities, capacity, RoomType);

    // Test the getter methods
    assert(myRoom.getRoomNumber() == roomNumber);
    assert(myRoom.getAnimalType() == animalType);
    assert(myRoom.getRoomType() == RoomType);
    assert(myRoom.getOccypiedStatus() == false);
    assert(myRoom.getCapacity() == capacity);

    // Test the printInfoRoom method by redirecting output to a string stream
    std::stringstream ss;
    myRoom.printInfoRoom(ss);
    std::string roomInfo = ss.str();
    std::string expectedInfo = "Room Number: 101\nAnimal Type: Dog\nRoom Status: 0\nRoom Capacity: 2\nAmenities: TV Bed Toys \n";
    assert(roomInfo == expectedInfo);

    std::cout << "Room test passed" << std::endl;
}

void testHotelClass()
{

    // Create a hotel with a maximum of 21 days and package pricing
    std::unordered_map<std::string, float> packageInfo = {
        {"Econom", 50.0},
        {"Standart", 100.0},
        {"Business", 150.0}};
    Hotel hotel(21, packageInfo);

    // Add rooms to the hotel

    assert(hotel.addRoom("Dog", {"TV 55'", "PS5 with Video Games", "Spa Centre"}, 4, "Econom") == 1); // should be no peroblem in adding rooms
    hotel.addRoom("Cat", {"Private Bathroom", "Personal Library", "Soft Chair"}, 4, "Standart");
    hotel.addRoom("Monkey", {"Personal C++ OOP Teacher", "Laptop", "Bar"}, 1, "Business");

    // test of getter room by number

    assert(hotel.getRoomByNumber(1).getAnimalType() == "Dog");

    try
    {
        hotel.getRoomByNumber(777); // should through error cause of incorrect room number
        assert(false && "Expected std::invalid_argument exception");
    }
    catch (const std::invalid_argument &e)
    {
        assert(strcmp(e.what(), "No room with this number") == 0);
    }

    assert(hotel.addRoom("Dog", {"TV 55'", "PS5 with Video Games", "Spa Centre"}, 4, "Ultra super lux") == -2); // room with type that is not in price list is unaccepted

    // Check the maximum capacity of the hotel
    assert(hotel.getMaxCapacity() == 9);

    // Add pets to the hotel
    assert(hotel.addPet("Buddy", "Dog", "Bichon Frisé", 18) == 1); // first pet with id 1
    hotel.addPet("Whiskers", "Cat", "Sphynx", 3);
    assert(hotel.addPet("Bobojonii", "Dog", "Sobaken", 19) == 3); // third pet with id 3
    Room &Room1 = hotel.getRoomByNumber(1);
    Room &Room2 = hotel.getRoomByNumber(2);
    Room &Room3 = hotel.getRoomByNumber(3);
    assert(Room1.getRoomNumber() == 1);
    assert(Room2.getRoomNumber() == 2);
    assert(Room3.getRoomNumber() == 3);

    assert(hotel.checkRoomAvailability(Room1) == true); // All rooms have to be free, scince there are no reservations
    assert(hotel.checkRoomAvailability(Room2) == true);
    assert(hotel.checkRoomAvailability(Room3) == true);

    // Make a reservation for pet1
    Pet &Pet1 = hotel.getPetByID(1);
    assert(Pet1.GetId() == 1);

    assert(Pet1.getSpecies() == "Dog");
    assert(hotel.makeReservation(Pet1, "Standart", "2023/06/03", "2023/06/18", 15) == -1); // error code No rooms avaliable for such parameters

    assert(hotel.makeReservation(Pet1, "Econom", "2023/06/11", "2023/06/15", 4) == 1); // reservation succesfully

    Pet &Pet3 = hotel.getPetByID(3);
    assert(Pet3.getSpecies() == "Dog");
    assert(hotel.makeReservation(Pet3, "Econom", "2023/06/11", "2023/06/12", 1) == -1); // b prev reservation

    Pet &Pet2 = hotel.getPetByID(2);
    assert(Pet2.getSpecies() == "Cat");
    assert(hotel.makeReservation(Pet2, "Standart", "2023/06/03", "2023/06/18", 15) == 2); // reservation should be ok
    int Pet5Id = hotel.addPet("Banana", "Monkey", "BlackMonkey", 45);
    Pet &Pet5 = hotel.getPetByID(Pet5Id);
    assert(hotel.makeReservation(Pet5, "Business", "2023/07/01", "2023/08/31", 62) == -2); // not allowed to stay for so long

    Reservation &reservation1 = hotel.getReservationByID(1);
    Reservation &reservation2 = hotel.getReservationByID(2);

    assert(reservation1.getPriceToPay() == 200.0);  // the prices have to be calculated
    assert(reservation2.getPriceToPay() == 1500.0); // in dependancy of type of the room
    reservation2.AddService("Personal Bar");
    assert(reservation2.getPriceToPay() == 1600);                 // 100 added because of additional service
    assert(reservation2.GetExtraServices()[0] == "Personal Bar"); // service should be added

    assert(hotel.checkRoomAvailability(Room3) == true);  // room 3 is still free
    assert(hotel.checkRoomAvailability(Room2) == false); // room 2 and 1 are occypied
    assert(hotel.checkRoomAvailability(Room1) == false);

    Payment payment1(210);

    reservation1.MarkPaid(payment1); // Paing for second reservation
    assert(reservation1.payment_status_ == "Overpaid");
    reservation1.AddService("Gaming mouse for PC");
    assert(reservation1.getPriceToPay() == 90); // fee for an additional service
    assert(reservation1.payment_status_ == "Not Paid");
    Payment payment2(90);
    reservation1.MarkPaid(payment2); // Paing for second reservation
    assert(reservation1.payment_status_ == "Paid");
    hotel.cancelReservation(reservation2);                                   // Cancelling reservation 2
    assert(hotel.getReservationByPet(Pet1).getId() == reservation1.getId()); // pet1 shouldhave reservation2
    try
    {
        hotel.getReservationByPet(Pet2); // Pet 2 has no reservations
        assert(false && "Expected std::invalid_argument exception");
    }
    catch (const std::invalid_argument &e)
    {
        assert(strcmp(e.what(), "No reservation for this pet") == 0);
    }

    assert(hotel.getReservationByRoom(Room1).getId() == reservation1.getId()); // Room 1 has to have reservation2

    try
    {
        hotel.getReservationByRoom(Room2); // should through error because no reservations with this room
        assert(false && "Expected std::invalid_argument exception");
    }
    catch (const std::invalid_argument &e)
    {
        assert(strcmp(e.what(), "No reservation with this room") == 0);
    }
    std::cout << "Hotel test passed\n";
}

int main()
{
    PetTest();
    testPaymentClass();
    testReservationClass();
    testRoomClass();
    testHotelClass();
}