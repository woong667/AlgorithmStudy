#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef struct aa {
	int a;
	int idx; //전 인덱스
}aa;


aa dist[100001];
bool check[100001];
queue <int> q;

void kkk(int B)
{
	vector <int> kk;
	int k = B;
	while (dist[k].idx != -1)
	{
		kk.push_back(k);
		k = dist[k].idx;
	}
	for (int i = (int)kk.size()-1; i >= 0; i--)
	{
		cout << kk[i] << " ";
	}
	return;
}

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
	dist[n].a= 0;
	dist[n].idx = -1;
	q.push(n);
	int num;
	while (!q.empty())
	{
		num = q.front();
		if (num- 1 >= 0)
		{
			if (check[num- 1] == false) //아직 가보지않은곳이라면
			{
				check[num - 1] = true;
				dist[num - 1].a = dist[num].a + 1;
				dist[num - 1].idx = num; //전 인덱스의 번호를 넣는다.
				q.push(num - 1);
			}
		}
		if (num + 1 < 100001)
		{
			if (check[num + 1] == false)
			{
				check[num + 1] = true;
				dist[num + 1].a = dist[num].a + 1;
				dist[num + 1].idx = num;
				q.push(num + 1);
			}
		}
		if (num * 2 < 100001)
		{
			if (check[num * 2] == false)
			{
				check[num * 2] = true;
				dist[num * 2].a = dist[num].a + 1;
				dist[num * 2].idx = num;
				q.push(num * 2);
			}
		}
		q.pop();
	}
	cout << dist[B].a<<endl;
	cout << n << " ";
	kkk(B);
	return 0;
}