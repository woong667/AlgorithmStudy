#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	//ifstream input("a.inp");
	bool check[2000];
	int N, L;
	int s, e;
	cin >> N >> L;
	int *sub = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> sub[i];
		check[sub[i]] = true;
	}
	sort(sub, sub + N);
	s = sub[0];
	e = sub[N - 1];
	//시작점 끝점을 구해놓는다.
	int count = 0;    //테이프 갯수.
	for (int i = s; i <= e; i++)
	{
		if (check[i] == true) //구멍이난 곳이면
		{
			//테이프를 하나 쓰기 시작하고
		    for (int j = i; j < i + L; j++)
			{
				check[j] = false; // false로 돌려놓는다.
			}
			count++; // 테이프 갯수 올리고

		}
	}
	cout << count << endl;
//	input.close();
	return 0;
}