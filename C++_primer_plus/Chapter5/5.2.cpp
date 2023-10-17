// 循环中的数字测试
#include <iostream>
using namespace std;

int main(){
    cout << "Enter the starting countdown value: ";
    int limit;
    cin >> limit;
    int i;
    for(i = limit; i; i--)
    // 第二个i作为条件是bool类型，i=0，返回False，循环终止
        cout << "i = " << i << "\n";
    cout << "Done now that i = " << i << "\n";

    return 0;
}