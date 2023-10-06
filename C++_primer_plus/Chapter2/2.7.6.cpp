// light years -> astronmical units
#include <iostream>

using namespace std;

double LYtoAU(double ly)
{
    double au;
    au = 63240 * ly;
    return au;
}

int main()
{
    double ly,au;
    cout << "Enter the number of light years: ";
    cin >> ly;
    au = LYtoAU(ly);
    cout << ly << " light years = " << au << " astronomical units.";
    return 0;
}