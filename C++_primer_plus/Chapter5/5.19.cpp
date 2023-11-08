// 改进5.18 采用cin.get()方法
#include <iostream>

using namespace std;

int main()
{
    int ch;
    int count = 0;

    while ((cin.get())!=EOF)
    {
        cout.put(char(ch));
        ++count;
    }
    cout << endl << count << " characters read\n";
    return 0;
}