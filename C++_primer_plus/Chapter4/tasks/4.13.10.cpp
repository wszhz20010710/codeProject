#include <iostream>
#include <array>
#include <bits/stdc++.h>

using namespace std;

int main(){
    array<double,3> grade;
    cout << "请输入三次40米跑成绩: " << endl;
    cin >> grade[0] >> grade[1] >> grade[2];
    double sum = grade[0]+grade[1]+grade[2];
    int times = sizeof(grade) / sizeof(double);
    cout << times << "次40米跑平均成绩为" 
         << fixed << setprecision(2) // 保留两位小数
         << sum/times << "秒" << endl;
    return 0;
}