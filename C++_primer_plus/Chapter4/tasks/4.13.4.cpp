#include <iostream>
#include <string>

using namespace std;

int main(){
    string firstname;
    string lastname;
    cout << "Enter your first name: ";
    cin >> firstname;
    cout << "Enter your last name: ";
    cin >> lastname;

    cout << "Here's the information in a single string: " 
         << lastname << ", " << firstname;
    return 0;
}