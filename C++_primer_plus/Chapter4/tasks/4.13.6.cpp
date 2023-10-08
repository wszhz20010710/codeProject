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
    CandyBar snack[3] = 
    {
        {"chips", 123.4, 514},
        {"chicken", 456.7, 789},
        {"biscuit", 345.6, 678},
    };
    for (size_t i = 0; i < 3; i++)
    {
        cout << "Brand of NO." << i+1 << " snack is " << snack[i].brand << endl;
        cout << "Weight of NO." << i+1 << " snack is " << snack[i].weight << endl;
        cout << "Calories of NO." << i+1 << " snack is " << snack[i].calories << endl;
        cout << endl;
    }
    
    return 0;
}