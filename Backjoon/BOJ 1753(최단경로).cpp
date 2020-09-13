#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;
vector <int> arr;


void get_num(string a)
{
	int num=0;
	for (int i = 0; i <= a.length(); i++)
	{
		if (a[i] == ':'||a[i]=='\0')
			num = 0;
		else
		{
			num = num * 10;
			a += (a[i] - '0');
		}
	}
}


int main()
{
	ifstream input("a.inp");
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string a;
	input >> a;
	return 0;
}