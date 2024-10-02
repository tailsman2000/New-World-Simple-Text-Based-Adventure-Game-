#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Function that displays a block of text and waits for the user to press 1 to continue
void displayTextAndContinue(const string& text) {
    cout << text << endl; // Display the text

    int userInput = 0;
    cout << "Press 1 to continue..." << endl;

    // Loop until the user presses 1
    while (userInput != 1) {
        cin >> userInput;
        if (userInput != 1) {
            cout << "Please press 1 to continue." << endl;
        }
    }
    // Clear any remaining input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function that generates and returns a save password based on progress
string generatePassword(bool hasForestItem, bool hasCaveItem, bool hasMountainItem, bool hasLakeItem) {
    string password = "";
    password += hasForestItem ? "F" : "-";
    password += hasCaveItem ? "C" : "-";
    password += hasMountainItem ? "M" : "-";
    password += hasLakeItem ? "L" : "-";
    return password;
}

// Function to save the game and display the password
void saveGame(bool hasForestItem, bool hasCaveItem, bool hasMountainItem, bool hasLakeItem) {
    string password = generatePassword(hasForestItem, hasCaveItem, hasMountainItem, hasLakeItem);
    cout << "Your progress has been saved. Your save password is: " << password << endl;
}

// Function to load the game based on password
void loadGameFromPassword(const string& password, bool &hasForestItem, bool &hasCaveItem, bool &hasMountainItem, bool &hasLakeItem) {
    if (password.length() == 4) {
        hasForestItem = (password[0] == 'F');
        hasCaveItem = (password[1] == 'C');
        hasMountainItem = (password[2] == 'M');
        hasLakeItem = (password[3] == 'L');
    } else {
        cout << "Invalid password! Starting a new game." << endl;
        hasForestItem = false;
        hasCaveItem = false;
        hasMountainItem = false;
        hasLakeItem = false;
    }
}

// Function that outputs a message, confirming the user wants to start
string adventureStartConfirm() {
    string adventureConfirm;
    cout << "For this, you are going to need a bit of an imagination..." << endl;
    cout << "So make sure to sit back, relax, and enjoy the tale!" << endl;
    cout << "Are you ready? (type in YES!, or we can't let you experience the adventure...)" << endl;
    cin >> adventureConfirm;

    cin.ignore();
    while (adventureConfirm != "YES!") {
        cout << "C'mon, the world is waiting for ya." << endl;
        cout << "Let's try this again..." << endl; 
        cout << "Are you ready? (type in YES!, or we can't let you experience the adventure...)" << endl;
        cin >> adventureConfirm;
    }
    return "Let the journey begin, have fun!";
}

// Function to describe the player falling asleep and waking up in the fantasy world
void transitionToFantasyWorld() {
    displayTextAndContinue("It's raining... You return home from a long day of work.");
    displayTextAndContinue("Exhausted, you fall into bed and quickly drift off to sleep...");
    displayTextAndContinue("Suddenly, you wake up in a strange new world! The sky is purple, and strange creatures wander around.");
    displayTextAndContinue("A mysterious voice tells you that in order to return home, you must retrieve four magical items from four dungeons.");
    displayTextAndContinue("The dungeons are located in the forest, the cave, the mountain, and the lake.");
}

// Functions for the dungeons (one for each area)
bool exploreForest() {
    displayTextAndContinue("You venture into the dense forest, hearing the rustling of leaves.");
    displayTextAndContinue("After navigating through twisting paths, you find a hidden dungeon.");
    displayTextAndContinue("Inside the dungeon, you defeat a mighty tree guardian and obtain the **Forest Amulet**.");
    saveGame(true, false, false, false);
    return true;
}

bool exploreCave() {
    displayTextAndContinue("You descend into a dark, cold cave. The air is damp and still.");
    displayTextAndContinue("After solving puzzles in the cave, you face a stone golem and claim the **Cave Gem**.");
    saveGame(false, true, false, false);
    return true;
}

bool exploreMountain() {
    displayTextAndContinue("You climb the towering mountain. The wind howls around you.");
    displayTextAndContinue("At the peak, you battle a dragon and earn the **Mountain Stone**.");
    saveGame(false, false, true, false);
    return true;
}

bool exploreLake() {
    displayTextAndContinue("You swim through a mysterious lake, diving into its depths.");
    displayTextAndContinue("In an underwater temple, you defeat a water serpent and secure the **Lake Pearl**.");
    saveGame(false, false, false, true);
    return true;
}

// Final castle exploration and decision-making
void exploreCastle() {
    displayTextAndContinue("With all four items in hand, you enter the majestic castle.");
    displayTextAndContinue("Inside, a portal opens to your home, but the voice returns: 'You have a choice to make.'");
    displayTextAndContinue("Do you wish to stay in this fantasy world, or return to your normal life?");

    cout << "1. Stay in the fantasy world" << endl;
    cout << "2. Return home" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        displayTextAndContinue("You choose to stay and live out your days in this magical world.");
    } else {
        displayTextAndContinue("You step through the portal, leaving the adventure behind and returning to your home.");
    }
}

