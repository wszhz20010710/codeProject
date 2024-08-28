#include <iostream>
using namespace std;

// 定义立方体类
// 求出立方体的面积和体积
// 判断两个立方体是否相等

class Cube
{
public:
    void set_arug(int length, int width, int height)
    {
        if (length < 0 || width < 0 || height < 0)
        {
            cout << "wrong input!" << endl;
            return;
        }
        m_length = length;
        m_width = width;
        m_height = height;
    }

    void cal_area()
    {
        m_area = 2*(m_height*m_length+m_height*m_width+m_length*m_width);
    }

    void cal_vol()
    {
        m_volume = m_length*m_height*m_width;
    }

    void show_cube()
    {
        cout << "length = " << m_length << endl;
        cout << "width = " << m_width << endl;
        cout << "height = " << m_height << endl;
        cout << "area = " << m_area << endl;
        cout << "volume = " << m_volume << endl;
        cout << endl;
    }

    int get_L()
    {
        return m_length;
    }

    int get_W()
    {
        return m_width;
    }
    
    int get_H()
    {
        return m_height;
    }

    void isSame_class(Cube &c)
    {
        if (m_length == c.get_L() &&
            m_width == c.get_W() &&
            m_height == c.get_H())
        {
            cout << "两个立方体相同！" << endl;

        }
        else
        {
            cout << "两个立方体不同！" << endl;

        }
    }
private:
    int m_length;
    int m_width;
    int m_height;
    int m_area = 2*(m_height*m_length+m_height*m_width+m_length*m_width);
    int m_volume = m_length*m_height*m_width;
};

bool is_Same(Cube &c1, Cube &c2)
{
    if (c1.get_L() == c2.get_L() && 
        c1.get_W() == c2.get_W() && 
        c1.get_H() == c2.get_H())
    {
        return true;
    }
    return false;
    
}




int main()
{
    Cube c1;
    Cube c2;
    c1.set_arug(3,4,5);
    c1.cal_area();
    c1.cal_vol();
    c2.set_arug(3,4,5);
    c2.cal_area();
    c2.cal_vol();

    c1.show_cube();
    c2.show_cube();

    bool ret = is_Same(c1,c2);
    if (ret)
    {
        cout << "same!" << endl;
    }
    else
    {
        cout << "different!" << endl;
    }

    c1.isSame_class(c2);

    system("pause");
    return 0;
}