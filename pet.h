#include <string>
#pragma once
class Pet
{
private:
    std::string name;    // name of the pet
    std::string species; // species of the pet
    std::string breed;   // breed of the pet
    int age;             // age of the pet
    int ID;

public:
    // Constructor
    Pet(std::string name, std::string species, std::string breed, int age, int ID);

    // Destructor
    ~Pet();

    // Returns the name of the pet.
    std::string getName() const;

    // Returns the species of the pet.
    std::string getSpecies() const;

    // Returns the breed of the pet.
    std::string getBreed() const;

    // Returns the age of the pet.
    int getAge() const;

    // Returns id
    int GetId() const;

    // Prints the information of the pet instance.
    void printInfoPet(std::ostream &os);
};
