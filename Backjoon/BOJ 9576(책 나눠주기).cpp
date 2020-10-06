#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <memory>
#include <map>
#include <string>
#include <queue>
using namespace std;
bool Student[1001];


bool compare(const pair<int,int> &a,const pair<int,int> &b) //second를 기준으로 sort한다 하지만
{
	if (a.second == b.second) return a.first < b.first;  //second가 같을경우에 first기준으로 오름차순 sort
	return a.second < b.second;
}


int main()
{
             ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector <pair<int, int> > v;
	int N, M,s,e;
	int T;
	int answer = 0;
	input >> T;
	while (T--)
	{
		v.clear();
		fill(Student,Student+1001, false);
		input >> N >> M;
		for (int i = 0; i < M; i++)
		{
			
			input >> s >> e;
			v.push_back(make_pair(s, e));
		}//입력을 받고
		sort(v.begin(), v.end(), compare);
		for (int i = 0; i < (int)v.size(); i++)
		{
			int ss = v[i].first;
			int ee = v[i].second;
			for (int j = ss; j <= ee; j++)
			{
				if (Student[j] == false) //아직 주지 않은 책이라면
				{
					Student[j] = true;
					answer++;
					break;
				}
			}
		}
		cout << answer <<endl;
		answer = 0;
	}
	return 0;
}