#include <iostream>
#include <string>
using namespace std;

// 函数调用运算符（）重载

// 打印输出类
class MyPrinter
{
public:
    // 重载函数调用运算符
    void operator()(string test)
    {
        cout << test << endl;
    }
};

void test01()
{
    MyPrinter mp1;
    mp1("hello world!");
}

// 仿函数没有固定写法，非常灵活

// 加法类
class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

void test02()
{
    MyAdd ma;
    int ret = ma(100, 200);
    cout << "ret = " << ret << endl;

    // 匿名函数对象：当前行用完直接释放
    cout << MyAdd()(100, 100) << endl;
}

int main(){
    
    //test01();
    test02();


    system("pause");
    return 0;
}