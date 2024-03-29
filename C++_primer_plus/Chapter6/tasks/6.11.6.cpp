#include <iostream>
#include <string>

using namespace std;

struct people
{
    string name;
    double money;
};

int main()
{
    int num;
    cout << "Enter number of people who donated money: ";
    cin >> num;
    people *p = new people[num];
    for (int i = 0; i < num; i++)
    {
        cout << "请输入第" << i+1 << "个人的姓名: ";
        cin >> p[i].name;
        cout << "请输入第" << i+1 << "个人的捐款金额: ";
        cin >> p[i].money;
    }
    cout << "重要捐款人如下: " << endl;
    for (int i = 0; i < num; i++)
    {
        if (p[i].money >= 10000){
            cout << "姓名: " << p[i].name << " 捐款数目: " << p[i].money << endl;
        }
    }
    cout << "普通捐款人如下: " << endl;
    for (int i = 0; i < num; i++)
    {
        if (p[i].money < 10000){
            cout << "姓名: " << p[i].name << " 捐款数目: " << p[i].money << endl;
        }
    }
    
    

    return 0;
}
