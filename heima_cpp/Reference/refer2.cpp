#include <iostream>

using namespace std;

// 引用的注意事项

int main()
{
    int a = 10;

    
    // 1.必须要初始化本体
    // int &b;  wrong!
    int &b = a;

    // 2.引用一旦初始化，就不可以更改
    int c = 20;
    b = c; // 赋值操作，不是更改引用

    // a=b=c=20
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    system("pause");
    return 0;
}