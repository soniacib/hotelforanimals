#include "hotel.h"
#include <algorithm>

// Constructor
Hotel::Hotel(int MaxDays, std::unordered_map<std::string, float> pricing)
{
    maxDays = MaxDays;
    package_info = pricing;
    maxCapacity = 0;
}

// Constructor for the Hotel class. Initializes the maximum number of days, package information, and maximum capacity.
// Parameters:
// - MaxDays: The maximum number of days allowed for a reservation.
// - pricing: An unordered map containing the pricing information for different room types.

// Destructor
Hotel::~Hotel()
{
}

// Removes the provided Reservation instance from the reservation schedule.
// Updates the occupied status of the room associated with the reservation and removes the reservation from the schedule.
// Parameters:
// - reservation: A reference to the Reservation instance to be canceled.

void Hotel::cancelReservation(Reservation &reservation)
{
    getRoomByNumber(reservation.getRoomNumber()).setOccypiedStatus(false);

    for (auto it = reservation_schedule.begin(); it != reservation_schedule.end(); ++it)
    {
        if (it->getId() == reservation.getId())
        {
            reservation_schedule.erase(it);
            break;
        }
    }
}

// Prints the list of available rooms and their respective amenities.
// Parameters:
// - os: The output stream to which the room information will be printed.

void Hotel::printRoomList(std::ostream &os)
{
    for (auto room : room_list)
    {
        room.printInfoRoom(os);
    }
}

// Prints the current reservation schedule.
void Hotel::printReservationSchedule(std::ostream &os)
{
    for (auto reservation : reservation_schedule)
    {
        reservation.printInfoRes(os);
    }
}

// Prints the information of all reservations in the reservation schedule.
// Parameters:
// - os: The output stream to which the reservation information will be printed.

int Hotel::addRoom(string animal_type, vector<std::string> amenities, int capacity, string RoomType)
{
    int RoomNumber = 1;

    if (!room_list.empty())
        RoomNumber = room_list.back().getRoomNumber() + 1;

    auto search_result = package_info.find(RoomType);

    if (search_result == package_info.end())
        return -2; // The given room type is not in the pricelist.

    Room room(RoomNumber, animal_type, amenities, capacity, RoomType);

    room_list.push_back(room);
    maxCapacity += room.getCapacity();

    return RoomNumber;
}

// Adds a new Room object to the room list.
// Parameters:
// - animal_type: The type of animal allowed in the room.
// - amenities: A vector of amenities provided in the room.
// - capacity: The maximum capacity of the room.
// - RoomType: The type of room.

int Hotel::addPet(string name, string species, string breed, int age)
{
    int PetID = 1;

    if (!pet_list.empty())
        PetID = pet_list.back().GetId() + 1;

    Pet pet(name, species, breed, age, PetID);
    pet_list.push_back(pet);

    return PetID;
}

// Adds a new Pet object to the pet list.
// Parameters:
// - name: The name of the pet.
// - species: The species of the pet.
// - breed: The breed of the pet.
// - age: The age of the pet.

int Hotel::makeReservation(Pet &pet, std::string RoomType,
                           std::string check_in_date, std::string check_out_date, int num_days)
{
    if (num_days > maxDays)
        return -2; // Not allowed to stay for so long.

    string animalType = pet.getSpecies();

    for (auto &rm : room_list)
    {
        if (rm.getOccypiedStatus() == false && rm.getRoomType() == RoomType && rm.getAnimalType() == animalType)
        {
            rm.setOccypiedStatus(true);

            int RoomNumber = rm.getRoomNumber();
            int ID = 1;

            if (!reservation_schedule.empty())
                ID = reservation_schedule.back().getId() + 1;

            Reservation reservation(pet.getName(), pet.getSpecies(), RoomType, check_in_date, check_out_date, num_days, RoomNumber, ID);
            reservation.DeterminePrice(package_info);
            reservation_schedule.push_back(reservation);

            return ID;
        }
    }

    return -1; // No suitable rooms found.
}

// Makes a reservation for a pet in a room.
// Parameters:
// - pet: A reference to the Pet object for which the reservation is made.
// - RoomType: The type of room for the reservation.
// - check_in_date: The check-in date of the reservation.
// - check_out_date: The check-out date of the reservation.
// - num_days: The number of days for the reservation.

// Checks if a room is available for a given number of days
bool Hotel::checkRoomAvailability(Room &room)
{
    return !room.getOccypiedStatus();
}

// Checks the availability of a given Room object.
// Parameters:
// - room: A reference to the Room object to check.

Reservation &Hotel::getReservationByPet(Pet &pet)
{

    for (auto &reservation : reservation_schedule)
    {
        if (reservation.getPetName() == pet.getName())
        {
            return const_cast<Reservation &>(reservation);
        }
    }
    throw std::invalid_argument("No reservation for this pet");
}

// Returns a reservation associated with a given Pet object.
// Parameters:
// - pet: A reference to the Pet object.

Reservation &Hotel::getReservationByRoom(Room &Room)
{
    for (auto &reservation : reservation_schedule)
    {
        if (reservation.getRoomNumber() == Room.getRoomNumber())
        {
            return const_cast<Reservation &>(reservation);
        }
    }

    throw std::invalid_argument("No reservation with this room");
}

// Returns the reservation associated with a given Room object.
// Parameters:
// - Room: A reference to the Room object.

Room &Hotel::getRoomByNumber(int RoomNum) const
{
    for (auto &room : room_list)
    {
        if (room.getRoomNumber() == RoomNum)
        {
            return const_cast<Room &>(room);
        }
    }

    throw std::invalid_argument("No room with this number");
}

// Returns the Room object with a specific room number.
// Parameters:
// - RoomNum: The room number to search for.

Pet &Hotel::getPetByID(int id) const
{
    for (auto &pet : pet_list)
    {
        if (pet.GetId() == id)
        {
            return const_cast<Pet &>(pet);
        }
    }
    throw std::invalid_argument("Pet not found");
}

// Returns the Pet object with a specific ID.
// Parameters:
// - id: The ID of the pet to search for.

Reservation &Hotel::getReservationByID(int id) const
{
    for (auto &reservation : reservation_schedule)
    {
        if (reservation.getId() == id)
        {
            return const_cast<Reservation &>(reservation);
        }
    }
    throw std::invalid_argument("Reservation not found.");
}

// Returns the Reservation object with a specific ID.
// Parameters:
// - id: The ID of the reservation to search for.

int Hotel::getMaxCapacity()
{
    return maxCapacity;
}

// Returns the maximum number of pets allowed in the hotel.

int Hotel::getMaxDays()
{
    return maxDays;
}

// Returns the maximum number of days a guest can stay in the hotel.

void Hotel::printInfoHotel(std::ostream &os)
{
    os << "Hotel Information:\n";
    os << "Maximum Capacity: " << maxCapacity << "\n";
    os << "Maximum Days: " << maxDays << "\n";
    os << "Package Pricing Information:\n";
    for (const auto &entry : package_info)
    {
        os << " - " << entry.first << ": " << entry.second << "\n";
    }
}

// Prints information about the hotel, including maximum capacity, maximum days, and package pricing information.
// Parameters:
// - os: The output stream to write the information to.
