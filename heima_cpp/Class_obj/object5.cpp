#include <iostream>
using namespace std;

// 深拷贝和浅拷贝
class Person
{
public:
    Person() 
    {
        cout << "Person的默认构造函数调用" << endl;
    }
    
    Person(int age, int height)
    {
        cout << "Person有参构造函数的调用" << endl;
        m_age = age;
        m_height = new int(height);
    }

    // 自己实现拷贝构造函数来解决浅拷贝带来的问题
    Person(const Person &p)
    {
        cout << "Person拷贝构造函数的调用" << endl;
        m_age = p.m_age;
        // 编译器默认实现 m_height = p.m_height;
        m_height = new int(*p.m_height);
    }

    ~Person()
    {
        // 析构代码，将堆区开辟数据进行释放操作
        if (m_height != NULL)
        {
            delete m_height;
            m_height = NULL;
        }
        
        cout << "Person的析构函数调用" << endl;
    }

    int m_age;
    int *m_height;

};

void test01()
{
    Person p1(18, 160);
    cout << "p1的年龄为：" << p1.m_age << endl;
    cout << "p1的身高为：" << *p1.m_height << endl;

    Person p2(p1);
    cout << "p2的年龄为：" << p2.m_age << endl;
    cout << "p2的身高为：" << *p2.m_height << endl;
}

int main()
{
    test01();


    system("pause");
    return 0;
}