// Main menu for exploring areas and dungeons
void mainMenu(bool &hasForestItem, bool &hasCaveItem, bool &hasMountainItem, bool &hasLakeItem) {
    int choice;
    cout << "Where would you like to go?" << endl;
    cout << "1. Forest" << endl;
    cout << "2. Cave" << endl;
    cout << "3. Mountain" << endl;
    cout << "4. Lake" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            if (!hasForestItem) {
                hasForestItem = exploreForest();
            } else {
                cout << "You've already retrieved the Forest Amulet." << endl;
            }
            break;
        case 2:
            if (!hasCaveItem) {
                hasCaveItem = exploreCave();
            } else {
                cout << "You've already retrieved the Cave Gem." << endl;
            }
            break;
        case 3:
            if (!hasMountainItem) {
                hasMountainItem = exploreMountain();
            } else {
                cout << "You've already retrieved the Mountain Stone." << endl;
            }
            break;
        case 4:
            if (!hasLakeItem) {
                hasLakeItem = exploreLake();
            } else {
                cout << "You've already retrieved the Lake Pearl." << endl;
            }
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
    }
}

int main() {
    string userName;
    int userNameConfirm;
    bool hasForestItem = false;
    bool hasCaveItem = false;
    bool hasMountainItem = false;
    bool hasLakeItem = false;
    
    cout << "Welcome to the adventure! \n";
    cout << "1. Start a new game\n";
    cout << "2. Load from password\n";
    
    int menuChoice;
    cin >> menuChoice;
    cin.ignore(); // Clear input buffer

    if (menuChoice == 2) {
        string password;
        cout << "Please enter your save password: ";
        cin >> password;
        loadGameFromPassword(password, hasForestItem, hasCaveItem, hasMountainItem, hasLakeItem);
        cin.ignore(); // Clear input buffer
    }

    if (menuChoice == 1 || (menuChoice == 2 && !hasForestItem && !hasCaveItem && !hasMountainItem && !hasLakeItem)) {
        cout << "To start off, let's get your first name.\n";
        getline(cin, userName);
    
        cout << userName << "? Are you sure? (1 = yes, 2 = no, change it)\n";
        cin >> userNameConfirm;
        cin.ignore(); // Clear the buffer
    
        while (userNameConfirm == 2) {
            cout << "Please re-enter your first name. \n";
            getline(cin, userName);  // Get the new name
    
            cout << userName << "? Are you sure? (1 = yes, 2 = no, change it)\n";
            cin >> userNameConfirm;
            cin.ignore();  // Clear the buffer
        }

        cout << "Great! Welcome to the adventure, " << userName << "!" << endl;

        // Start the adventure with the intro and confirmation
        string adventureBeginMessage = adventureStartConfirm();
        cout << adventureBeginMessage << endl;

        transitionToFantasyWorld();
    }

    // Main game loop
    while (!hasForestItem || !hasCaveItem || !hasMountainItem || !hasLakeItem) {
        mainMenu(hasForestItem, hasCaveItem, hasMountainItem, hasLakeItem);
    }

    // Once all items are collected, proceed to the final stage
    exploreCastle();

    return 0;
}
