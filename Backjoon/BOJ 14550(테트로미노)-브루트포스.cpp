#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

typedef struct mov {
	int mx[3];
	int my[3];
}mov;

mov form[19] = {
				 {{0,0,0},{1,2,3}},
				 {{1,2,3},{0,0,0}},
				 {{0,1,1},{1,0,1}},
				 {{1,2,2},{0,0,1}},
				 {{1,0,0},{0,1,2}},
				 {{0,1,2},{1,1,1}},
				 {{0,0,-1},{1,2,2}},
				 {{0,-1,-2},{1,1,1}},
				 {{0,0,1},{1,2,2}},
				 {{1,2,0},{0,0,1}},
				 {{1,1,1},{0,1,2}},
				 {{1,1,2},{0,1,1}},
				 {{0,-1,-1},{1,1,2}},
				 {{0,1,1},{1,1,2}},
				 {{1,0,-1},{0,1,1}},
				 {{1,-1,0},{0,0,1}},
				 {{0,-1,1},{1,1,1}},
				 {{0,-1,0},{1,1,2}},
				 {{0,1,0},{1,1,2}}
};  //한 점에 대하여 19개의 모형대로 틀을 만듬

int main()
{
	//ifstream input("a.inp");
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M;
	int MAX = 0;
	cin >> N >> M;
	int **arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
	}// 이차원배열 동적할당
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	} //입력받고
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int cnt = arr[i][j];   //cnt초기값은 arr[i][j]의 위치
			for (int k = 0; k < 19; k++)
			{

				for (int l = 0; l < 3; l++)
				{
					int nx = i + form[k].mx[l];  
					int ny = j + form[k].my[l];  //원래위치에서 위에 배열에 맞춰 모양을 맞춰나감
					if (nx > N - 1 || nx<0 || ny>M - 1 || ny < 0)   //범위가 벗어나면
					{
						break; // break
					}
					cnt += arr[nx][ny];   // 범위내라면 cnt에 더해주고
				}
				if (cnt > MAX)
					MAX = cnt; //MAX값 비교
				cnt = arr[i][j];
			}
			//여기서 MAX값 비교
		}
	}
	cout << MAX << endl;
	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	//input.close();
	return 0;

}