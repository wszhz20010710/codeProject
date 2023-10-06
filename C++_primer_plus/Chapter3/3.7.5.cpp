#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the world's population: ";
    long long world_popu;
    cin >> world_popu;
    cout << "Enter the population of the US: ";
    long long us_popu;
    cin >> us_popu;
    double rate;
    rate = (double)us_popu / (double)world_popu * 100;
    cout << "The population of the US is " << rate <<
    "%" << " of the world population.";
}