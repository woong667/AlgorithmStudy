#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
int mx[4] = { 0,-1,0,1};
int my[4] = {-1,0,1,0};
int N,M;
int arr[1001][1001];
int sub_arr[1001][1001];
bool check[1001][1001];
int pop_cnt;
queue <pair<int,int> > q;
 
void bfs(int x,int y)
{
	int nx,ny;
	for (int i = 0; i < 4; i++)
	{
		nx = x + mx[i];
		ny = y + my[i];
		if (nx >= N || nx < 0 || ny >= M || ny < 0) //범위를 벗어나면 
		{
			continue;
		}
		if (check[nx][ny] != true&&arr[nx][ny]==1) {
			sub_arr[nx][ny] = sub_arr[x][y] + 1;
			q.push(make_pair(nx, ny));
			check[nx][ny] = true;
		}
	}
}
int main()
{
	//ifstream input("a.inp");
	cin >> N >> M;
	int x, y;
	for (int i=0;i<N;i++ )
	{
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				x = i; y = j;
			} //위치를 입력받고
			if (arr[i][j] == 0)
			{
				sub_arr[i][j] = 0;
			}
			else
				sub_arr[i][j] = -1;
		}
	}
	check[x][y] = true;
	sub_arr[x][y] = 0;
	q.push(make_pair(x,y));  //
	while (!q.empty()) //큐가 다 비어질때까지
	{
		 x = q.front().first;
		 y = q.front().second;
		q.pop();
		bfs(x,y);
		
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << sub_arr[i][j] << " ";
		}
		cout << endl;
	}
	//input.close();
	return 0;
}