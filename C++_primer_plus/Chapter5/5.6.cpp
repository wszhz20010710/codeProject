// 利用for循环来访问字符串
#include <iostream>
#include <string>

int main(){
    using namespace std;

    cout << "Enter a word: ";
    string word;
    cin >> word;

    // 实现倒序输出字符串
    for (int i = word.size() - 1; i >= 0; i--)
        cout << word[i];
    cout << "\nBye.\n";
    return 0;
}