#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int arr[101][101];
long long int dp[101][101];

void go(int N) {

	int jump = arr[0][0]; //첫위치에서(0,0) 점프력
	if (jump >= N)      //하지만 배열사이즈를 넘어가버리는 점프력이면 RETURN
		return;
	dp[jump][0] = 1;    //0,0 에서 오른쪽만큼 점프력을 이용해 점프 DP배열에 +1 
	dp[0][jump] = 1;    //0,0 에서 아래쪽만큼 점프력을 이용해 점프 DP배열에 +1
	//일단 시작점은부터 바로 뛸수 있는애들은 1을 넣어줌
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			long long int jump = arr[i][j]; //FOR문으로 순회하면서 밟는곳의 점프력을 jump변수에 입력
			if (jump == 0||dp[i][j]==0)    //점프력이 0 이거나 dp가 0인곳은 어차피 도달할수 없는 위치=>  볼 필요 없이 건너 뛴다.
				continue; 
			if (i + jump < N) //밑으로 점프하는게 범위 이내라면
			{
				dp[i + jump][j] = dp[i+jump][j]+dp[i][j];   //아래로 점프해서 도착할 위치에 현재 위치의 dp를 더하기 
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
