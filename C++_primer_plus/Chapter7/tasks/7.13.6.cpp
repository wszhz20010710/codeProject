#include <iostream>

using namespace std;
const int ArSize = 10;

int Fill_array(double arr[], int length)
{
    int count = 0;
    while (count < length)
    {
        if (!(cin >> arr[count]))
        {
            count--;
        }
    count++;
    }
    return count;
}

void Show_array(double arr[], int length)
{
    for (size_t i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Reverse_array(double arr[], int length)
{
    int temp = 0;
    for (size_t i = 0; i < length/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
    
}

int main()
{
    double arr[5];
    Fill_array(arr, 5);
    Show_array(arr, 5);
    Reverse_array(arr, 5);
    Show_array(arr, 5);
    return 0;
}