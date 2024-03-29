#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
const int SIZE = 60;

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

    char c;
    int charCount = 0;

    // read file to the end
    while (inFile.get(c))
    {
        charCount++;
    }
    
    cout << "文件中包含字符数为" << charCount << endl;
    inFile.close();

    return 0;
}