#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// vector存放内置数据类型
void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    // 创建vector数组
    vector<int> v;

    // 向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 通过迭代器访问容器中的数据
    // 起始迭代器 指向容器第一个元素
    vector<int>::iterator itBegin = v.begin(); 
    // 结束迭代器 指向容器中最后一个元素的下一个位置
    vector<int>::iterator itEnd = v.end();

    // 第一种遍历
    while (itBegin != itEnd)
    {
        cout << *itBegin << " ";
        itBegin++;
    }
    cout << endl;

    // 第二种遍历
    for (vector<int>::iterator it = v.begin(); it != itEnd; it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 第三种遍历
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    
    
}


int main()
{
    test01();

    system("pause");
    return 0;
}