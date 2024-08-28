#include <iostream>
#include <math.h>
using namespace std;

// 创建点类和圆类，判断点和圆位置关系
class Point
{
public:
    void set_point(double x, double y)
    {
        x_value = x;
        y_value = y;
    }

    double get_x()
    {
        return x_value;
    }

    double get_y()
    {
        return y_value;
    }
    void show_point()
    {
        cout << "(" << x_value << ", " << y_value << ")";
    }

private:
    double x_value;
    double y_value;
};

class Circle
{
public:
    void set_center(double x, double y)
    {
        center.set_point(x, y);
    }

    void set_radius(double r)
    {
        radius = r;
    }

    double cal_dis(Point &p1, Point &p2)
    {
        double dis = sqrt(pow(abs(p1.get_x()-p2.get_x()),2) + 
                        pow(abs(p1.get_y()-p2.get_y()),2));
        
        return dis;
    }

    void show_circle()
    {
        cout << "圆心为：";
        center.show_point();
        cout << "   半径为：" << radius << endl;
    }

    void judge_pos(Point &p3)
    {
        double dis = cal_dis(center, p3);
        if (dis > radius)
        {
            cout << "点在圆外" << endl;
        }
        else if (dis == radius)
        {
            cout << "点在圆上" << endl;
        }
        else
        {
            cout << "点在圆内" << endl;
        }
        
    }

private:
    Point center;
    double radius;
};

int main()
{
    Point p1;
    p1.set_point(0,-1);
    cout << "该点为：";
    p1.show_point();
    cout << endl;

    Circle c1;
    c1.set_center(3,4);
    c1.set_radius(5);
    c1.show_circle();
    c1.judge_pos(p1);
    
    system("pause");
    return 0;
}