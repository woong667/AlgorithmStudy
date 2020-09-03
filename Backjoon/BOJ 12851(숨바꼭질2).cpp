#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dist[100001];
bool check[100001];
int cnt[100001] = { 0, };
queue <int> q;
int main()
{
	int n, B;
	cin >> n >> B;
	if (n == 0 && B == 0)
	{
		cout << 0 << endl;
		cout << 0;
		return 0;
	}
	check[n] = true;
	dist[n] = 0;
	q.push(n);
	int num;
	cnt[n]= 1;
	while (!q.empty())
	{
		num = q.front();
		if (num - 1 >= 0)
		{
			
			if (check[num - 1] == false) //아직 가보지않은곳이라면
			{
				check[num - 1] = true;
				dist[num - 1]= dist[num]+ 1;
				q.push(num - 1);
				cnt[num - 1] = cnt[num];
			}
			else if (dist[num - 1] == dist[num] + 1) {
				cnt[num - 1] += cnt[num];
			}
		}
		if (num + 1 < 100001)
		{
			
			if (check[num + 1] == false)
			{
				check[num + 1] = true;
				dist[num + 1] = dist[num] + 1;
				q.push(num + 1);
				cnt[num + 1] = cnt[num];
			}
			else if (dist[num + 1] == dist[num] + 1) {
				cnt[num + 1] += cnt[num];
			}
		}
		if (num * 2 < 100001)
		{
		
			if (check[num * 2] == false)
			{
				check[num * 2] = true;
				dist[num * 2]= dist[num] + 1;
				q.push(num * 2);
				cnt[num * 2] = cnt[num];
			}
			else if (dist[num * 2] == dist[num] + 1) {
				cnt[num * 2] += cnt[num];
			}
		}
		q.pop();
	}
	cout << dist[B]<< endl;
	cout << cnt[B];
	return 0;
}