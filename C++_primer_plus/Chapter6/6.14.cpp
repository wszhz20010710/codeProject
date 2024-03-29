// 允许错误内容的修正
#include <iostream>

using namespace std;
const int Max = 5;

int main()
{
    int golf[Max];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << Max << " rounds.\n";
    int i;
    for (i = 0; i < Max; i++)
    {
        cout << "round #" << i+1 << ": ";
        while (!(cin >> golf[i]))
        {
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "Please enter a number: ";
        }   
    }
    // average
    double total = 0.0;
    for (i = 0; i < Max; i++)
    {
        total += golf[i];
    }
    
    // show results
    cout << total / Max << " = average scores "
        << Max << " rounds\n";
        
    return 0;
}