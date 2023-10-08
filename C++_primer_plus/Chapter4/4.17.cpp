// new运算符的应用
// new返回分配内存空间的首地址，控制权更大
#include <iostream>

using namespace std;

int main(){
    int nights = 1001;
    int *ptr = new int;
    *ptr = 1001;

    cout << "nights value = ";
    cout << nights << "; location = " << &nights << endl;
    cout << "int ";
    cout << "value = " << *ptr << "; location = " << ptr << endl;

    double *pd = new double;
    *pd = 10000001.0;
    cout << "double ";
    cout << "value = " << *pd << "; location = " << pd << endl;
    cout << "location of pointer pd: " << &pd << endl;

    cout << "size of ptr = " << sizeof(ptr) << endl;
    // ptr为地址，占用8个字节
    cout << "size of *ptr = " << sizeof(*ptr) << endl;
    // 而*ptr为int类型，占用4个字节
    cout << "size of pd = " << sizeof(pd) << endl;
    // pd为地址，占用8个字节
    cout << "size of *pd = " << sizeof(*pd) << endl;
    // 而*pd为double类型，同样占用8个字节

    return 0;
}

// 可用delete来释放使用new分配的内存，成对使用否则内存泄漏
// int * ps = new int;
// delete ps;
// 不可释放已经释放的内存块
// 不要创建两个指向同一个内存块的指针
