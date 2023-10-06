// 结构体数组：本质是数组，每个元素都是结构体

#include <iostream>
#include <string>
#include <array>

using namespace std;

struct identity
{
    string name;
    int age;
    double height;
};

int main()
{
    identity friends[3] = 
    {
        {"ZhouHaozhe", 22, 1.82},
        {"ZhongRui", 23, 1.85},
        {"ShuTaotao", 22, 176},
    };

    for (size_t i = 0; i < 3; i++)
    {
       cout << friends[i].name << " is " << friends[i].age << " years old and "
        << friends[i].height << " meters tall." << endl; 
    }
    
    
    return 0;
}