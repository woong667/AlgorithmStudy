#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int cnt= 0;
int N;
bool chess[16][16];


bool check(int i, int j)
{
	int h = i - 1;
	for (int k = 1; k <= h; k++)
	{
		if (chess[k][j])
			return false;
	}
	int x = i - 1;
	int y = j - 1;
	while (x >= 1 && y >= 1)
	{
		if (chess[x][y])
			return false;

		x -= 1;
		y -= 1;
	}
	x = i - 1;
	y = j + 1;
	while (x >= 1 && y <= N)
	{
		if (chess[x][y])
			return false;
		x -= 1;
		y += 1;
	}
	return true;
}

void go(int i, int j,int num)  //num은 현재까지 queen의 갯수.
{
	int h = i + 1;
	//탈출 지점 설정
	if (num == N)
	{
		cnt++;
		return;
	}
	if (h>N)
		return;
	if (num != i)
		return;
	for (int k=1; k <= N; k++) {
	   if (check(h, k)) {   //check했는데 문제없으면 그 부분 true로 만들고 다시 재귀
			chess[h][k] = true;
			go(h, k, num + 1); //퀸의 갯수도 1을 늘림.
			chess[h][k] = false;  //다시 false로 돌려놓음
		}
	}
}

int main()
{
	//ifstream input("a.inp");
	//ofstream output("a.out");
	cin >> N;
	for (int j = 1; j <= N; j++)
	{
			chess[1][j] = true;
			go(1, j,1); 
			chess[1][j] = false;
	}
	cout << cnt << endl;
	//input.close();
	//output.close();
	return 0;
}