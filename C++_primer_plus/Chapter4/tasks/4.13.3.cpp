#include <iostream>
#include <cstring>

using namespace std;

int main(){
    const int StrSize = 20;
    char firstname[StrSize];
    char lastname[StrSize];

    cout << "Enter your first name: ";
    cin.getline(firstname, StrSize);
    cout << "Enter your last name: ";
    cin.getline(lastname, StrSize);

    char comma[StrSize] = ", ";
    strcat(lastname, comma);
    strcat(lastname, firstname);

    cout << "Here's the information in a single string: " 
         << lastname;
    return 0;
}