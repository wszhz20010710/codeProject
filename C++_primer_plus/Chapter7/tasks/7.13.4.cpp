#include <iostream>

using namespace std;

/*
从域号码中选择几个
从特选号码中选择1个
中头奖的概率为
域号码中正确选取的几率
与
特选号码中正确选取的几率
的乘积
计算中头奖的概率
*/

long double probability01(unsigned numbers01, unsigned picks);

int main()
{
    double total01, choices, total02;
    cout << "分别输入域号码总数、需要选的个数和特选号码总数：\n";
    while ((cin >> total01 >> choices >> total02) && choices <= total01) {
        cout << "获得头奖的概率：";
        cout << probability01(total01, choices) * total02 << endl;
        cout << "继续输入，输入q退出：";
    }
    cout << "bye\n";
    return 0;
}

long double probability01(unsigned numbers01, unsigned picks) {
    long double result = 1.0;
    long double n;
    unsigned p;
    for (n = numbers01, p = picks; p > 0; n--, p--) {
        result = result * n / p;
    }
    return result;
}

