// and 运算符
#include <iostream>

const int ArSize = 6;
using namespace std;

int main()
{
    float naaq[ArSize];
    cout << "Enter the NAAQs (New Age Awareness Quotients)  "
         << "of\nyour neighbours. Program terminates "
         << "when you make\n" << ArSize << " entries "
         << "or enter a negative value.\n";
    
    int i = 0;
    float temp;
    cout << "First value: ";
    cin >> temp;
    while (i < ArSize && temp >= 0)
    {
        naaq[i] = temp;
        ++i;
        if (i < ArSize)
        {
            cout << "Next Value: ";
            cin >> temp;
        }
        
    }
    if (i == 0)
    {
        cout << "No data--bye\n";
    }
    else
    {
        cout << "Enter your NAAQ: ";
        float you;
        cin >> you;
        int count = 0;
        for (int j = 0; j < i; j++)
        {
            if (naaq[j] > you)
                ++count;
        }
        cout << count;
        cout << " of your neighbours have greater awareness of\n"
             << "the New Age than you do.\n";
    }
    return 0;
}