//sqrt.cpp -- how to use the sqrt() function

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float a,b;
    
    while (true)
    {
        cout << "type in a  positive number, return its sqaure feet" << endl;
        cin >> a;
        if (a < 0)  {
            cout << "you should type in a positive number" << endl;
            continue;
        }

        b = sqrt(a);
        cout << "the square feet is " << b << endl;
        
    }
    return 0;
    
}