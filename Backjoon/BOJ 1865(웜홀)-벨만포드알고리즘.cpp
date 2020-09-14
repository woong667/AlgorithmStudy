#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#define INF 1000000000
using namespace std;
vector <pair<int, pair<int, int> > > Edge;
vector <int> Dist(501);
int N, M, W;
bool flag = false;

//

void Belman_Ford()
{
	
		Dist[1] = 0;
		for (int j = 1; j <= N - 1; j++) //벨만포트는 정점의 갯수-1 만큼 돌아준다.
		{
			for (int k = 0; k < (int)Edge.size(); k++) {
				int From = Edge[k].first;
				int To = Edge[k].second.first;
				int Cost = Edge[k].second.second;

				//if (Dist[From] == INF) continue;  기존 벨만포드를 사용해 최단거리를 구할때는 연결되지 않은 애들을 신경쓰지 않기위해 뺴는데 이 문제는 연결되지 않은 곳에서 지들끼리 싸이클이 있다면 그것도 yes가 되니까 이부분을 빼준다
				if (Dist[From] + Cost < Dist[To])
				{
					Dist[To] = Dist[From] + Cost;
					if (j == N - 1)     //최대횟수까지 계속 값이 변하고 있다면 negative cycle이 있는거
					{ 
						flag = true;
						return;
					}
				}
			}
		} 
	
}


int main()
{
	ifstream input("a.inp");
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int Test;
	int S, E, T;    //시작위치, 도착위치, 걸리는 시간
	input >> Test;
	while (Test--)
	{
		input >> N >> M >> W;
		for (int i = 1; i <= N; i++)
		{
			Dist[i] = INF; //무한대 입력시켜주고.
		}
		for (int i = 1; i <= M; i++)
		{
			input >> S >> E >> T;
			Edge.push_back(make_pair(S, make_pair(E, T)));
			Edge.push_back(make_pair(E, make_pair(S, T)));
		}   //양방향으로 통하는 엣지를 위해. 양쪽으로 다 배열에 넣어줌
		for (int i = 1; i <= W; i++)
		{
			input >> S >> E >> T;
			Edge.push_back(make_pair(S, make_pair(E, -T)));  // 웜홀에는 음수를 대입
		}
		Belman_Ford();     //벨만포드 알고리즘 돌린다.
		if (flag == true)
		{
			cout << "YES\n";
			flag = false;
		}
		else
		{
			cout << "NO\n";
		}
		while (Edge.size() != 0)
		{
			Edge.pop_back();
		}
	}
	return 0;
}