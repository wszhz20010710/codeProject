// 使用new创建动态结构体
// 箭头运算符-> ：用于指向结构体的指针
#include <iostream>

using namespace std;
const int ArSize = 20;

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main(){
    inflatable * ps = new inflatable;
    cout << "Enter name of inflatable item: " ;
    cin.getline(ps->name,ArSize);
    cout << "Enter the volume of inflatable item: ";
    cin >> (*ps).volume;
    /* *ps就是被指向的结构体本身，(*ps).volume就是结构体的price成员*/
    cout << "Enter the price: $";
    cin >> ps->price;

    cout << "Name: " << (*ps).name << endl;
    // 使用箭头运算符对成员进行访问
    cout << "Volume: " << ps->volume << " cubic feet\n";
    cout << "Price: $" << ps->price << endl;
    delete ps;
    return 0;
}