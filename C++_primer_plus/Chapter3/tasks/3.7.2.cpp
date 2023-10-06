//calculate bmi
#include <iostream>

using namespace std;

const double k1 = 12;
const double k2 = 0.0254;
const double k3 = 2.2;

int main()
{
    double feet,inch,pound;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "请输入您的身高，按照几英尺几英寸的方式输入。" << endl;
    cout << "英尺：";
    cin >> feet;
    cout << "英寸：";
    cin >> inch;
    cout << "您的身高为 " << feet << " 英尺 " << inch << " 英寸" << endl;
    cout << "请输入您的体重，按照几磅方式输入。" << endl;
    cout << "体重：";
    cin >> pound;
    cout << "您的体重为" << pound << "磅。";
    cout << endl;
    double height_meter;
    height_meter = (feet * k1 + inch) * k2;
    double weight_kg;
    weight_kg = pound / k3;
    double bmi;
    bmi = weight_kg / (height_meter * height_meter);
    cout << "您的bmi指数是:" << bmi << endl;
    return 0;

}