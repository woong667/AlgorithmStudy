#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[100001] = { 0, };
void init()
{

	int start = 1;
	int min = 1000;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 2; i <= 316; i++)
	{
		dp[i*i] = 1;
	}
	for (int i = 3; i < 100001; i++)
	{
		if (dp[i] == 0) {   //제곱수들 아닌애들.
			for (int j = start; j >= 1; j--)
			{
				if (min > 1 + dp[i - (j*j)])
					min = 1 + dp[i - (j*j)];
			}
			dp[i] = min;
			min = 1000;
		}
		else  //제곱수들 일때는 start를 하나 늘려준다.
		{
			start++;
		}
	}
}
int main()
{
	init();
	int N;
	cin >> N;
	cout << dp[N];
	return 0;
}