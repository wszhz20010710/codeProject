#include <iostream>

using namespace std;
const double k = 0.0833;

int main()
{
    cout << "请输入您的身高(单位:英寸):______\b\b\b\b\b\b";
    double height;
    cin >> height;
    int feet = height * k;
    double inch = height - feet / k;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "您的身高为 " << feet << " 英尺 " << inch << " 英寸";
    return 0; 

}