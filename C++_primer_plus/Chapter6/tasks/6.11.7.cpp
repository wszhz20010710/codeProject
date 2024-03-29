#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
    char word[20];
    int num_y = 0;  //元音
    int num_f = 0;  //辅音
    int other = 0;
    cin >> word;
    while (strcmp(word, "q")) {
        if (isalpha(word[0])) {
            switch (word[0]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                num_y++;
                break;
            default:
                num_f++;
                break;
            }
        }
        else {
            other++;
        }
        cin >> word;
    }
    cout << "元音打头的有" << num_y << "个" << endl;
    cout << "辅音打头的有" << num_f << "个" << endl;
    cout << "其他打头的有" << other << "个" << endl;
    return 0;
}

