#include <iostream>

using namespace std;

double mean(double x, double y);

int main()
{
    double x;
    double y;
    while (true)
    {
        cout << "Please input 2 numbers: ";
        cin >> x >> y;
        cout << "Average = " << mean(x,y) << endl;
        if (x==0 || y == 0)
        {
            break;
        }
    }
    
    return 0;
}

double mean(double x, double y)
{
    double res;
    res = 2.0 * x * y / (x + y);
    return res;
}