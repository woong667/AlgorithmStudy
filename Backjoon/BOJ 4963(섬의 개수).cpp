#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> dap;
int sum = 0;

void dfs(int **arr, int w, int h, int i,int j)
{
	arr[i][j] -= 1;
	if (j - 1 > -1 && arr[i][j - 1] == 1) //왼쪽에 1이 있는 경우
	{
		sum++;
		dfs(arr, w, h, i, j - 1);
	}
	if (i - 1 > -1 && j - 1 > -1 && arr[i - 1][j - 1] == 1) //왼쪽 대각선에 1이 있는 경우
	{
		sum++;
		dfs(arr, w, h, i - 1,j - 1);
	}
	if (i - 1 > -1 && arr[i - 1][j] == 1) //바로 위쪽에 1이 있는 경우.
	{
		sum++;
		dfs(arr, w, h, i - 1, j);
	}
	if (i - 1 > -1 && j + 1 < w&&arr[i - 1][j + 1] == 1)  //오른쪽 위(대각선)에 1이 있는경우.
	{
		sum++;
		dfs(arr, w, h, i - 1, j + 1);
	}
	if (j + 1 < w&&arr[i][j + 1] == 1)  //바로 오른쪽
	{
		sum++;
		dfs(arr, w, h, i, j + 1);
	}
	if (i + 1 < h&&j + 1 < w&&arr[i + 1][j + 1] == 1)//오른쪽 아래
	{
		sum++;
		dfs(arr, w, h, i + 1, j + 1);
	}
	if (i + 1 < h&&arr[i + 1][j] == 1)   //바로 아래
	{
		sum++;
		dfs(arr, w, h, i + 1, j);
	}
	if (i + 1 < h&&j - 1 > -1 && arr[i + 1][j - 1] == 1)  //왼쪽아래 대각선
	{
		sum++;
		dfs(arr, w, h, i + 1, j - 1);
	}
}
int main()
{
	int w, h;
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		int **arr = new int*[h];
		for (int i = 0; i < h; i++)
		{
			arr[i] = new int[w];
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}  //섬의 모양을 입력받고.
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] == 1)
				{
					sum++;
					dfs(arr, w, h, i, j);
					if (sum > 0)
					{
						dap.push_back(sum);
						sum = 0;
					}
				}
			}
		}
		cout << dap.size() << endl;
		while (!dap.empty())
		{
			dap.pop_back();
		}
		for (int i = 0; i < h; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
	return 0;
}