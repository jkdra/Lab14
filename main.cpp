/*
 * AUTHOR : Jawad Khadra
 * STUDENT ID : 1312092 (IVC)
 * LAB #14 - Inheritance, Overloading, and Redefining
 * CLASS : CS1B
 * SECTION : MW: 7:30p - 9:50p
 * DUE DATE : December 9, 2024
 */


#include "header.h"

using namespace std;

// main
int main() {
    MenuOptions menuOption = INIT_ANIMALS;        // INPUT - Stores the user's menu choice
    int menuOptionInput;           // INPUT - Stores the user's menu choice
    int animalCount = 0;           // COUNTER - Keeps track of the number of animals
    Pig pigs[MAX_ANIMALS];         // ARRAY - Stores the pigs
    Sheep sheep[MAX_ANIMALS];      // ARRAY - Stores the sheep

    displayHeader();

    while (menuOption != EXIT) {
        displayMenu(pigs);
        cin >> menuOptionInput;

        if (!isValidIntInput(0, pigs[0].getName() == "" ? 1 : 4, menuOptionInput)) continue;

        if (pigs[0].getName() != "" && menuOptionInput != 0) menuOptionInput++; // Add one to the menu option to account for the pigs if they are initialized already
        menuOption = static_cast<MenuOptions>(menuOptionInput);

        switch (menuOption) {
            case INIT_ANIMALS:  // 1
                loadSheep(sheep);
                loadPigs(pigs);
                break;
            case INIT_PIG:  // 2
                loadPigs(pigs);
            break;
            case INIT_SHEEP:  // 3
                loadSheep(sheep);
                break;
            case CHANGE_AGE:  // 4
                changeAge(pigs, sheep);
                break;
            case DISPLAY:  // 5
                pigs[0].displayTableHeader();
                for (Pig pigElement : pigs) if (pigElement.getName() != "") pigElement.displayAnimal();
                sheep[0].displayTableHeader();
                for (Sheep sheepElement : sheep) if (sheepElement.getName() != "") sheepElement.displayAnimal();
                break;
            case EXIT:  // 0
                break;
            default:
                break;
        }

    }
    return 0;
}