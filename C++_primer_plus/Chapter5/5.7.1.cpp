// ++和--和指针
/*
    *pt *++pt ++*pt (*pt)++ *pt++
*/
#include <iostream>

int main()
{
    using namespace std;

    double arr[5] = {21.1,32.8,23.4,45.2,37.4};
    double* pt = arr;

    cout << "*pt = " << *pt << endl;// 指向第一个元素21.1
    cout << endl;

    cout << "*pt = " << *pt << endl;
    cout << "*++pt = " << *++pt << endl;// 前缀++先计算pt+1，再取(pt+1)指向的值
    cout << endl;

    cout << "*pt = " << *pt << endl;
    cout << "++*pt = " << ++*pt << endl;// 先取得pt指向的值，再+1
    cout << endl;

    cout << "*pt = " << *pt << endl;
    cout << "(*pt)++ = " << (*pt)++ << endl;// 括号内优先级高，先取pt指向的值再+1
    cout << endl;

    cout << "*pt = " << *pt << endl;
    cout << "*pt++ = " << *pt++ << endl;// 后缀运算符++优先级高，先取出pt指向的值，然后指针pt+1
    cout << endl;

    cout << "*pt = " << *pt << endl;// 此时pt指向第三个元素

    return 0;
}