// 结构体嵌套
#include <iostream>
#include <string>
#include <ctime>

using  namespace std;

struct Student
{
    string name;
    int score;
};

struct Teacher
{
    string name;
    struct Student sArr[5];
};

void allocate_value(struct Teacher tArr[], int len)
{
    string nameseed = "ABCDE";
    for (size_t i = 0; i < len; i++)
    {
        tArr[i].name = "Teacher_";
        tArr[i].name += nameseed[i];

        for (size_t j = 0; j < 5; j++)
        {
            tArr[i].sArr[j].name = "Student_";
            tArr[i].sArr[j].name += nameseed[j];
            tArr[i].sArr[j].score = rand() % 41 + 60;
        }
        
    }
    
}
void print_arr(struct Teacher tArr[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        cout << "老师姓名： "<< tArr[i].name << endl;
        for (size_t j = 0; j < 5; j++)
        {
            cout << "学生姓名： " << tArr[i].sArr[j].name << "   "
                 << "学生成绩： " << tArr[i].sArr[j].score << endl;
        }
        cout << endl;  
    }
    
}
int main()
{
    // random seed
    srand((unsigned int) time(NULL));
    
    struct Teacher tArr[3];
    int length = sizeof(tArr) / sizeof(tArr[0]);

    allocate_value(tArr, length);
    print_arr(tArr, length);

    return 0;

}