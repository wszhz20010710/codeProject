#include <iostream>
#include <string>

using namespace std;

double calculate(double x, double y, double (*ptr)(double, double))
{
    return (*ptr)(x, y);
}

double add(double x, double y)
{
    return x+y;
}

double sub(double x, double y)
{
    return x-y;
}

double mul(double x, double y)
{
    return x*y;
}

double div(double x, double y)
{
    return x/y;
}

int main()
{
    double x, y;
    double (*ptr[4])(double, double) = {add, sub, mul, div};
    string name[4] = {"add", "sub", "mul", "div"};
    string symbol[4] = {"+", "-", "*", "/"};
    cout << "输入非数字则退出：" << endl;
    while (cin >> x >> y)
    {
        for (size_t i = 0; i < 4; i++)
        {
            cout << name[i] << ": " << x << " "<< symbol[i] << " "
                 << y << " " << "=" << " "
                 << calculate(x, y, ptr[i]) 
                 << endl;

        }   
    }
    return 0;
}