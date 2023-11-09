#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter two integers." << endl;
    cout << "Enter the smaller one: ";
    int small;
    cin >> small;
    cout << "Enter the biggerr one: ";
    int big;
    cin >> big;
    int sum = 0;
    for (size_t i = small; i < big+1; i++)
    {
        sum += i;
    }
    cout << "The sum of numbers between " << small << " and " << big
         << " is " << sum << endl;

    return 0;
}