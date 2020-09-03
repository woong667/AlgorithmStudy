#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;

int arr[8][8]; 
int check[8][8];    
bool copy_check[8][8];
int n, m;
int MIN = 65;
int cnt= 0;
vector <pair<int, pair<int, int> > > point; //cctv번호와 위치들


void right(int i, int j)
{
	for (int k = j+1; k < m; k++)
	{
		if (copy_check[i][k] == true) // 벽이없는곳만
			break;
		if(arr[i][k]==0)
		  check[i][k]++;
	}
}
void un_right(int i, int j)
{
	for (int k = j+1; k < m; k++)
	{
		if (copy_check[i][k] == true)
			break;
		if(arr[i][k]==0)
		  check[i][k]--; //다시 false로
		
	}
}
void down(int i, int j)
{
	for (int k = i+1; k < n; k++)
	{
		if (copy_check[k][j] == true)
			break;
		if(arr[k][j]==0)
		  check[k][j]++;
	}
}
void un_down(int i, int j)
{
	for (int k = i+1; k < n; k++)
	{
		if (copy_check[k][j] == true)
			break;
		if(arr[k][j]==0)
		  check[k][j]--;
		
	}
}

void left(int i, int j)
{
	for (int k = j-1; k >= 0; k--)
	{
		if (copy_check[i][k] == true)
			break;
		if(arr[i][k]==0)
		  check[i][k]++;
	}
}
void un_left(int i, int j)
{
	for (int k = j-1; k >= 0; k--)
	{
		if (copy_check[i][k] == true)
			break;
		if(arr[i][k]==0)
		  check[i][k]--;
		
	}
}
void up(int i, int j)
{
	for (int k = i-1; k >= 0; k--)
	{
		if (copy_check[k][j] == true)
			break;
		if(arr[k][j]==0)
		  check[k][j]++;
	}
}
void un_up(int i, int j)
{
	for (int k = i-1; k >= 0; k--)
	{
		if (copy_check[k][j] == true)
			break;
		if(arr[k][j]==0)
		check[k][j]--;
	}
}

void get_p()
{
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < m; b++)
		{
			if (check[a][b] == 0)
			{
				cnt++;
			}
		}
	}
	if (MIN > cnt)
		MIN = cnt;
	cnt = 0;
}


void run(int idx,int cctv, int i, int j)   //벡터의 인덱스
{
	
	if (cctv == 1)
	{
		right(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_right(i, j);
		down(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_down(i, j);
		left(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_left(i, j);
		up(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_up(i, j);

	}
	else if(cctv==2)
	{
		right(i, j);
		left(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_right(i, j);
		un_left(i, j);
		up(i, j);
		down(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_up(i, j);
		un_down(i,j);

	}
	else if (cctv == 3)
	{
		up(i, j);
		right(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_up(i, j);
		un_right(i, j);
		right(i, j);
		down(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_right(i, j);
		un_down(i, j);
		down(i, j);
		left(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_down(i, j);
		un_left(i, j);
		left(i, j);
		up(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_left(i, j);
		un_up(i, j);
	}
	else if (cctv == 4)
	{
		left(i, j);
		up(i, j);
		right(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_left(i, j);
		un_up(i, j);
		un_right(i, j);
		up(i, j);
		right(i, j);
		down(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_up(i, j);
		un_right(i, j);
		un_down(i, j);
		right(i, j);
		down(i, j);
		left(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_right(i, j);
		un_down(i, j);
		un_left(i, j);
		down(i, j);
		left(i, j);
		up(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_down(i, j);
		un_left(i, j);
		un_up(i, j);
	}
	else
	{
		up(i, j);
		right(i, j);
		down(i, j);
		left(i, j);
		if (idx + 1 < (int)point.size())
		{
			run(idx + 1, point[idx + 1].first, point[idx + 1].second.first, point[idx + 1].second.second);
		}
		else
		{
			get_p();
		}
		un_up(i, j);
		un_right(i, j);
		un_down(i, j);
		un_left(i, j);
	}
	return;
}

int main()
{
	//ifstream input("a.inp");
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				if (arr[i][j] == 6)
				{
					check[i][j]++;
					copy_check[i][j]=true;  //copy_check는 벽을 의미하는 공간
				}
				else
				{
					check[i][j]++;
					point.push_back(make_pair(arr[i][j], make_pair(i, j)));
				}
			}
		}
	} //입력완료.
	if (!point.empty()) {
		run(0, point[0].first, point[0].second.first, point[0].second.second);
	}
	else
	{
		int cc = 0;
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < m; k++)
			{
				if(arr[i][k] == 0)
				   cc++;
			}
		}
		MIN = cc;
	}
	cout << MIN << endl;
	//input.close();
	return 0;
	

}

 