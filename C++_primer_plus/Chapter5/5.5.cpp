// 修改和更新步长
#include <iostream>

using namespace std;

int main(){
    cout << "Enter a integer: ";
    int footstep;
    cin >> footstep;
    cout << "Counting by " << footstep << "s:\n";
    for(int i = 0; i < 100; i += footstep)
        cout << i << endl;
        
    return 0;
}