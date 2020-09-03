#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

bool cmp(const pair <int,int > &p1, const pair <int,int> &p2) {
	if (p1.first < p2.first) {
		return true;
	}
	else {
		return false;
	}
}

void init()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}

int main()
{ 
	//ifstream input("a.inp");
	init();
	int T,N;
	cin >> T;
	while (T--)
	{
		vector <pair <int, int > > v;
		cin >> N;
		int a, b,count=1;
		bool flag = true;
		while (N--)
		{
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end(), cmp);
		for (int i = v.size() - 1; i >= 1; i--)
		{
			for (int j = i - 1; j >= 0; j--) {
				if (v[j].second < v[i].second)
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
				count++;
			flag = true;
		}
		cout << count << endl;
		count = 1;
	}
	//input.close();
	return 0;
}