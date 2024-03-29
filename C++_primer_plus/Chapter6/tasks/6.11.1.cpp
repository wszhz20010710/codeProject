#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    cout << "Please enter text for analysis, and type @ to terminate input.\n";

    char ch;
    cin.get(ch);

    while (ch != '@')
    {
        if (isdigit(ch))
            ch++;
        else if (isupper(ch))
            cout << char(tolower(ch));
        else if (islower(ch))
            cout << char(toupper(ch));
        else
            cout << ch;
        cin.get(ch);
    }
    return 0;
    
}