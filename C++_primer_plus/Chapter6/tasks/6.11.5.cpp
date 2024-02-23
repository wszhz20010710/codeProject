#include <iostream>

using namespace std;

int main(){
    cout << "输入你的收入 程序会计算你的所得税: ";
    double income;
    double tax;
    while (cin >> income)
    {
        if (income <= 5000)
            tax = 0;
        else if ((5000 < income)&&(income <= 15000))
            tax = (income - 5000) * 0.1;
        else if ((15000 < income)&&(income <= 35000))
            tax = 10000 * 0.1 + (income - 15000) * 0.15;
        else if (35000 < income)
            tax = 10000 * 0.1 + 20000 * 0.15 + (income - 35000) * 0.2;

        cout << "your income = " << income << endl;
        cout << "your tax = " << tax << endl;
        cout << "输入你的收入 程序会计算你的所得税: ";

    }
    return 0;
}