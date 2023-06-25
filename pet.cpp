
#include "pet.h"
#include <iostream>

// Constructor
Pet::Pet(std::string name, std::string species, std::string breed, int age, int ID)
{
    this->name = name;
    this->species = species;
    this->breed = breed;
    this->age = age;
    this->ID = ID;
}

// Constructor for the Pet class. Initializes the member variables with the provided values.
// Parameters:
// - name: The name of the pet.
// - species: The species of the pet.
// - breed: The breed of the pet.
// - age: The age of the pet.
// - ID: The ID of the pet.

// Destructor
Pet::~Pet()
{
    // Destructor implementation (if needed)
}

// Getters

int Pet::GetId() const
{
    return ID;
}

// Returns the ID of the pet.

std::string Pet::getName() const
{
    return name;
}

// Returns the name of the pet.

std::string Pet::getSpecies() const
{
    return this->species;
}

// Returns the species of the pet.

std::string Pet::getBreed() const
{
    return breed;
}

// Returns the breed of the pet.

int Pet::getAge() const
{
    return age;
}

// Returns the age of the pet.

void Pet::printInfoPet(std::ostream &os)
{
    os << "ID: " << ID << std::endl;
    os << "Name: " << name << std::endl;
    os << "Species: " << species << std::endl;
    os << "Breed: " << breed << std::endl;
    os << "Age: " << age << std::endl;
}

// Prints the information of the pet instance to the provided output stream.
