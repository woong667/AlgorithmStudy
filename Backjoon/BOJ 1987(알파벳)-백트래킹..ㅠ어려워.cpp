#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
//A는 아스키로 65
//ifstream input("a.inp");
//ofstream output("a.out");
char arr[20][20];
string a[20];
int R, C;
bool eng[26];
int get_x[4] = { -1,0,1,0 };       //좌->상->우->하
int get_y[4] = { 0,-1,0,1 };       //좌->상->우->하
int MAX = 0;
int cnt= 0;

bool full()
{
	for (int i = 0; i < 26; i++)
	{
		if (eng[i] == false)
			return false;
	}
	return true;  //
}

bool go(int i, int j)
{
	if (full())   //full이면 더이상 갈 수 있는곳없다는 뜻.
		return false;

	if (eng[arr[i][j] - 65] == true)
		return false;
	else
	{
		eng[arr[i][j] - 65] = true;
		cnt++;
		if (cnt > MAX)
			MAX = cnt;
		for (int k = 0; k < 4; k++)
	    {
			if (j + get_x[k]<0 || j + get_x[k]>C - 1 || i + get_y[k]<0 || i + get_y[k]>R - 1||eng[arr[i+get_y[k]][j+get_x[k]]-65]==true)
			{
				continue;
			} //돌아가야한다.
		    else
		    {
				go(i + get_y[k], j + get_x[k]);
		    }
		}
		eng[arr[i][j] - 65] = false;
		cnt--;
		return false;
	}
	return true;
}
int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			arr[i][j] = a[i][j];
		}
	}
	go(0, 0);
	cout << MAX << endl;
	//input.close();
	//output.close();
	return 0;
	
}