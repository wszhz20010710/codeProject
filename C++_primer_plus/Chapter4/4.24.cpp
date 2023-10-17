// 比较数组、vector对象、array对象
#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main(){
    // c, original c++
    double a1[4] = {1.2,2.4,3.6,4.8};

    // c++98 STL
    vector<double> a2(4);
    a2[0] = 1.0/3.0;
    a2[1] = 1.0/5.0;
    a2[2] = 1.0/7.0;
    a2[3] = 1.0/9.0;

    // c++ 11
    array<double, 4> a3 = {3.14,2.72,1.62,1.41};
    array<double, 4> a4;
    a4 = a3;

    // array方法
    cout << "a1[2] = " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2] = " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2] = " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2] = " << a4[2] << " at " << &a4[2] << endl;

    // 错误示范
    a1[-2] = 20.2;
    // 找到a1所指的地方，向前移两个double元素，存储20.2
    // 20.2会被存放在数组外部，这是不安全的
    cout << "a1[-2] = " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2] = " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2] = " << a4[2] << " at " << &a4[2] << endl;
    
    return 0;
}