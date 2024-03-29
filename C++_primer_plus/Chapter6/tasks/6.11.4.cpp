#include <iostream>

using namespace std;
const int StrSize = 20;

struct bop
{
    char fullname[StrSize];
    char title[StrSize];
    char bopname[StrSize];
    int preference;
    // 0-fullname 1-title 2-bopname
};

int main()
{
    bop people[5] = {
        {"Bob", "player", "B", 0},
        {"Jack", "boss", "J", 1},
        {"Steve", "worker", "S", 2},
        {"White", "engineer", "W", 1},
        {"Alex", "finder", "A", 0},
    };

    cout << "Benevolent Order of Programmers Report\n";
    cout << "a. display by name\tb. display by title\n";
    cout << "c. display by bopname\td. display by preference\n";
    cout << "q. quit\n";
            cout << "Enter your choice: ";
    while (true)
    {
        char ch;
        cin >> ch;
        if ((ch == 'a')||(ch == 'b')||(ch == 'c')||(ch == 'd')){
            switch (ch)
            {
            case 'a':{
                for (size_t i = 0; i < 5; i++)
                {
                    cout << people[i].fullname << endl;
                }
                break;
            }
            case 'b':{
                for (size_t i = 0; i < 5; i++)
                {
                    cout << people[i].title << endl;
                }
                break;
            }
            case 'c':{
                for (size_t i = 0; i < 5; i++)
                {
                    cout << people[i].bopname << endl;
                }
                break;
            }
            case 'd':{
                for (size_t i = 0; i < 5; i++)
                {
                    int pre;
                    pre = people[i].preference;
                    switch (pre)
                    {
                    case 0: {
                        cout << people[i].fullname << endl; 
                        break;
                    }
                    case 1:{
                        cout << people[i].title << endl;
                        break;
                    }
                    case 2:{
                        cout << people[i].bopname << endl;
                        break;
                    }
                    default:
                        break;
                    }
                }   
            }

            default:
                break;
            }
        }
        else if (ch == 'q'){
            cout << "Good Bye!" << endl;
            break;
        }
        else
            cout << "输入有误，请重新输入！" << endl;
        cout << "Next choice: ";
    }

    return 0;
}