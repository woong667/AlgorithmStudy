#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int arr[100][10];

void init()
{
	arr[1][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		arr[1][i] = 1;
	}
	for (int i = 2; i <= 100; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0 || j == 9)
			{
				if (j == 0)  // 뒷자리가 0일때
				{
					arr[i][j] = arr[i - 1][1]%1000000000;
			    } 
				else       //뒷자리가 9일때
				{
					arr[i][j] = arr[i - 1][8]%1000000000;
				}
			}
			else //뒷자리가 0과 9가 아닐때.
			{
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1])%1000000000;
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
		sum = (sum + arr[N][i]) % 1000000000;
	}
	cout << sum << endl;
	return 0;
}
