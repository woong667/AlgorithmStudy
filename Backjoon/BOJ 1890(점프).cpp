#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int arr[101][101];
long long int dp[101][101];

void go(int N) {

	int jump = arr[0][0]; //첫 점프숫자 넣어주기
	if (jump >= N)
		return;
	dp[jump][0] = 1;
	dp[0][jump] = 1;
	//일단 시작점은부터 바로 뛸수 있는애들은 1을 넣어줌
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			long long int jump = arr[i][j];
			if (jump == 0||dp[i][j]==0)   //점프할 수 없는 위치거나 dp가 0인곳은 볼 필요 없이 건너 뛴다.
				continue; 
			if (i + jump < N) //밑으로 점프하는게 범위 이내라면
			{
				dp[i + jump][j] = dp[i+jump][j]+dp[i][j];
			}
			if (j + jump < N) //오른쪽으로 점프하는게 범위 이내라면
			{
				dp[i][j + jump] = dp[i][j+jump]+dp[i][j];
			}
		}
	}
}

int main()
{
	//ifstream input("a.inp");
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	go(N);
	cout << dp[N - 1][N - 1];
	//input.close();
	return 0;
}