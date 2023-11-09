#include <iostream>
#include <array>

using namespace std;
const int ArSize = 16;

int main()
{
    array <long double, ArSize> products;
    products[0] = products[1] = 1;
    for (size_t i = 2; i < ArSize; i++)
    {
        products[i] = i * products[i-1];
    }
    for (size_t i = 0; i < ArSize; i++)
    {
        cout << i << "! = " << products[i] << endl;
    }
    
    
    return 0;
}