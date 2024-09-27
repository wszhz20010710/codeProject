STL初识
***
2.1 STL的诞生

软件界想建立的一套数据结构和算法的标准化模板以提高复用性

***
***
2.2 STL的基本概念

中文名：标准模板库
分类：容器container、算法algorithm、迭代器iterator
关系：容器和算法通过迭代器进行无缝连接
特点：STL几乎所有的代码都采用了模板类或模板函数
***
***
2.3 STL的六大件

容器、算法、迭代器、仿函数、适配器、空间配置器
***
***
2.4 容器、算法、迭代器

容器：运用常用数据结构实现出来

分类：序列式、关联式
***
***
2.5 容器算法迭代器初识
***
2.5.1 vector存放内置数据类型

创建vector数组

    vector<int> v;

向容器中插入数据

    v.push_back(10);

起始迭代器 指向容器第一个元素

    vector<int>::iterator itBegin = v.begin(); 
结束迭代器 指向容器中最后一个元素的下一个位置

    vector<int>::iterator itEnd = v.end();
第三种遍历

    for_each(v.begin(), v.end(), myPrint);
***
2.5.2 vector存放自定义数据类型

遍历法输出存放的数据
***
2.5.3 vector容器嵌套容器

学习容器嵌套容器
***
***
3 STL常用容器
***
3.1 string容器
3.1.1 string基本概念

string是cpp风格的字符串，本质上是一个类

string内部封装了char*，是个char*型的容器
char*是一个指针，是c风格的字符串

特点：
string内部封装了很多成员方法
例如：查找find、拷贝copy、删除delete……
***
3.1.2 string的构造函数

string();
string(const char* s);
string(const string& str);
string(int n, char c);
***
3.1.2 string的赋值操作

=赋值
assign赋值
***
3.1.3 string的拼接操作

+=拼接
append拼接
***
3.1.4 3.1.5 string的查找和替换

find、rfind查找
find从左往右 rfind从右往左
replace 替换
***
3.1.6 string对比

使用compare函数
比较ASCII码，
= 返回0        > 返回1       < 返回-1