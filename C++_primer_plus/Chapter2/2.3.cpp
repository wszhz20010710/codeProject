#include <iostream>
#include <stdio.h>
using namespace std;


int main(void)
{
    int apple;
    cout << "how many apples do you have now?" << endl;
    cin >> apple;
    cout << "here are two more" << endl;
    apple += 2;
    cout << "now you have " << apple << " apples" << endl;
    return 0;

}