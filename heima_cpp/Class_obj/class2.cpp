#include <iostream>
#include <string>
using namespace std;

// 设计一个学生类
class Student
{
public:
    string name;
    string number;

    void show_data()
    {
        cout << "学生姓名为：" << name << endl;
        cout << "学生学号为：" << number << endl;
    }

    void input_data(string in_name, string in_num)
    {
        name = in_name;
        number = in_num;
    }

};

int main()
{
    Student stu1;
    stu1.name = "zhz";
    stu1.number = "202322070339";
    stu1.show_data();

    Student stu2;
    stu2.name = "zr";
    stu2.number = "202322070319";
    stu2.show_data();

    Student stu3;
    stu3.input_data("cjh", "114514");
    stu3.show_data();

    system("pause");
    return 0;
}