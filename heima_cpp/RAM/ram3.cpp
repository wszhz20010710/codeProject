#include <iostream>
// 堆区
using namespace std;

int * func()
{
    int * p = new int(10);
    return p;
}

int main()
{
    int * p = func();

    cout << *p << endl;
    
    return 0;
}