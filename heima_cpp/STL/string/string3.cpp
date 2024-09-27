#include<iostream>
#include<string>
using namespace std;

// string的拼接操作

void test01()
{
    string str1 = "I";
    str1 += " like playing games";
    cout << "str1 = " << str1 << endl;

    str1 += ".";
    cout << "str1 = " << str1 << endl;

    string str2;
    str2 = " Apex LOL";
    str1 += str2;
    cout << "str1 = " << str1 << endl;

    string str3 = "I";
    str3.append(" love ");
    cout << "str3 = " << str3 << endl;

    str3.append("game abcde", 4);
    cout << "str3 = " << str3 << endl;

    str3.append(str2);
    cout << "str3 = " << str3 << endl;

    str3.append(str2,6,3);
    cout << "str3 = " << str3 << endl;
}

int main()
{

    test01();

    system("pause");
    return 0;
}