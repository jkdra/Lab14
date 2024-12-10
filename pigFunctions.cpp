//
// Created by Jawad Khadra on 12/9/24.
//

#include "pigHeader.h"

Pig::Pig() {
    tailType = STRAIGHT;
}

Pig::~Pig() { }

// Getters
TailType Pig::getTailType() { return tailType; }

// Setters
void Pig::setTailType(TailType tailType) { this->tailType = tailType; }

/*
 * tailTypeString
 *
 * This method is used to return the string representation of the tail type
 */
string Pig::getTailTypeString() {
    switch (tailType) {
        case STRAIGHT:
            return "Straight";
        case CORKSCREW:
            return "Corkscrew";
        case CURL_UP:
            return "Curl Up";
        case CURL_RIGHT:
            return "Curl Right";
        case CURL_LEFT:
            return "Curl Left";
        default:
            return "INVALID TAIL TYPE";
    }
}

/*
 * displayTable
 *
 * This method is used to display the animal's information in a table
 */
void Pig::displayAnimal() {
    Animal::displayAnimal();
    cout << " " << setw(8) << getTailTypeString() << endl ;
}

/*
 * displayTableHeader
 *
 * This method is used to display the header of the animal's table
 */
void Pig::displayTableHeader() {
    cout
    << "\n\nTHE PIG(S):\n\n"
    << "NAME      AGE TAILTYPE\n"
    << "--------- --- --------\n";
}