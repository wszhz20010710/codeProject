// 对C风格字符串，可以调用cstring库来进行操作
// 与string类方法进行对比
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    char charr1[20];
    char charr2[20] = "jaguar";
    string str1; 
    string str2 = "panther";

    // 字符串的复制操作
    str1 = str2;
    strcpy(charr1,charr2);
    cout << "str1: " << str1 << " " << " charr1: " << charr1 << endl;

    // 字符串的末尾添加元素（追加操作）
    str1 += " paste";
    strcat(charr1, " juice");
    cout << "str1: " << str1 << " " << " charr1: " << charr1 << endl;

    // 返回字符串长度
    int len1 = str1.size();
    int len2 = strlen(charr1);

    cout << "The string " << str1 << " contains "
         << len1 << " characters." << endl;
    cout << "The string " << charr1 << " contains "
         << len2 << " characters." << endl;

    return 0;
}