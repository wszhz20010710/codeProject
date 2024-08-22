// 一维数组逆序输出
#include <iostream>

using namespace std;

int main()
{
    int N = 5;
    int arr[N] = {1,2,3,4,5};
	cout << "逆序前:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
 
    for (int i = 0; i < N/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[N-i-1];
        arr[N-i-1] = temp;
    }

    cout << "逆序后:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
    
	system("pause");
	return 0;

}