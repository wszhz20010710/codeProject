// while loop
// while循环是没有初始化和更新部分的for循环
// 知道次数用for 知道循环结束条件用while
#include <iostream>
const int ArSize = 20;
int main(){
    using namespace std;
    char name[ArSize];
    cout << "Your first name, please: ";
    cin >> name;
    cout << "Here is your name, verticalized and ASCIIized:\n";
    int i = 0;
    while (name[i] != '\0') // 测试数组中的字符是否为空
    {
        cout << name[i] << ": " << int(name[i]) << endl;
        i ++;
    }
    

    return 0;
}