#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the number of seconds: ";
    long total_seconds;
    cin >> total_seconds;
    int days,hours,miniutes,seconds;
    days = total_seconds / (24*3600);
    hours = (total_seconds - (days*24*3600)) / 3600;
    miniutes = (total_seconds - (days*24*3600) - hours *3600) / 60;
    seconds = total_seconds - (days*24*3600) - (hours *3600) - miniutes*60;
    
    cout << total_seconds << " seconds = " << days << " days, " <<
     hours << " hours, " << miniutes << " minutes, " << seconds
     << " seconds.";
     
    return 0;
}