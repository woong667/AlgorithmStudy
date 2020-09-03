#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int arr[10][10];
bool square_check[9][9]; //3x3 정사각형을 확인하는 배열. 작은 정사각형은 6개
bool garo_check[9][9];
bool sero_check[9][9];
//ifstream input("a.inp");
//ofstream output("a.out");

int trans(int i, int j)
{
	return ((i / 3) * 3) + (j / 3);
}

bool go(int idx)
{
	if (idx == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (j != 8) {
					cout << arr[i][j] << " ";
				}
				else //j가 8일때
					cout << arr[i][j];
				
			}
			if (i != 8) {
				cout << endl;
			}
			
		}
		return true;
	}
	int x = idx / 9;      //                  0~8 까지
	int y = idx % 9;      //좌표가될아이들.   0~8 까지
	if (arr[x][y] != 0)
		return go(idx + 1);
	else{
		for (int i = 0; i < 9; i++)
		{
			if (garo_check[x][i] == false && sero_check[y][i] == false && square_check[trans(x, y)][i] == false) //check에 문제없으면
			{
				garo_check[x][i] = sero_check[y][i] = square_check[trans(x, y)][i] = true; //모든애들한테 true를 주고
				arr[x][y] = i+1;
				if (go(idx + 1))
				{
					return true;
				} //여기서 들어가는거지...뒤에까지 쫙 참이면 밑에꺼 더 볼거없이 리턴.
				garo_check[x][i] = sero_check[y][i] = square_check[trans(x, y)][i] = false;
				arr[x][y] = 0;
			}
		}
	}
	return false;
}

int main()
{
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] != 0) //0이 아니면
			{
				garo_check[i][arr[i][j]-1] = true;
				sero_check[j][arr[i][j]-1] = true;
				square_check[trans(i,j)][arr[i][j]-1] = true;
			} //이미 체크된것들은 true로 바꿔준다.
		}
	} //배열을 모두 입력받고.
	go(0);
	//input.close();
	//output.close();
	return 0;
}