//
// Created by Jawad Khadra on 12/9/24.
//

#include "header.h"

/*
 * displayHeader
 *
 * This method is used to display the header of the lab
 */
void displayHeader() {
    cout
    << "* AUTHOR : Jawad Khadra\n"
    << "* STUDENT ID : 1312092 (IVC)\n"
    << "* LAB #14 - Inheritance, Overloading, and Redefining\n"
    << "* CLASS : CS1B\n"
    << "* SECTION : MW: 7:30p - 9:50p\n"
    << "* DUE DATE : December 9, 2024\n";
}

/*
 * displayMenu
 *
 * This method is used to display the menu to the user
 */
void displayMenu(Pig pigs[] /* only to check for initialization */) {
    if (pigs[0].getName() == "") {
        cout
        << "\nMENU:\n"
        << "1 - Initialize Animals\n"
        << "0 - Exit\n"
        << "Enter selection: ";
    } else {
        cout
        << "\nMENU:\n"
        << "1 - Re-Initialize Pigs\n"
        << "2 - Re-Initialize Sheep\n"
        << "3 - Change Age\n"
        << "4 - Display\n"
        << "0 - Exit\n"
        << "Enter selection: ";
    }
}

/*
 * loadPigs
 *
 * This method is used to load the pigs from the file
 */
void loadPigs(Pig pigs[]) {
    ifstream inFile;           // INPUT - Input file stream. This is declared here since it will only be used once.
    string pigName;            // INPUT - Name of the pig
    int pigAge;                // INPUT - Age of the pig
    string tailTypeString;     // INPUT - Tail type of the pig as a string
    TailType tailType;         // INPUT - Tail type of the pig

    inFile.open("Pigs.txt", ios::in);

    // First, clear the array
    for (int i = 0; i < MAX_ANIMALS; i++) pigs[i] = Pig();

    if (inFile.fail()) {
        cerr << "\nCould not open the input file\n";
        exit(EXIT_FAILURE);
    }

    int i = 0;            // COUNTER - Keeps track of the number of pigs loaded as well as the index of the pigs array
    while (!inFile.eof()) {
        getline(inFile, pigName);
        inFile >> pigAge;
        inFile.ignore();
        getline(inFile, tailTypeString);

        if (tailTypeString == "Straight") tailType = STRAIGHT;
        else if (tailTypeString == "Corkscrew") tailType = CORKSCREW;
        else if (tailTypeString == "Curl Up") tailType = CURL_UP;
        else if (tailTypeString == "Curl Right") tailType = CURL_RIGHT;
        else if (tailTypeString == "Curl Left") tailType = CURL_LEFT;
        else tailType = STRAIGHT;

        pigs[i] = Pig();
        pigs[i].setName(pigName);
        pigs[i].setAge(pigAge);
        pigs[i].setTailType(tailType);
        i++;

        inFile.ignore();  // Ignore the newline character after the pig's name
    }

    inFile.close();
}

/*
 * loadSheep
 *
 * This method is used to load the sheep from the file
 */
void loadSheep(Sheep sheep[]) {
    ifstream inFile;          // INPUT - Input file stream. This is declared here since it will only be used once.
    string sheepName;         // INPUT - Name of the sheep
    int sheepAge;             // INPUT - Age of the sheep
    WoolType woolType;        // INPUT - Wool type of the sheep
    string woolTypeString;    // INPUT - Wool type of the sheep as a string
    string color;             // INPUT - Color of the sheep

    inFile.open("Sheep.txt", ios::in);

    // First, clear the array
    for (int i = 0; i < MAX_ANIMALS; i++) sheep[i] = Sheep();

    if (inFile.fail()) {
        cerr << "\nCould not open the input file\n";
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (!inFile.eof()) {
        getline(inFile, sheepName);
        inFile >> sheepAge;
        inFile.ignore();

        getline(inFile, woolTypeString);

        if (woolTypeString == "Long") woolType = LONG;
        else if (woolTypeString == "Medium") woolType = MEDIUM;
        else if (woolTypeString == "Fine") woolType = FINE;
        else if (woolTypeString == "Carpet") woolType = CARPET;
        else woolType = LONG;

        getline(inFile, color);
        sheep[i] = Sheep();
        sheep[i].setName(sheepName);
        sheep[i].setAge(sheepAge);
        sheep[i].setWoolType(woolType);
        sheep[i].setColor(color);
        i++;

        inFile.ignore();  // Ignore the newline character after the sheep's name
    }
    inFile.close();
}

/*
 * changeAge
 *
 * This method is used to change the age of the animal
 */
void changeAge(Pig pigs[], Sheep sheep[]) {
    int animalType;                // INPUT - Stores the type of animal
    int animalIndex;               // INPUT - Stores the index of the animal
    int animalCount = 0;           // COUNTER - Keeps track of the number of animals
    int newAge;                    // INPUT - Stores the new age of the animal


    cout
    << "\nAre you changing the age of a pig or a sheep?\n"
    << "1 - Pig\n"
    << "2 - Sheep\n"
    << "Enter selection: ";

    cin >> animalType;
    cin.ignore();
    if (!isValidIntInput(1, 2, animalType)) return;

    cout << "\n";
    if (animalType == 1 /* Pig */) {
        for (int i = 0; i < MAX_ANIMALS; i++) {
            if (pigs[i].getName() != "") {
                cout << i + 1 << " - " << pigs[i].getName() << endl;
                animalCount++;
            }
        }
    } else if (animalType == 2 /* Sheep */) {
        for (int i = 0; i < MAX_ANIMALS; i++) {
            if (sheep[i].getName() != "") {
                cout << i + 1 << " - " << sheep[i].getName() << endl;
                animalCount++;
            }
        }
    }

    cout << "Enter the number of the animal you want to change: ";
    cin >> animalIndex;
    cin.ignore();
    animalIndex--; // Adjust the index to account for the pigs array
    if (!isValidIntInput(0, animalCount, animalIndex)) return;

    cout << "Enter the new age: ";
    cin >> newAge;
    cin.ignore();
    if (!isValidIntInput(0, 10, newAge)) return;

    if (animalType == 1) pigs[animalIndex].setAge(newAge);
    else if (animalType == 2) sheep[animalIndex].setAge(newAge);
}

/*
 * isValidIntInput
 *
 * This method is used to check if the input is a valid integer
 */
bool isValidIntInput(int min, int max, int input) {
    if (cin.fail()) {
        cout << "\n**** Please input a NUMBER between " << min << " and " << max << " ****\n";
        cin.clear();
        cin.ignore();
        return false;
    } else if (input < min || input > max) {
        cout << "\n\n**** The number " << input << " is an invalid entry.            ****\n";
        cout << "**** Please input a number between " << min << " and " << max << " ****\n\n";
        cin.clear();
        cin.ignore();
        return false;
    } else return true;
}