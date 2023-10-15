// 指针和字符串

#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char animal[20] = "bear"; // animal中有元素bear
    const char* bird = "wren";// bird为wren的地址
    // brid指针声明为const，只能读不能改
    char* ps; // 指针没有指向，不能随意调用

    cout << animal << " and " << bird << "\n";

    cout << "Enter a kind of animal: ";
    cin >> animal;

    ps = animal;
    // ps和animal存放相同的地址
    cout << ps << "!\n";
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl;
    // (int *)强制类型转换，输出animal的地址 非char类型
    cout << ps << " at " << (int *) ps << endl;

    ps = new char[strlen(animal) + 1];
    // 要获得字符串副本，首先需要分配内存来存储字符串
    // 使用strlen确定字符串长度，+1来获得包含空字符时的字符串长度
    strcpy(ps, animal);
    // 将animal中的字符串复制到新分配的空间中
    // strcpy接受两个参数，第一个是目标地址，第二个是要复制字符串的地址

    cout << "After using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl; 
    cout << ps << " at " << (int *) ps << endl;
    delete [] ps;

    return 0;
}