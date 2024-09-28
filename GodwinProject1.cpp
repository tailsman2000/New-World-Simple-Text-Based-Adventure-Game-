#include <iostream>
#include <string>

using namespace std;

int main() {
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
    
    

    return 0;
}
