// 和c风格字符串的比较--strcmp()
#include <iostream>
#include <cstring>

int main(){
    using namespace std;
    char word[5] = "?ate";
    for (char ch = 'a'; strcmp(word, "mate"); ch++)
    {
        // 字符串和 mate不同测试就继续进行
        cout << word << endl;
        word[0] = ch;
    }
    cout << "After loop ends, word is " << word << endl;
    return 0;
}