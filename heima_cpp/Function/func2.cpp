#include <iostream>
using namespace std;

// 函数的占位参数
void func(int a, int = 10)
{
    cout << "this is func" << endl;
}

int main()
{
    func(10);


    system("pause");
    return 0;
}