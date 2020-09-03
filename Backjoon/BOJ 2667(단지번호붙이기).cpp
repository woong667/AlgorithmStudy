#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int danji[1000];
int c = 1;
int sum = 0;
vector <int> gap;
void dfs(int **arr, int g, int s,int n)
{
	arr[g][s] -= 1;
	
	
	if (s+1<n&&arr[g][s + 1] == 1) //오른쪽을 보는 코드
	{
		sum++;
		dfs(arr, g, s + 1, n);
			
	}
	if (g+1<n&&arr[g + 1][s] == 1) //아래쪽을 보는 코드
	{
		sum++;
		dfs(arr, g + 1, s, n);
			
	}
	if (s-1>-1&&arr[g][s - 1] == 1) //왼쪽을 보는 코드
	{
		sum++;
		dfs(arr, g, s - 1, n);
			
	}
	if (g-1>-1&&arr[g - 1][s] == 1) //위쪽을 보는 코드
	{
		sum++;
		dfs(arr, g - 1, s, n);		
	}
}

int main()
{
	string a;
	int s;
	cin >> s;
	int **arr = new int*[s];
	for (int i = 0; i < s; i++)
	{
		arr[i] = new int[s];
	}
	
	for (int i = 0; i < s; i++)
	{
		cin >> a;
		for (int j = 0; j < s; j++)
		{
			arr[i][j] = a[j]-'0';
		}
	} //여기까지 입력을 다 받앗꼬.

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (arr[i][j] == 1)
			{
				arr[i][j] = 0;
				sum++;
				dfs(arr, i, j, s);
			}
			if (sum > 0)
			{
				gap.push_back(sum);
				sum = 0;
			}
		}
	}
	cout << gap.size() << endl;
	sort(gap.begin(), gap.end());
	for (int i = 0; i < (int)gap.size(); i++)
	{
		cout << gap[i]<<endl;
	}
	return 0;
}