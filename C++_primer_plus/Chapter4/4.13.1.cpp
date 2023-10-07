// 共用体union的用法
// 每次只能存储一个值，长度为最大成员的长度
// 数据项使用两种或更多格式但不同时使用时，可节约空间
#include <iostream>

using namespace std;

union one4all
{
    int int_val;
    long long_val;
    double double_val;
};


int main(){
    one4all pail;
    pail.int_val = 114;
    cout << pail.int_val << endl;
    pail.double_val = 514.810;
    cout << pail.double_val << endl;

    return 0;
}

