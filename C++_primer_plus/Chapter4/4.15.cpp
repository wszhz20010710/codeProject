// 指针变量的应用
// &运算符获得地址，*运算符获得值
#include <iostream>

using namespace std;

int main(){
    int updates = 6;
    int *p_updates; // 定义一个指针

    p_updates = &updates; // 让指针指向updates所在的地址

    // p_updates 是updates存储地址
    // 但*p_updates表示在p_updates指向内存单元中的值
    cout << "Values: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;

    cout << "Address: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;

    return 0;
}