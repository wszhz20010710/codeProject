#include <iostream>
#include <string>

using namespace std;

struct car
{
    string Producer;
    int date;
};


int main()
{
    cout << "How many cars do you wish to catalog?" ;
    int num;
    cin >> num;
    car *ptr = new car[num];
    for(int i=0;i < num; i++)
    {
        cout << "please enter the make of the car #" << i+1 << ":" << endl;
        cin >> ptr[i].Producer;
        cout << "please enter the date of the car #" << i+1 << ":" << endl;
        cin >> ptr[i].date;
    }
    cout << "Here is your collection:" << endl;
    for(int i = 0;i < num; i++)
    {
        cout << ptr[i].date << "  " << ptr[i].Producer << endl;
    }

    return 0;
}