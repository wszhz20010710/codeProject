// ==和=运算符
#include <iostream>

int main(){
    using namespace std;
    int quizscores[10] = 
        {20,20,20,20,20,20,20,19,18,20};
    cout << "Doing it right:\n";
    int i;
    for (i = 0; quizscores[i] == 20; i++)
        cout << "quiz " << i << "is a 20\n";
    
    // 危险动作
    cout << "Doing it dangerously wrong:\n";
    for (i = 0; quizscores[i] = 20; i++)
        cout << "quiz " << i << " is a 20\n";
        
    return 0;
}