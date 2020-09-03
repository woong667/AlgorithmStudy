#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int N;
	int top = -1;
	cin >> N;
	vector <int> a(N); 
	int *dp = new int[N];
	for (int i = 0; i < N; i++)
	{
		dp[i] = 0;
		cin >> a[i];
	}
	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j]) //뒤에 있는게 더 작으면
			{
				if(dp[j]+1>dp[i])
				   dp[i] = dp[j] + 1;
			}
		}
		if (dp[i] == 0)
			dp[i] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		if (dp[i] > top)
			top = dp[i];
	}
	cout << top;
	delete[] dp;
	return 0;
}