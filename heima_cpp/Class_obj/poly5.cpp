#include <iostream>
#include <string>
using namespace std;

// 虚析构和纯虚析构
class Animal
{
public:
    Animal()
    {
        cout << "Animal的构造函数的调用！" << endl;
    }

    // virtual ~Animal()
    // {
    //     cout << "Animal的虚析构函数的调用！" << endl;
    // }

    // 纯虚析构
    virtual ~Animal() = 0;
    // 纯虚函数
    virtual void speak() = 0;
};

Animal::~Animal()
{
    cout << "Animal的纯虚析构函数的调用！" << endl;
}

class Cat : public Animal
{
public:

    Cat(string name)
    {
        cout << "Cat的构造函数的调用！" << endl;
        m_Name = new string(name);
    }

    virtual void speak()
    {
        cout << "Cat " << *m_Name << " is speaking!" << endl;
    }

    ~Cat()
    {
        if (m_Name != NULL)
        {
            cout << "Cat的析构函数的调用！" << endl;
            delete m_Name;
            m_Name = NULL;
        }
        
    }
    string * m_Name;
};

void test01()
{
    Animal * ptr = new Cat("Tom");
    ptr->speak();
    // 父类的指针在析构时不会调用子类的析构函数
    // 导致子类若有堆区属性会导致内存泄漏
    delete ptr;
}


int main(){

    test01();


    system("pause");
    return 0;
}
