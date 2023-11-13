#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter the number of rows: ";
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        for(int j = 0; j < (4-i); j++)
        {
            cout << ".";
        }
        for(int k = 0; k < (i+1); k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
}