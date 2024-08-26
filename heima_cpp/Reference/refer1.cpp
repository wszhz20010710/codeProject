#include <iostream>

using namespace std;

int main()
{
    // 引用的基本语法
    int a = 10;
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    b = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    system("pause");
    return 0;
}