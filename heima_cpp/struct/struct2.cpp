// struct bubble sort
#include <iostream>
#include <string>

using namespace std;

struct Hero
{
    string name;
    int age;
    string gender;
};

void struct_bubble_sort(struct Hero arr[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len-i-1; j++)
        {
            struct Hero Temp;
            if (arr[j].age > arr[j+1].age)
            {
                Temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = Temp;
            }
        }  
    } 
}

void print_struct(struct Hero arr[], int length)
{
    for (size_t i = 0; i < length; i++)
    {
        cout << arr[i].name << " " << arr[i].age << " " << arr[i].gender << endl;
    }
    cout << endl;
}
int main()
{
    struct Hero SanGuo[5] = 
    {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"},
    };
    int length = sizeof(SanGuo) / sizeof(SanGuo[0]);

    cout << "排序前：" << endl;
    print_struct(SanGuo, length);

    struct_bubble_sort(SanGuo, length);

    cout << "排序后：" << endl;
    print_struct(SanGuo, length);

    return 0;
}