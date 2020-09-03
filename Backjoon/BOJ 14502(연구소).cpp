#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int N,M;
int MAX = -1;
vector <pair <int, int> > v;
int copy_arr[8][8] = { -1, };
int mx[4] = { 0,-1,0,1 };
int my[4] = { -1,0,1,0 };  //좌->상->우->하

void copy_floor(int **arr)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			copy_arr[i][j] = arr[i][j];
		}
	}
}

void dfs(int x,int y){
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + mx[i];
		int ny = y + my[i];
		if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) {    //범위가 넘어가면
			continue;	
		}
		if (copy_arr[nx][ny] == 0)
		{
			copy_arr[nx][ny] = 2;
			dfs(nx, ny);
		}
		else
			continue;
	}
	return;
}

int main() {

	//ifstream input("a.inp");
	cin >> N >> M;
	int **arr = new int*[N];
    
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
	} //동적할당 완료.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				v.push_back(make_pair(i, j));     //바이러스의 위치 저장.
		}
	} //입력을 받고.
	for (int i = 0; i < N*M; i++)
	{
		if (arr[i / M][i%M] == 0)
		{
			for (int j = i + 1; j < N*M; j++)
			{
				if (arr[j / M][j%M] == 0) {
					for (int k = j + 1; k < N*M; k++)
					{
						if (arr[k / M][k%M] == 0)
						{
							copy_floor(arr);
							copy_arr[i / M][i%M] = 1;
							copy_arr[j / M][j%M] = 1;
							copy_arr[k / M][k%M] = 1; //해당위치에 벽을 세우고.
							for (int l = 0; l < (int)(v.size()); l++)
							{
								dfs(v[l].first,v[l].second);
							}//바이러스 전부옮은 상황....
							int cnt = 0;
							for (int z = 0; z < N; z++)
							{
								for (int x = 0; x < M; x++)
								{
									if (copy_arr[z][x] == 0)
										cnt++;
								}
							}
							if (cnt > MAX)
								MAX = cnt;
						}
						else continue;
					}
				}
				else
					continue;
			}
		}
		else
			continue;
	}
	cout << MAX << endl;
	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
//	input.close();
	return 0;
}