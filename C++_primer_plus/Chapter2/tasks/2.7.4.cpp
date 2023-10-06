#include <iostream>

using namespace std;

int main()
{
    int age,month;
    cout << "Please enter your age!" << endl;
    cin >> age;
    month = age * 12;
    cout << "It contains " << month << " months.";
    return 0;
}