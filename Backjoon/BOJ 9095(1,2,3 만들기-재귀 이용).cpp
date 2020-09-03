#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dap = 0;
int go(int count, int sum, int goal)
{
	if (sum > goal) return 0;
	if (sum == goal) return 1;
	int now = 0;
	for (int i = 1; i <= 3; i++)
	{
		now += go(count + 1, sum + i, goal);  //1 , 2 , 3 을 돌릴때 각각에 대해 재귀돌려보리기
	}
	return now;
}
int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;
		cout << go(0, 0, n) << endl;
	}
}