#include <iostream>
#include <string>
using namespace std;

// 多态
// 动物类
class Animal
{
public:
    // 非静态函数和类分开存储，Animal是空类，size=1
    // 加上virtual后，类内多了个虚指针，8字节，size=8
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

void test02()
{
    cout << "size of Animal = " << sizeof(Animal) << endl;
}

int main(){

    test02(); // Animal is speaking!

    system("pause");
    return 0;
}