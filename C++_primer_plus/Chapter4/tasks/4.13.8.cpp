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
    pizza_info * ptr = new pizza_info;
    cout << "Please enter the name: " << endl;
    cin >> ptr->name;
    cout << "Please enter the diametre: " << endl;
    cin >> ptr->diametre;
    cout << "Please enter the weight: " << endl;
    cin >> ptr->weight;

    // display the information
    cout << "Here are the information of pizza: " << endl;
    cout << "the name of pizza: " << ptr->name << endl; 
    cout << "the diameter of pizza: " << ptr->diametre << endl; 
    cout << "the weight of pizza: " << ptr->weight << endl; 
    
    return 0;

}