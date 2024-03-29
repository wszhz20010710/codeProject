#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter one of the following choices:\n";
    cout << "a) carnivore   b)pianist\n";
    cout << "c) tree        d)game\n";

    char ch;
    cin >> ch;

    while (true)
    {
        if ((ch != 'a')&&(ch != 'b')&&(ch != 'c')&&(ch != 'd')){
            cout << "Please enter a,b,c,d to choose.\n";
            cin >> ch;
        }
        else
            break;
        
    }

    switch (ch)
    {
        case 'a': cout << "aaaaaa"; break;
        case 'b': cout << "bbbbbb"; break;
        case 'c': cout << "cccccc"; break;
        case 'd': cout << "dddddd"; break;
        break;
    
        default:
            break;
    }
    return 0;
}