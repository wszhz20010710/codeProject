#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// 多态案例——计算器类

// 普通实现
class Calculator1
{
public:
    int getResult(string oper)
    {
        if (oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if (oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if (oper == "*")
        {
            return m_Num1 * m_Num2;
        }
        else
            return 0;
        // 如果想扩展新功能，需要修改源码
    }

    int m_Num1;
    int m_Num2;
};

// 多态实现
// 先实现计算器抽象类
class AbstractCal
{
public:
    virtual int getResult()
    {
        return 0;
    }

    int m_NUM1;
    int m_NUM2;

};

// 加减乘法类
class AddCal : public AbstractCal
{
public:
    int getResult()
    {
        return m_NUM1 + m_NUM2;
    }
};

class SubCal : public AbstractCal
{
public:
    int getResult()
    {
        return m_NUM1 - m_NUM2;
    }
};

class MulCal : public AbstractCal
{
public:
    int getResult()
    {
        return m_NUM1 * m_NUM2;
    }
};

class PowCal : public AbstractCal
{
public:
    int getResult()
    {
        return pow(m_NUM1, m_NUM2);
    }
};





void test01()
{
    Calculator1 c1;
    c1.m_Num1 = 10;
    c1.m_Num2 = 20;

    cout << c1.m_Num1 << " + " << c1.m_Num2 << " = " << c1.getResult("+") << endl;
    cout << c1.m_Num1 << " - " << c1.m_Num2 << " = " << c1.getResult("-") << endl;
    cout << c1.m_Num1 << " * " << c1.m_Num2 << " = " << c1.getResult("*") << endl;

}

void test02()
{
    // add
    AbstractCal * ptr = new AddCal;
    ptr->m_NUM1 = 10;
    ptr->m_NUM2 = 20;
    cout << ptr->m_NUM1 << " + " << ptr->m_NUM2 << " = " << ptr->getResult() << endl;
    delete ptr;

    ptr = new SubCal;
    ptr->m_NUM1 = 10;
    ptr->m_NUM2 = 20;
    cout << ptr->m_NUM1 << " - " << ptr->m_NUM2 << " = " << ptr->getResult() << endl;
    delete ptr;

    ptr = new MulCal;
    ptr->m_NUM1 = 10;
    ptr->m_NUM2 = 20;
    cout << ptr->m_NUM1 << " * " << ptr->m_NUM2 << " = " << ptr->getResult() << endl;
    delete ptr;

    ptr = new PowCal;
    ptr->m_NUM1 = 2;
    ptr->m_NUM2 = 8;
    cout << ptr->m_NUM1 << " ^ " << ptr->m_NUM2 << " = " << ptr->getResult() << endl;
    delete ptr;
}

int main(){

    test02();

    system("pause");
    return 0;
}
