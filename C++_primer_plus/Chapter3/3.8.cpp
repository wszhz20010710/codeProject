// floatnum.cpp -- float type

#include <iostream>

using namespace std;

int main()
{

    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tub = 10.0 / 3.0 ; //只能保持6位精确
    double mint = 10.0 / 3.0 ;//双精度更加精确
    const float million = 1.0e6;


    cout << "tub = " << tub << endl;
    cout << "a million tubs = " << million * tub << endl; 
    cout << "ten million tubs = " << 10 * million * tub << endl;
    cout << endl;
    
    cout << "mint = " << mint << endl;
    cout << "a million mints = " << million * mint << endl; 
    cout << "ten million mints = " << 10 * million * mint << endl;
    cout << endl;

    return 0;
    
}