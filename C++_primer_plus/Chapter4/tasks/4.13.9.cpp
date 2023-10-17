#include <iostream>
#include <string>

using namespace std;

struct CandyBar
{
    string brand;
    double weight;
    int calories;
};

int main(){

    CandyBar * ptr = new CandyBar[3];
    
    cout << "请输入第1个商品的品牌:";
    cin >> ptr[0].brand;
    cout << "请输入第1个商品的重量:";
    cin >> ptr[0].weight;
    cout << "请输入第1个商品的热量:";
    cin >> ptr[0].calories;
    cout << "请输入第2个商品的品牌:";
    cin >> ptr[1].brand;
    cout << "请输入第2个商品的重量:";
    cin >> ptr[1].weight;
    cout << "请输入第2个商品的热量:";
    cin >> ptr[1].calories;
    cout << "请输入第3个商品的品牌:";
    cin >> ptr[2].brand;
    cout << "请输入第3个商品的重量:";
    cin >> ptr[2].weight;
    cout << "请输入第3个商品的热量:";
    cin >> ptr[2].calories;
            
    cout << "\n下面显示已输入的商品信息:\n";

    for (size_t i = 0; i < 3; i++)
    {
        cout << "第" << i+1 << "个商品的品牌为" << ptr[i].brand << endl;
        cout << "第" << i+1 << "个商品的重量为" << ptr[i].weight << endl;
        cout << "第" << i+1 << "个商品的热量为" << ptr[i].calories << endl;
        cout << endl;
    }
    
    
    return 0;
}