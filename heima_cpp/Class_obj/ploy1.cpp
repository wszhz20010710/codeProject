#include <iostream>
#include <string>
using namespace std;

// 多态
// 动物类
class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal is speaking!" << endl;
    }
};

// 猫类
class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Cat is speaking!" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Dog is speaking!" << endl;
    }
};

// 静态多态的函数地址早绑定，在编译时确定函数地址
// 动态多态的函数地址晚绑定，在运行时确定函数地址
void DoSpeak(Animal &a) // Animal & a = cat;
{
    a.speak();
}

void test01()
{
    Cat cat;
    DoSpeak(cat);

    Dog dog;
    DoSpeak(dog);
}

int main(){

    test01(); // Animal is speaking!

    system("pause");
    return 0;
}