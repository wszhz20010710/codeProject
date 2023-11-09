#include <iostream>
#include <string>

using namespace std;

int main()
{
    string months[12] = 
    {"一","二","三","四","五","六","七","八","九","十","十一","十二"};
    int book_sale[3][12];
    int sum[4] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cout << "请输入第" << i+1 << "年第" << months[j] << "月的销量：";
            cin >> book_sale[i][j];
            sum[i] += book_sale[i][j];
        }
        sum[3] += sum[i];
    }
    for (size_t i = 0; i < 3; i++)
    {
        cout << "第" << i+1 << "年总销量为" << sum[i] << "本书" << endl;
    }
    cout << "三年总销量为" << sum[3] << "本书" << endl;
    return 0;
}