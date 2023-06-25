
#include "room.h"
// Constructor
Room::Room(int room_number, std::string animal_type, std::vector<std::string> amenities, int capacity, std::string RoomType)
{
    this->RoomType = RoomType;
    this->room_number_ = room_number;
    this->animal_type_ = animal_type;
    this->amenities_ = amenities;
    this->capacity_ = capacity;
    this->occypied = false;
}

// Constructor for the Room class. Initializes the member variables with the provided values.
// Parameters:
// - room_number: The number of the room.
// - animal_type: The type of animal the room is suitable for.
// - amenities: A vector of amenities available in the room.
// - capacity: The maximum capacity of the room.
// - RoomType: The type of the room.

// Getters
int Room::getRoomNumber() const
{
    return room_number_;
}

// Returns the number of the room.

std::string Room::getRoomType() const
{
    return RoomType;
}

// Returns the type of the room.

std::string Room::getAnimalType() const
{
    return animal_type_;
}

// Returns the type of animal the room is suitable for.

bool Room::getOccypiedStatus() const
{
    return occypied;
}

// Returns the occupancy status of the room.

void Room::setOccypiedStatus(bool occypied)
{
    this->occypied = occypied;
}

// Sets the occupancy status of the room.

int Room::getCapacity() const
{
    return capacity_;
}

// Returns the maximum capacity of the room.

// Prints the information of the room instance
void Room::printInfoRoom(std::ostream &os) const
{
    os << "Room Number: " << room_number_ << std::endl;
    os << "Animal Type: " << animal_type_ << std::endl;
    os << "Room Status: " << occypied << std::endl;
    os << "Room Capacity: " << capacity_ << std::endl;
    os << "Amenities: ";
    for (const auto &amenity : amenities_)
    {
        os << amenity << " ";
    }
    os << std::endl;
}

// Prints the information of the room to the provided output stream.
