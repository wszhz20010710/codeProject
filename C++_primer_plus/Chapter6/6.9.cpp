// 此节讲 ?:运算符
#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cout << "Please enter two integers: ";
    cin >> a >> b;
    cout << "The larger of " << a << " and " << b;
    int c = a > b ? a : b;
    cout << " is " << c << endl;
    
    return 0;
}