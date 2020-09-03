#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int arr[1001][10] = { 0, };

void init()
{

	for (int i = 0; i < 10; i++)
	{
		arr[1][i] = 1;
	}
	for (int i = 2; i < 1001; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k >= 0; k--)
			{
				arr[i][j] =(arr[i][j]+ arr[i - 1][j - k])%10007;
			}
		}
	}
}
int main() {
	
	init();
	int N;
	long long int sum = 0;
	cin >> N;
	for (int i = 0; i < 10; i++)
	{
		sum = (sum + arr[N][i]) % 10007;
	}
	cout << sum<< endl;
	return 0;
}
