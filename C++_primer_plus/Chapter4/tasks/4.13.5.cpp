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
    CandyBar snack = 
    {
        "Mocha Munch",
        2.3,
        350,
    };
    cout << "brand of snack: " << snack.brand << endl;
    cout << "weight of snack: " << snack.weight << endl;
    cout << "calories of snack: " << snack.calories <<endl;
    
    return 0;
}
