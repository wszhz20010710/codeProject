// 指针、数组和指针算数
// c++ 将数组名解释为地址

#include <iostream>

using namespace std;

int main(){
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3,2,1};
    /*
     cout << stacks << endl 表示stack[0]的地址
        是指向元素的short指针
     cout << &stacks << endl 表示数组stacks的地址 -> 数值相同 意义不同
        是指向数组的数组指针
     stacks+1 地址值+2，表示跳过第一个元素；&stacks+1 地址+3*2，表示跳过整个数组
    */

    // 下面展示两种得到数组地址的方法
    double* pw = wages; // 实际将pw初始化为wages数组第一个元素的地址
    short* ps = &stacks[0];

    // pw 指针+1，地址每次+8，double类型占用8字节
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw += 1;
    cout << "add 1 to the pw pointer: \n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n";
    pw += 1;
    cout << "add 2 to the pw pointer: \n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

    // ps 指针+1，地址每次+2， short类型占用2字节
    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps += 1;
    cout << "add 1 to the ps pointer: \n";
    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps += 1;
    cout << "add 2 to the ps pointer: \n";
    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    cout << endl;

    // 数组索引方法获取值
    cout << "access 3 elements with array notation\n";
    cout << "stacks[0] = " << stacks[0] 
         << ", stacks[1] = " << stacks[1] 
         << ", stacks[2] = " << stacks[2] << "\n\n";

    // 指针方法获取值
    cout << "access 3 elements with pointer notation\n";
    cout << "*stacks = " << *stacks 
         << ", *(stacks+1) = " << *(stacks + 1) 
         << ", *(stacks+2) = " << *(stacks + 2)
         << endl << endl;
    
    // 大小
    cout << "size of wages array = " << sizeof(wages) << endl;// 3个double元素 3*8 = 24
    cout << "size of pw pointer = " << sizeof(pw) << endl;// 指针占用8字节
    cout << endl;
    cout << "size of stacks array = " << sizeof(stacks) << endl;// 3个short元素 3*2 = 6
    cout << "size of ps pointer = " << sizeof(ps) << endl;// 指针占用8字节
    return 0;
}