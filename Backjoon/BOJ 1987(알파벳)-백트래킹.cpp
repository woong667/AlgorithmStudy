#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int arr[21][21];             //입력받는 배열
bool arr_check[21][21];      //들른장소인지 check할 배열
bool check[26];              //사용된 알파벳인지 check할 배열
int mx[4] = { 0,-1,0,1 };   
int my[4] = { -1,0,1,0 };    //움직이는 
int N, M;
int MAX = 0;

void dfs(int x, int y,int sum) {
	
	if (sum > MAX)
		MAX = sum;  //최댓값 갱신
	int nx,ny;
	for (int i = 0; i < 4; i++)
	{
		nx = x + mx[i];
		ny = y + my[i];
		if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1)
			continue;     //범위를 나가면 CONTINUE;

		if (arr_check[nx][ny] == false && check[arr[nx][ny]] == false) //아직 들르지 않은곳이면서 아직 밟지 않은 알파벳이라면.
		{
			arr_check[nx][ny] = true;
			check[arr[nx][ny]] = true; //들렀던 알파벳 처리해주고
			dfs(nx, ny, sum + 1);
			arr_check[nx][ny] = false;  
			check[arr[nx][ny]] = false; //나왔으니까 빼준다.
		}
	}
}

int main()
{
	//ifstream input("a.inp");
	cin >> N >> M;
	char inp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> inp;
			arr[i][j] = inp - 65;  //숫자로 넣어준다. 아스키로 해결하기위해 A=0으로 해줬다
		}
	}
	arr_check[0][0] = true; //첫위치는 들렀고
	check[arr[0][0]] = true; //첫위치의 알파벳은 사용됫다
	dfs(0,0,1);              //0,0 위치에서 CNT=1로 DFS돌린다.
	cout << MAX;
	//input.close();
	return 0;

}
