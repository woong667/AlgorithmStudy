#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, U, V, P, S, E;
queue <pair <int, int> > pq;
vector <pair<int,int> > v[1001];

int dist[1001];


void dijkstra(int src)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;  //이게 우선순위큐 선언식
	pq.push(make_pair(src,0));   //현재위치의 cost랑 
	while (!pq.empty())
	{
		int now = pq.top().first;
		int distance = pq.top().second; //작은 값이 최상단에 오도록
		pq.pop();
		if (dist[now] < distance) 
			continue;    //최단거리 아닌경우 continue;
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i].first;
			int nextDistance = dist[now] + v[now][i].second;
			if (dist[next] > nextDistance)
			{
				dist[next] = nextDistance;
				pq.push(make_pair(next, dist[next]));
			}
		}
	}
}

int main()
{
	//ifstream input("a.inp");
	cin >> N;
	cin >> M;
	for (int i = 0; i <= N; i++)
	{
		dist[i] = 100000000;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> U >> V >> P;
		v[U].push_back(make_pair(V, P));
	}
	cin >> S >> E;
	dist[S] = 0;
	dijkstra(S);
	cout << dist[E] << endl;
	//input.close();
	return 0;
}