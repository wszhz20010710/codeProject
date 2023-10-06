// c++中的结构体
#include <iostream>

using namespace std;
struct inflatable 
// 结构体放在main()函数前面，外部变量，全局都可使用
// 尽量使用局部变量、外部结构体
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    inflatable guest = 
    {
        "Glorious Gloria", // name
        1.88,              // volume
        29.99              // price
    };
    
    inflatable pal = 
    {
        "Audacious Arthur",
        3.12,
        32.99
    };

    cout << "Expand your guest list with " << guest.name;
    cout << " and " << pal.name << "!\n";

    cout << guest.name << "'s volume is " << guest.volume << endl;
    cout << pal.name << "'s volume is " << pal.volume << endl;


    cout << "You can have both for $";
    cout << guest.price + pal.price << "!\n";
    return 0;
}