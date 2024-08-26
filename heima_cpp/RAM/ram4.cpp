#include <iostream>

// new开辟数据
using namespace std;

// new的基本语法
int * func()
{
    // new create int data
    int * p = new int(10);
    return p;
}

void test01()
{
    int * p = func();
    cout << *p << endl;
    cout << *p << endl;

    // release ram
    delete p;
    cout << *p << endl;
}

// 在堆区开辟数组
void test02()
{
    int * arr = new int[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100;
    }
    
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    // 释放堆区数组要加一个中括号
    delete[] arr;
    
}


int main()
{
    //test01();
    test02();

    


    system("pause");
    return 0;
}