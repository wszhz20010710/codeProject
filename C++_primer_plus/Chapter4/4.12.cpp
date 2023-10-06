// 结构体可以使用string类作为成员
// 一定要让结构体可以访问名称空间std

#include <iostream>
#include <string>

using namespace std;

struct identity
{
    string name;
    int age;
    bool gender;
    string address;
    double height;
    double weight;
    string phone_number;
};

int main()
{
    identity zhz =
    {
        "周昊哲",
        22,
        0,
        "电子科技大学清水河校区",
        182,
        85,
        "1145141919810",
    };
    cout << zhz.name << endl;
    cout << zhz.age << endl;
    cout << zhz.gender << endl;
    cout << zhz.height << endl;
    cout << zhz.weight << endl;
    cout << zhz.address << endl;
    cout << zhz.phone_number << endl;
    return 0;
}