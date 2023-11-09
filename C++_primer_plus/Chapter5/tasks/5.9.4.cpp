#include <iostream>

using namespace std;
 
int main()
{
    double money_Daphne = 100.0;
    double money_Cleo = 100.0;
    int year = 0;
    while (money_Daphne >= money_Cleo)
    {
        money_Daphne += 10;
        money_Cleo *= 1.05;
        year++;
    }
    cout << "Daphne's money is "<< money_Daphne << endl;
    cout << "Cleo's money is "<< money_Cleo << endl;
    
    return 0;
}