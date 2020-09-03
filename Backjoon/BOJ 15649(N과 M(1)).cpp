#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool c[10];
int a[10];
void go(int index, int n, int m)
{
	if (index == m)
	{
		//수열을 출력
		for (int i = 0; i<m; i++)
		{
			cout << a[i]<<" ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (c[i]) continue;   //중복이면 건너뛰어라
		c[i] = true; a[index] = i;
		go(index + 1, n, m);
		c[i] = false;
	}
}
int main()
{
	int N, M;
	cin >> N >> M;
	go(0, N, M);
	return 0;
}