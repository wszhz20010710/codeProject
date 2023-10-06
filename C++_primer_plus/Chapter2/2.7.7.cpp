// formated-print hour&minute
#include <iostream>

using namespace std;

void DispTime(int hour,int minute)
{
    cout << "Time: " << hour << ":" << minute; 
}

int main()
{
    cout << "Enter the number of hours: ";
    int hour;
    cin >> hour;
    cout << "Enter the number of minutes: ";
    int minute;
    cin >> minute;
    DispTime(hour,minute);
    return 0;
}