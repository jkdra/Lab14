//
// Created by Jawad Khadra on 12/9/24.
//

#include "sheepHeader.h"

Sheep::Sheep() { woolType = LONG; }

Sheep::~Sheep() { }

// Getters
WoolType Sheep::getWoolType() { return woolType; }
string Sheep::getColor() { return color; }

// Setters
void Sheep::setWoolType(WoolType woolType) { this->woolType = woolType; }
void Sheep::setColor(string color) { this->color = color; }

/*
 * woolTypeString
 *
 * This method is used to return the string representation of the wool type
 */
string Sheep::getWoolTypeString() {
    switch (woolType) {
        case LONG:
            return "Long";
        case MEDIUM:
            return "Medium";
        case FINE:
            return "Fine";
        case CARPET:
            return "Carpet";
        default:
            return "INVALID WOOL TYPE";
    }
}

/*
 * displayAnimal
 *
 * This method is used to display the animal's information in a table
 */
void Sheep::displayAnimal() {
    Animal::displayAnimal();
    cout
    << " "
    << setw(8) << getWoolTypeString() << " "
    << setw(5) << getColor() << endl
    ;
}

/*
 * displayTableHeader
 *
 * This method is used to display the header of the animal's table
 */
void Sheep::displayTableHeader() {
    cout
    << "\n\nTHE SHEEP:\n\n"
    << "NAME      AGE WOOLTYPE COLOR\n"
    << "--------- --- -------- -----\n";
}