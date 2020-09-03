#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
	int max;
	int N;
	cin >> N;
	int arr[100001];
	int dp[100001];
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}  //arr에 값을 먼저 할당.
	dp[1] = arr[1];
	max = arr[1];
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] > dp[i - 1] + arr[i]) //그대로 둬야할떄
		{
			dp[i] = arr[i];
			if (dp[i] > max)
				max = dp[i];
		}
		else
		{
			dp[i] = arr[i] + dp[i - 1];
			if (dp[i] > max)
				max = dp[i];
		}
	}
	cout << max << endl;
	return 0;
}