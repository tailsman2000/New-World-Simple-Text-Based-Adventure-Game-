#include <iostream>
#include <string>

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

    return 0;
}
