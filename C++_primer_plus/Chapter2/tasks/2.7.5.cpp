// Celsius temperature -> Fahrenheit temperature
#include <iostream>

using namespace std;

double CelToFah(double cel)
{
    double fah;
    fah = 1.8 * cel + 32.0;
    return fah;
}


int main()
{
    double cel,fah;
    cout << "Please enter a Celsius value:" ;
    cin >> cel;
    fah = CelToFah(cel);
    cout << cel <<" degrees Celsius is " << fah << " degrees Fahrenheit.";
    return 0;
}