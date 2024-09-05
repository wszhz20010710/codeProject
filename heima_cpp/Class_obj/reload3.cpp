#include <iostream>
#include <string>
using namespace std;

// 递增运算符++的重载

// 自定义整型
class MyInterger
{
    friend ostream& operator<<(ostream& cout, MyInterger myint);
public:
    MyInterger()
    {
        m_num = 0;
    }

    // 重载前置++运算符
    // 返回引用是为了一直对一个数据进行递增操作
    MyInterger& operator++()
    {
        // 先++
        m_num++;
        // 在返回自身
        return *this;
    }

    // 重载后置++运算符
    // void operator++(int)，int代表占位参数
    // 用于区分前置和后置递增
    // 返回值，局部变量的引用在程序结束后就释放，此时返回变成非法操作
    MyInterger operator++(int)
    {
        // 先记录结果
        MyInterger temp = *this;
        // 后进行递增
        m_num++;
        // 最后返回记录结果
        return temp;
    }

private:
    int m_num;
};

ostream& operator<<(ostream& cout, MyInterger myint)
{
    cout << myint.m_num;
    return cout;
}

void test01()
{
    MyInterger myint;

    cout << ++myint << endl;
    cout << myint << endl;
}

void test02()
{
    MyInterger myint;
    cout << myint++ << endl;
    cout << myint << endl;
}

int main(){

    test01();
    test02();

    system("pause");
    return 0;
}