#include <iostream>
#include <vector>
#include <unordered_map>
#include "room.h"
#include "reservation.h"
#include "payment.h"
#include "pet.h"

using namespace std;
class Hotel
{
private:
    vector<Room> room_list;                    // vector of available rooms in the hotel
    vector<Reservation> reservation_schedule;  // current reservation schedule
    vector<Pet> pet_list;                      // pet list
    unordered_map<string, float> package_info; // package pricing information
    int maxCapacity;                           // maximum capacity of the hotel each room adds 5
    int maxDays;                               // maximum number of days a guest can stay in the hotel
public:
    // Constructor
    Hotel(int MaxDays, unordered_map<std::string, float> pricing);

    // Destructor
    ~Hotel();

    // Removes the provided Reservation instance from the reservation schedule.
    void cancelReservation(Reservation &Reservation);

    // Updates the services for the provided Reservation instance.
    void modifyServices(Reservation &Reservation, string NewService);

    // Prints the vector of available rooms and their respective amenities.
    void printRoomList(ostream &os);

    // Prints the current reservation schedule.
    void printReservationSchedule(ostream &os);

    // Adds a Room object to the list of rooms, returns the room number
    int addRoom(string animal_type, vector<std::string> amenities, int capacity, string RoomType);

    // Adds a Pet object to the list of pets, returns the pet id
    int addPet(string name, string species, string breed, int age);

    // Makes a reservation for a pet, returns error code(<0) or reservation id(>0)
    int makeReservation(Pet &pet, std::string RoomType,
                        std::string check_in_date, std::string check_out_date, int num_days);

    // Checks if a room is available for a given number of days
    bool checkRoomAvailability(Room &Room);

    // Returns a list of reservations for a given Pet object
    Reservation &getReservationByPet(Pet &Pet);

    // Gets room by its number
    Room &getRoomByNumber(int number) const;

    // Gets Pet by id
    Pet &getPetByID(int id) const;

    // Gets reservation by its id
    Reservation &getReservationByID(int id) const;

    // Returns a reservation with given room
    Reservation &getReservationByRoom(Room &Room);

    // Returns the maximum number of pets allowed in the hotel
    int getMaxCapacity();

    // Returns the maximum number of days a guest can stay in the hotel
    int getMaxDays();

    // Prints the hotel information
    void printInfoHotel(ostream &os);
};
