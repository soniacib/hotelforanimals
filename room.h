#include <iostream>
#include <vector>
#include <string>
#pragma once
#include "pet.h"

class Room
{
private:
    int room_number_;                    // room number
    std::string animal_type_;            // type of animal the room can accommodate
    std::vector<std::string> amenities_; // list of amenities the room has
    int capacity_;                       // maximum number of pets the room can accommodate
    // std::string pet_name_;               // name of the pet currently occupying the room (if any)
    bool occypied;        // true if room is occypied
    std::string RoomType; // type of the room(econom, standart, business)

public:
    // constructor
    Room(int room_number, std::string animal_type, std::vector<std::string> amenities, int capacity, std::string RoomType);

    // getter for room number
    int getRoomNumber() const;

    // getter for animal type
    std::string getAnimalType() const;

    // getter for room status
    bool getOccypiedStatus() const;

    // setter for occypied status
    void setOccypiedStatus(bool occypied);

    // getter for room capacity
    int getCapacity() const;

    // getter for room type
    std::string getRoomType() const;

    // prints the information of the room instance
    void printInfoRoom(std::ostream &os) const;
};
