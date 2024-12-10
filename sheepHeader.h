//
// Created by Jawad Khadra on 12/9/24.
//

#ifndef SHEEPHEADER_H
#define SHEEPHEADER_H

#include "animalHeader.h"

enum WoolType {
    LONG,
    MEDIUM,
    FINE,
    CARPET
};

class Sheep : public Animal {
    private:
        WoolType woolType;
        string color;
    public:
        Sheep();
        ~Sheep();

        // Getters
        WoolType getWoolType();
        string getColor();

        // Setters
        void setWoolType(WoolType woolType);
        void setColor(string color);

        /*
         * woolTypeString
         *
         * This method is used to return the string representation of the wool type
         */
        string getWoolTypeString();

        /*
         * displayTable
         *
         * This method is used to display the animal's information in a table
         */
        void displayAnimal();

        /*
         * displayHeader
         *
         * This method is used to display the header of the sheep's table
         */
        void displayTableHeader();
};

#endif //SHEEPHEADER_H
