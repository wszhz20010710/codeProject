// 递归
#include <iostream>

using namespace std;
void countdown(int n);

int main()
{
    cout << "Please input an integer: ";
    int n;
    cin >> n;
    countdown(n);
    return 0;
}

void countdown(int n)
{
    cout << "Counting down ... " << n << endl;
    if (n > 0)
    {
        countdown(n-1);
    }
    cout << n << ": Kaboom!\n";
    
}