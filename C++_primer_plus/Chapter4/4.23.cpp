// 常用类型组合
#include <iostream>

using namespace std;

struct anitarctica_years_end
{
    int year;
};

int main(){
    anitarctica_years_end s01, s02, s03;
    s01.year = 1998;
    anitarctica_years_end * pa = &s02;
    pa->year = 1999;
    anitarctica_years_end trio[3];
    trio[0].year = 2003;
    cout << trio->year << endl;
    const anitarctica_years_end * arp[3] = {&s01, &s02, &s03};
    cout << arp[1]->year << endl;
    const anitarctica_years_end ** ppa = arp;
    auto ppb = arp;
    cout << (*ppa)->year << endl;
    cout << (*(ppb+1))->year << endl;
    
    return 0;
}