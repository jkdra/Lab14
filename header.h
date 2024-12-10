//
// Created by Jawad Khadra on 12/9/24.
//

#ifndef HEADER_H
#define HEADER_H

#include "animalHeader.h"
#include "sheepHeader.h"
#include "pigHeader.h"
#include <fstream>

const int MAX_ANIMALS = 5;

using namespace std;

enum MenuOptions {
    INIT_ANIMALS = 1,
    INIT_PIG = 2,
    INIT_SHEEP = 3,
    CHANGE_AGE = 4,
    DISPLAY = 5,
    EXIT = 0
};

/*
 * displayHeader
 *
 * This method is used to display the header of the lab
 */
void displayHeader();

/*
 * displayMenu
 *
 * This method is used to display the menu to the user
 */
void displayMenu(Pig pigs[]);

/*
 * loadPigs
 *
 * This method is used to load the pigs from the file
 */
void loadPigs(Pig pigs[]);

/*
 * loadSheep
 *
 * This method is used to load the sheep from the file
 */
void loadSheep(Sheep sheep[]);

/*
 * changeAge
 *
 * This method is used to change the age of the animal
 */
void changeAge(Pig pigs[], Sheep sheep[]);

/*
 * isValidIntInput
 *
 * This method is used to check if the input is a valid integer
 */
bool isValidIntInput(int min, int max, int input);

#endif //HEADER_H
