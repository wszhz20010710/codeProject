// strings.cpp -- store strings in arrays
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const int Size = 15;
    char name1[Size];
    char name2[Size] = "SillyBoy";

    cout << "Howdy! I'm " << name2;
    cout << "! What's your name?\n";
    cin >> name1;
    cout << "Well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << " bytes.\n";
    cout << "Your initial is \'" << name1[0] << "\'.\n";
    cout << "How many characters of my name do you want to know?\n";
    int index;
    cin >> index;
    if (index >= strlen(name2))
        index = strlen(name2);
    name2[index] = '\0';
    cout << "Here are the first " << index << " characters of my name: ";
    cout << name2 << endl;

    return 0;
}