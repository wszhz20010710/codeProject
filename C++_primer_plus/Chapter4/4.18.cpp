// 使用new来创建动态数组
// 动态数组：数组在程序运行时创建

/*
    不要用delete释放不是new分配的内存
    不要用delete释放一个内存块两次
    使用new[]则应该用delete[]释放
    使用new[]为实体分配内存则应该用delete释放
    对空指针使用delete是安全的
*/
#include <iostream>

using namespace std;

int main(){
    double* p3 = new double [3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;
    // p3[3] = 0.9;
    cout << "p3[1] is " << p3[1] << ".\n";
    p3 = p3 + 1;
    // 表示p3[0]现在指向数组的第2个值
    cout << "Now p3[0] is " << p3[0] << " and ";
    cout << "p3[1] is " << p3[1] << ".\n";
    p3 = p3 - 1;
    // 指针指向原来的值，程序便可以给delete[]提供正确的地址
    delete [] p3;
    return 0;
}
