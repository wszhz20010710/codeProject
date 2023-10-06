#include <iostream>

using namespace std;

int main()
{
    cout << "请输入一个纬度，按照度、分、秒的格式输入。" << endl;
    cout << "度：";
    double degree;
    cin >> degree;
    cout << "分：";
    double minute;
    cin >> minute;
    cout << "秒：";
    double second;
    cin >> second;
    double total;
    total = degree + minute / 60 + second / 3600;
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << degree << " degrees, " << minute << " minutes, " 
    << second << " seconds = " << total << " degrees."; 
    return 0;

}