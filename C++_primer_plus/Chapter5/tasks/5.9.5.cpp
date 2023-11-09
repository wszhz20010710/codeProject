#include <iostream>
#include <string>

using namespace std;

int main()
{
    string months[12] = 
    {"一","二","三","四","五","六","七","八","九","十","十一","十二"};
    int book_sale[12];
    int sum = 0;
    for (size_t i = 0; i < 12; i++)
    {
        cout << "请输入" << months[i] << "月的销量：";
        cin >> book_sale[i];
        sum += book_sale[i];
    }
    
    cout << "今年总销量为" << sum << "本书" << endl;
    return 0;
}