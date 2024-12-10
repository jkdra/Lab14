//
// Created by Jawad Khadra on 12/9/24.
//

#ifndef PIGHEADER_H
#define PIGHEADER_H

#include "animalHeader.h"

enum TailType {
    STRAIGHT,
    CORKSCREW,
    CURL_UP,
    CURL_RIGHT,
    CURL_LEFT
};

class Pig : public Animal {
    private:
        TailType tailType;
    public:

        // Constructors & Destructors
        Pig();
        ~Pig();

        // Getters
        TailType getTailType();

        // Setters
        void setTailType(TailType tailType);

        /*
         * tailTypeString
         *
         * This method is used to return the string representation of the tail type
         */
        string getTailTypeString();

        /*
         * displayAnimal
         *
         * This method is used to display the animal's information in a table
         */
        void displayAnimal();

        /*
         * displayTableHeader
         *
         * This method is used to display the header of the animal's table
         */
        void displayTableHeader();
};

#endif //PIGHEADER_H
