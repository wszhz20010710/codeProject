#include <iostream>
#include <string>
using namespace std;

// 函数模板案例
// 利用选择排序从大到小排列数组
template<typename T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int max_index = i;
        for (int j = i+1; j < len; j++)
        {
            if (arr[j] > arr[max_index])
            {
                max_index = j;
            }
        }
        if (max_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[max_index];
            arr[max_index] = temp;
        }

    }
    
}

void test01()
{
    char arr1[] = "bsdkfja";
    int len = sizeof(arr1) / sizeof(char);
    mySort(arr1, len);
    for (int i = 0; i < len; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
}

void test02()
{
    int arr2[] = {1,2,7,5,9,4,8,3,6};
    int len = sizeof(arr2) / sizeof(int);
    mySort(arr2, len);
    for (int i = 0; i < len; i++)
    {
       cout << arr2[i] << " ";
    }
    

}

int main(){

    test01();
    test02();
    system("pause");
    return 0;
}