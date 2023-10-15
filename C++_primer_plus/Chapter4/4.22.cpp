// 使用new和delete来存储通过键盘输入的字符串
#include <iostream>
#include <cstring>

using namespace std;
char * getname(void);// 先进行声明

int main(){
    char * name;

    name = getname();
    cout << name << " at " << (int *) name << "\n";
    delete [] name;// name是指向数组的指针，应该用[]释放

    name = getname();
    cout << name << " at " << (int *) name << "\n";
    delete [] name;
    
    return 0;
}

char * getname(void) 
{
    // 返回字符串指针
    char temp[80];
    cout << "Enter last name: ";
    cin >> temp;
    char * pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);

    return pn;
}