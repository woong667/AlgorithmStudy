#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#define INF 100000000
using namespace std;
int arr[401][401];     //0으로 초기화 되어있다.
int N, E;

void set_arr(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
				arr[i][j] = INF;
		}
	}
	return;
}

int main()
{
	
             ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> E;
	set_arr(N);
	int s, e,test;

	for (int i = 1; i <= E; i++)
	{
		cin >> s >> e;
		arr[s][e] = 1;       //화살표로 연결이 되있는애들은 1로 바꿔준다.
		
	}
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (arr[i][k] == 1 && arr[k][j] == 1) //i가 k로 가고 k가 j로 갈수잇으면 i에서 j로도 가능
					arr[i][j] = 1;
			}
		}
	}
	cin >> test;
	while (test--)
	{
		cin >> s >> e;
		if (arr[s][e] == INF&&arr[e][s]==INF) //서로서로 닳을 수 없는곳일때
			cout <<"0\n";
		else if (arr[s][e]==1)
			cout << "-1\n";
		else
			cout << "1\n";
	}
	return 0;
}