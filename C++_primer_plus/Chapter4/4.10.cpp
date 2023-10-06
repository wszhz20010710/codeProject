// 按行输入string对象
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    char charr[20];
    string str;

    cout << "Length of string in charr before input: "
         << strlen(charr) << endl;
    cout << "Length of string in str before input: "
         << str.size() << endl;
    
    cout << "Enter a line of text: \n";
    cin.getline(charr,20);
    // getline()是istream类的一个类方法
    // 第一个参数为目标数组，第二个参数为数组长度，可防止越界

    cout << "You entered: " << charr << endl;
    cout << "Enter another line of text: \n";
    getline(cin,str);
    // getline()不是类方法，指出去cin查找输入
    // 不必指出长度，string对象可以自动调整
    
    cout << "You entered: " << str << endl;
    cout << "Length of string in charr after input: "
        << strlen(charr) << endl;
    cout << "Length of string in str after input: "
        << str.size() << endl;

    return 0;
}