// 计算数的阶乘
#include <iostream>

using namespace std;
const int ArSize = 16;

int main(){
    long long product[ArSize];
    product[1] = product[0] = 1LL;
    for (int i = 2; i < ArSize; i++)
    {
        product[i] = i * product[i-1];
    }
    for (int i = 0; i < ArSize; i++)
    {
        cout << i << "! = " << product[i] << endl;
    }
    
    return 0;
}