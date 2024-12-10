//
// Created by Jawad Khadra on 12/9/24.
//

#ifndef ANIMALHEADER_H
#define ANIMALHEADER_H

#include <iostream>
#include <iomanip>

using namespace std;

// animal class
class Animal {
    private:
        string name;
        int age;
    public:
        // Constructors & Destructors
        Animal();
        ~Animal();

        // Getters
        string getName();
        int getAge();

        // Setters
        void setName(string name);
        void setAge(int age);

        /*
         * modify
         *
         * This method is used to modify the name or age of an animal
         * It takes in a string and/or an int and modifies the animal accordingly
         */
        void modify(string newName);
        void modify(int newAge);
        void modify(string newName, int newAge);

        /*
         * displayAnimal
         *
         * This method is used to display the animal's information in a table
         */
        void displayAnimal();

        /*
         * displayHeader
         *
         * This method is used to display the header of the animal's table
         */
        static void displayTableHeader();
};

#endif //ANIMALHEADER_H
