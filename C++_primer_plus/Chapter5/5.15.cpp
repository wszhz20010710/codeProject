// do-while 循环
// 先执行循环体，再判定测试表达式，在决定是否继续执行循环
#include <iostream>
using namespace std;

int main(){
    int n;
    
    cout << "Enter numbers in the range 1-10 to find ";
    cout << "my favourite number\n";
    do
    {
        cin >> n;
    } while (n != 7);
    cout << "Yes, 7 is my favourite number.\n" << endl;
    
    return 0;
}