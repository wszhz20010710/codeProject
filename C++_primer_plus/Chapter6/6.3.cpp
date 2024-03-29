// if-else-if-else 结构
#include <iostream>

const int Fave = 27;
using namespace std;

int main()
{
    int n;
    cout << "Enter a number in the range 1-100 to find ";
    cout << "my favourite number: ";
    do
    {
        cin >> n;
        if (n < Fave)
            cout << "Too low -- guess again!";
        else if (n > Fave)
            cout << "Too high -- guess again!";
        else
            cout << "Bingo! " << Fave << " is my favourite number!";
    } while (n != Fave);
    
    
    return 0;
}