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

int main()
{
	
             ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N,B,C;
	cin >> N; //시험장 갯수 입력.
	vector <int> v(N);
	long long int answer = N; //어차피 감독관들 한명씩 있어야됨
	int re;
	for(int i=0;i<N;i++) 
	{
		cin >> re;
		v[i] = re; //각각의 장소에서 총감독관이 감시할 수 있는 수만큼 빼버리기.
	} //각 시험장의 수험생 인원.
	cin >> B >> C; //총감독관의 감시 가능인원, 부감독관의 감시 가능 인원.-> 한 고사장에 총감독관 1명은 무조건 있어야한다. 부감독관은 없어도 되고 여러명이어도 됨.
	for (int i = 0; i < N; i++)
	{
		v[i] = v[i] - B;
		if (v[i] > 0) //아직 감시해야할 인원이 더 남아았다면
		{
			answer = answer + (v[i] / C);
			if (v[i] % C != 0) //잔챙이들이 남아있으면
				answer++; // 부감독관 한명더 추가
		}
	}
	cout << answer;
	return 0;
}