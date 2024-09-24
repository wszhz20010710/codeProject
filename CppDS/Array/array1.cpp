#include <iostream>
using namespace std;

// 数组基础
int arr[2][3] = {
    {0,1,2},
    {3,4,5}
};

void test01()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << &arr[i][j] << " ";
        }
        cout << endl;
    }
    
    
}

int main()
{
    test01();

    system("pause");
    return 0;
}