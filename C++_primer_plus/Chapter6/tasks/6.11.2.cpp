#include <iostream>

using namespace std;
const int Max = 10;

int main()
{
    double Donation[Max];
    cout << "Please enter some numbers.\n";
    int i;
    int bigger = 0;
    int lower = 0;
    double mean = 0.0;
    double sum = 0.0;
    for (i = 0; i < Max; i++)
    {
        cout << "round #" << i+1 << ":";
        if (!(cin >> Donation[i]))
            break;
        else
            sum += Donation[i];
        
    }
    mean = sum / i;
    int j=0;
    for (j = 0; j<i; j++)
    {
        if (Donation[j] > mean)
            ++bigger; 
        if (Donation[j] < mean)
            ++lower; 
    }

    cout << "sum = " << sum << endl;
    cout << "average = " << mean << endl;
    cout << "bigger than mean = " << bigger << endl;
    cout << "lower than mean = " << lower << endl;

    return 0;
    
    
}