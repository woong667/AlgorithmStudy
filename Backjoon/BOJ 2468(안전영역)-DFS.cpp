#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;
int N;
int mx[4] = { 0,-1,0,1 };
int my[4] = { -1,0,1,0 };
int arr[101][101];
bool check[101][101];


void memory_reset()
{
	for (int i = 0; i < N; i++)
	{
		memset(check[i], false, sizeof(bool)*N);
	}
	return;
}

void dfs(int h,int x, int y)
{
	int nx;
	int ny;
	for (int i = 0; i < 4; i++)    //네 방향으로 이동해보기
	{
		nx = x + mx[i];
		ny = y + my[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N)  //범위를 벗어나면 continue
			continue;
		else
		{
			if (arr[nx][ny] > h&&check[nx][ny] == false)        //해당 위치가 잠기지않고 아직 안전지역에 포함되지않았으면
			{ 
				check[nx][ny] = true;   //안전지역으로 포함시키고
				dfs(h, nx, ny);     //다시 dfs
			}
		}
	}
}

int main()
{
	int MAX = -1;
	int MIN = 101;
	int cnt = 0;
	int ans = 0;
	//ifstream input("a.inp");
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > MAX)
				MAX = arr[i][j];     //가장 높은 높이 구하기.
			if (arr[i][j] < MIN)
				MIN = arr[i][j];     //가장 낮은 높이 구하기
		}
	}
	/////////////////////////////////////////////////////////////
	////////////////////////////DFS//////////////////////////////
	/////////////////////////////////////////////////////////////
	if (MIN == MAX)
	{
		cout << 1 << endl;
		return 0;
	}
	for (int i = MIN; i < MAX; i++)
	{
		for (int j = 0; j < N*N; j++)
		{
			int x = j / N;
			int y = j % N;
			if(check[x][y] ==false && arr[x][y]>i)
			{
				check[x][y] = true;
				dfs(i, x, y);
				cnt++;
			}
		}
		memory_reset();
		if (cnt > ans)
			ans = cnt;
		cnt = 0;
	}
	cout << ans << endl;
	//input.close();
	return 0;

}