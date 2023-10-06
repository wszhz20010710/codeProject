#include <iostream>
#include <string>

using namespace std;

/*
编写程序，要求：
输入名，姓，应得的成绩，年龄
输出姓名，成绩，年龄
*/

int main()
{
    string first_name;
    string last_name;
    char grade;
    int age;
    cout << "输入您的名字：";
    cin >> first_name;
    cout << "输入您的姓：";
    cin >> last_name;
    cout << "输入您应得的成绩：";
    cin >> grade;
    cout << "输入您的年龄：";
    cin >> age;
    cout << "姓名：" << first_name << "," << last_name << endl;
    cout << (char)(grade + 1) <<endl;
    cout << "年龄：" << age << endl;
    return 0;
}

