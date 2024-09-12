#include <iostream>
#include <string>
using namespace std;

// 多态案例2——制作饮品
// 流程为：煮水-冲泡-倒入杯中-加入辅料
class AbstractDrinking
{
public:
    virtual void ShowName() = 0;
    // 煮水
    virtual void Boil() = 0;
    // 冲泡
    virtual void Brew() = 0;
    // 倒入杯中
    virtual void PourInCup() = 0;
    // 辅料
    virtual void PutSomething() = 0;
    // 制作饮品
    void makeDrink()
    {
        ShowName();
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

// coffee
class Coffee : public AbstractDrinking
{
public:
    virtual void ShowName()
    {
        cout << "现在是煮咖啡时间！" << endl;
    }
    // 煮水
    virtual void Boil()
    {
        cout << "煮水！" << endl;
    }
    // 冲泡
    virtual void Brew()
    {
        cout << "冲泡咖啡！" << endl;
    }
    // 倒入杯中
    virtual void PourInCup()
    {
        cout << "倒入杯中！" << endl;
    }
    // 辅料
    virtual void PutSomething()
    {
        cout << "加入糖和牛奶！" << endl;
    }

};

// tea
class Tea : public AbstractDrinking
{
public:
    virtual void ShowName()
    {
        cout << "现在是煮茶时间！" << endl;
    }
    // 煮水
    virtual void Boil()
    {
        cout << "煮农夫山泉！" << endl;
    }
    // 冲泡
    virtual void Brew()
    {
        cout << "冲泡茶！" << endl;
    }
    // 倒入杯中
    virtual void PourInCup()
    {
        cout << "倒入杯中！" << endl;
    }
    // 辅料
    virtual void PutSomething()
    {
        cout << "加入枸杞和红枣！" << endl;
    }

};

// milk tea
class MilkTea : public AbstractDrinking
{
public:
    virtual void ShowName()
    {
        cout << "现在是煮奶茶时间！" << endl;
    }
    // 煮水
    virtual void Boil()
    {
        cout << "煮茶水！" << endl;
    }
    // 冲泡
    virtual void Brew()
    {
        cout << "牛奶加茶！" << endl;
    }
    // 倒入杯中
    virtual void PourInCup()
    {
        cout << "倒入杯中！" << endl;
    }
    // 辅料
    virtual void PutSomething()
    {
        cout << "加珍珠加芋泥加啵啵加红豆加芋圆加西米！" << endl;
    }

};

void doWork(AbstractDrinking * ptr)
{
    cout << "----------------------------------" << endl;
    ptr->makeDrink();
    cout << "----------------------------------" << endl;
    delete ptr;
    
}

void test01()
{
    doWork(new Coffee);
    doWork(new Tea);
    doWork(new MilkTea);

}

int main(){

    test01();


    system("pause");
    return 0;
}

