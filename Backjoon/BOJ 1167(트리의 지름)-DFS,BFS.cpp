#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
vector < pair<int, int> > Edge[100001];
bool check[100001];
int N, MAX = 0;
int END;
//1. 맨처음은 모든 정점에서 DFS돌려서 MAX값을 갱신하려고 정점의 갯수가 최대 100000개라서 시간초과
//2. 가장 트리에 끝트머리쪽에 있는 정점을 하나 정해서 거기서 DFS돌리면 전체 지름을 알 수 있다.

void dfs(int s,int sum) {

	check[s] = true;
	if (sum > MAX)    //최댓값을 갱신해줄 위치
	{
		MAX = sum; //최댓값 갱신해주고
		END = s;    //가장 먼 위치가 될때까지 계속 위치 바꿔줌
	}
	for (int i = 0; i < Edge[s].size(); i++)
	{
		int Cur = Edge[s][i].first;
		int Cost = Edge[s][i].second;
		if (check[Cur] == false) //아직 들르지 않은곳이라면
		{
			dfs(Cur, sum + Cost);
		}
	}
	return;

}
int main()
{
	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N;      //노드의 갯수 입력
	int From, To, Cost;   // 시작 ,도착, 가중치 변수 선언
	for (int i = 1; i <= N; i++)
	{
	   	cin >> From;
 		for (int j = 0;; j=j+2)
		{
			cin >> To;
			if (To == -1)
				break;
			cin >> Cost;
			Edge[From].push_back(make_pair(To,Cost));
		}
	} //여기까지 연결리스트로 배열 만듬
	
	dfs(1, 0); //먼저 1번노드에서 DFS를 한번 돌린다
	fill(check, check + N + 1, false);
	MAX = 0;
	dfs(END, 0);   //가장 끄트머리에서 한번더 DFS돌려주면
	
	cout << MAX << endl; //MAX값 나온다.
	return 0;
}