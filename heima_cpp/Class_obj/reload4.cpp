#include <iostream>
#include <string>
using namespace std;

// 递减运算符--的重载
class MyInterger
{
public:
    friend ostream& operator<<(ostream& cout, MyInterger myint);

    MyInterger()
    {
        m_num = 0;
    }

    MyInterger& operator--()
    {
        m_num--;
        return *this;
    }

    MyInterger operator--(int)
    {
        MyInterger temp = *this;
        m_num--;
        return temp;
    }
private:
    int m_num = 0;
};

ostream& operator<<(ostream& cout, MyInterger myint)
{
    cout << myint.m_num;
    return cout;
}

void test01()
{
    MyInterger myint;
    cout << myint << endl;
    cout << myint-- << endl;
    cout << (myint--)-- << endl;
}

void test02()
{
    MyInterger myint;
    cout << myint << endl;
    cout << --myint << endl;
    cout << --(--myint) << endl;
}

int main(){

    test01();
    test02();
    system("pause");
    return 0;
}