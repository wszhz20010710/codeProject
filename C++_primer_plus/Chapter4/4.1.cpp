// arrayone.cpp --arrays of integers
#include <iostream>

using namespace std;

int main()
{
    int yams[3];
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 9;

    int yamcosts[3] = {20,30,5};
    cout << "Total yams = " << yams[0]+yams[1]+yams[2] << endl;
    cout << "Total costs = " << yams[0]*yamcosts[0]+yams[1]*yamcosts[1]+yams[2]*yamcosts[2] << endl;
    cout << "Size of yams array = " << sizeof yams << " bytes." << endl;
    cout << "Size of one element = " << sizeof yams[0] << " bytes." << endl; 
    return 0;
}