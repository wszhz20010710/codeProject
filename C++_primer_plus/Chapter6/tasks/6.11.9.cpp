#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
const int SIZE = 60;

struct people
{
    string name;
    double money;
};

int main()
{
    char filename[SIZE];
    ifstream inFile;

    cout << "Please enter the name of file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);

    // failed to open file
    if (!inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Programe terminating.\n";
        exit(EXIT_FAILURE);
    }

    int numDonators;
    inFile >> numDonators;
    people *p = new people[numDonators];
    for (int i = 0; i < numDonators; i++)
    {
        inFile.ignore();
        getline(inFile,p[i].name);
        inFile >> p[i].money;
    }

    cout << "重要捐款人如下: " << endl;
    for (int i = 0; i < numDonators; i++)
    {
        if (p[i].money >= 10000){
            cout << "姓名: " << p[i].name << " 捐款数目: " << p[i].money << endl;
        }
    }
    cout << "普通捐款人如下: " << endl;
    for (int i = 0; i < numDonators; i++)
    {
        if (p[i].money < 10000){
            cout << "姓名: " << p[i].name << " 捐款数目: " << p[i].money << endl;
        }
    }

    return 0;
}