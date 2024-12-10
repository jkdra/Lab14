//
// Created by Jawad Khadra on 12/9/24.
//

#include "animalHeader.h"

Animal::Animal() {
    name = "";
    age = 0;
}

Animal::~Animal() { }

// Getters
string Animal::getName() { return name; }
int Animal::getAge() { return age; }

// Setters
void Animal::setName(string name) { this->name = name; }
void Animal::setAge(int newAge) {
    if (newAge < 0 || newAge > 10) cout << "\nAge must be between 0 and 10\n" << endl;
    else this->age = newAge;
}

/*
 * modify
 *
 * This method is used to modify the name or age of an animal
 * It takes in a string and/or an int and modifies the animal accordingly
 */
void Animal::modify(string newName) { setName(newName); }
void Animal::modify(int newAge) { setAge(newAge); }
void Animal::modify(string newName, int newAge) {
    setName(newName);
    setAge(newAge);
}

/*
 * displayAnimal
 *
 * This method is used to display the animal's information in a table
 */
void Animal::displayAnimal() {
    cout
    << left << setw(9) << getName() << "  "
    << setw(2) << getAge();
}

/*
 * displayTableHeader
 *
 * This method is used to display the header of the animal's table
 */
void Animal::displayTableHeader() {
    cout
    << "\n\nAnimal Table\n"
    << "NAME      AGE\n"
    << "--------- ---\n";
}