#include <iostream>
#include <string> //using string class

using namespace std;

int main()
{
    string s1 = "penguin";
    string s2,s3;

    cout << "You can assign one string object to another: s2 = s1.\n";
    s2 = s1;
    // 可将一个string对象赋值给另一个string对象 s2=s1
    cout << "s1: " << s1 << ", s2: " << s2 << endl;
    cout << "You can assign a C-style string to a string object.\n";
    cout << "s2 = \"buzzard\"\n";
    s2 = "buzzard";
    // 可以使用c语言的风格来为string对象赋值
    cout << "s2: " << s2 << endl;
    cout << "You can concatenate strings: s3 = s1 + s2.\n";
    s3 = s1 + s2;
    // 可以使用+来拼接两个字符串
    cout << "s3: " << s3 << endl;
    cout << "You can append strings.\n";
    s1 += s2;
    // 可以使用+=来将后一个string附加到前一个string的末尾
    cout << "s1 += s2 yields s1 = " << s1 << endl;
    s2 += " for a day";
    cout << "s2 += \" for a day\" yields s2 = " << s2 << endl;
    // 可以使用+=在字符串末尾追加字符串常量
    return 0;
}