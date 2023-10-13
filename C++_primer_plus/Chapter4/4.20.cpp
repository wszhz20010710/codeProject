// 指针和字符串

#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char animal[20] = "bear"; // animal中有元素bear
    const char* bird = "wren";// bird为wren的地址
    char* ps; // 指针没有指向，不能随意调用

    cout << animal << " and " << bird << "\n";

    cout << "Enter a kind of animal: ";
    cin >> animal;

    ps = animal;
    cout << ps << "!\n";
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl;
    cout << ps << " at " << (int *) ps << endl;

    ps = new char[strlen(animal) + 1];
    strcpy(ps, animal);

    cout << "After using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl; 
    cout << ps << " at " << (int *) ps << endl;
    delete [] ps;

    return 0;
}