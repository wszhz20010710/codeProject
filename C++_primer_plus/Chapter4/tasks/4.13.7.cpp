#include <iostream>

using namespace std;
const int Arsize = 30;

struct pizza_info
{
    char name[Arsize];
    double diametre;
    double weight;
};

int main(){
    pizza_info piz;
    cout << "Please enter the name: " << endl;
    cin >> piz.name;
    cout << "Please enter the diametre: " << endl;
    cin >> piz.diametre;
    cout << "Please enter the weight: " << endl;
    cin >> piz.weight;

    // display the information
    cout << "Here are the information of pizza: " << endl;
    cout << "the name of pizza: " << piz.name << endl; 
    cout << "the diameter of pizza: " << piz.diametre << endl; 
    cout << "the weight of pizza: " << piz.weight << endl; 
    return 0;
}
