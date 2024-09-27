#include<iostream>
#include<string>
using namespace std;

// string中的字符存取功能
void test01()
{
    string str = "hello";
    cout << "str = " << str << endl;

    // 1.通过[]方式取字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << endl;
    }

    cout << endl;

    // 2.通过at方法取字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << endl;
    }

    // 修改单个字符
    str[0] = 'x';
    cout << "str = " << str << endl;

    str.at(1) = 'x';
    cout << "str = " << str << endl;
    
}

int main()
{
    test01();


    system("pause");
    return 0;
}