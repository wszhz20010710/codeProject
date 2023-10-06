#include <iostream>
#include <string>

using namespace std;

int main()
{
    char charr1[20];
    char charr2[20] = "jaguar";
    // char 数组是一组用于存储字符串的char存储单元
    // string 类变量是一个表示字符串的实体
    // 使用string类更方便、更安全
    string str1; //创建长度为 0 的字符串对象，长度根据后续自动调整
    string str2 = "panther";

    cout << "Enter a kind of feline: ";
    cin >> charr1;
    cout << "Enter another kind of feline: ";
    cin >> str1;
    cout << "Here are some felines:\n";
    cout << charr1 << " " << charr2 << " "
         << str1 << " " << str2 << endl;
    cout << "The third letter in " << charr2 << " is "
         << charr2[2] << endl;
    cout << "The third letter in " << str2 << " is "
         << str2[2] << endl;
        
    
    return 0;
}