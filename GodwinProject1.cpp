#include <iostream>
#include <string>
#include <limits>

using namespace std;

//Function that outputs a message, confirming the user wants to start
//Message loops until the user chooses to start with confirm word
string adventureStartConfirm(){
    string adventureConfirm;
    cout << "For this, you are going to need a bit of an imagination..." << endl;
    cout << "So make sure tosit back, relax, and enjoy the tale!" << endl;
    cout << "Are you ready? (type in YES!, or we cant let you experience the adventure....)" << endl;
    cin >> adventureConfirm;

    cin.ignore();
    while (adventureConfirm != "YES!"){
        cout << "C'mon, the world is waiting for ya." << endl;
        cout << "Let's try this again..." << endl; 
        cout << "Are you ready? (type in YES!, or we cant let you experience the adventure....)" << endl;
        cin >> adventureConfirm;
    }
    return "Let the journey begin, have fun!";
}

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

int main(){
    string userName;
    int userNameConfirm;
    
    cout << "Welcome to the adventure! \n";
    cout << "To start off, let's get your first name.\n";
    
    getline(cin, userName);
    
    cout << userName << "? Are you sure? (1 = yes, 2 = no, change it)\n";
    cin >> userNameConfirm;

    // Clear the newline character left in the buffer
    cin.ignore();

    // Loop until the user confirms their name
    while (userNameConfirm == 2) {
        cout << "Please re-enter your first name. \n";
        getline(cin, userName);  // Get the new name

        cout << userName << "? Are you sure? (1 = yes, 2 = no, change it)\n";
        cin >> userNameConfirm;

        // Clear the newline character again after cin
        cin.ignore();
    }
    

    cout << "Great! Welcome to the adventure, " << userName << "!" << endl;

    //Declaring the adventure start function
    string adventureBeginMessage = adventureStartConfirm();
    cout << adventureBeginMessage << endl;

    cout << "It's raining... \n";
    cout << "You return home from a long day of work. \n";
    cout << "Exhausted, the f";

    return 0;
}

