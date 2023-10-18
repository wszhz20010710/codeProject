// ++运算符和--运算符
#include <iostream>

using namespace std;

int main(){
    int a = 20;
    int b = 20;

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a++ = " << a++ << ", ++b = " << ++b << endl;
    /*
        a++使用a的当前值计算表达式，然后将a的值+1
        ++b先将b的值+1，然后使用新的值来计算表达式
    */
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}