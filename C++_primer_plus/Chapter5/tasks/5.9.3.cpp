#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int sum = 0;
    do
    {
        cout << "Please enter a number:";
        cin >> a;
        sum += a;
        cout << "Present sum is " << sum << endl;
    } while (a != 0);
    
    return 0;
}