#include <iostream>

using namespace std;

const int arsize = 10;

int input(double grade[]);
void show_grade(double grade[], int size);
double average(double grade[], int size);

int main()
{
    double grade[arsize];
    int size = input(grade);
    show_grade(grade, size);

    double avg = average(grade, size);
    cout << "the average of grades is " << avg << endl;

    return 0;
}

int input(double grade[])
{
    int i = 0;
    cout << "please input some grades: ";
    cin >> grade[i];
    while (cin.get() != '\n' && i < 9)
    {
        i++;
        cin >> grade[i];
    }

    return i+1;
    
}

void show_grade(double grade[], int size)
{
    cout << "the grades are as follows: ";
    for (int i = 0; i < size; i++)
    {
        cout << grade[i] << " ";
    }
    cout << endl;
}

double average(double grade[], int size)
{
    double sum = 0.0;
    double avg = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += grade[i];
    }
    avg = sum / size;
    return avg;
}

