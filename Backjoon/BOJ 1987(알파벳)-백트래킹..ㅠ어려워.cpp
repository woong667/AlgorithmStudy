#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int arr[100001];
int L, N;

int method1(int idx)
{
	int cnt = 1;
	int bef = idx - 1, aft = idx + 1;
	while (bef>0)   //0만 되더라도 진행할 필요없음
	{
		bef -= N - 1;
		cnt++;
	}
	while (aft < L - 1)  //끝에 도달하기 전까지
	{
		aft += N - 1;
		cnt++;
	}
	return cnt;
}

int method2(int idx)
{
	int cnt = 1;
	int bef = idx, aft = idx + 2;
	while (bef > 0)   //0만 되더라도 진행할 필요없음
	{
		bef -= N - 1;
		cnt++;
	}
	while (aft < L - 1)  //끝에 도달하기 전까지
	{
		aft += N - 1;
		cnt++;
	}
	return cnt;
}

int method3(int idx)
{
	int cnt = 1;
	int bef = idx-2, aft = idx;
	while (bef > 0)   //0만 되더라도 진행할 필요없음
	{
		bef -= N - 1;
		cnt++;
	}
	while (aft < L - 1)  //끝에 도달하기 전까지
	{
		aft += N - 1;
		cnt++;
	}
	return cnt;
}

int main()
{
	ifstream input("a.inp");
	int idx,MIN=100001;
	int cnt = 1000001;
	input >> L >> N;
	for (int i = 0; i < L; i++)
	{
		input >> arr[i];
		if (arr[i] < MIN)
		{
			MIN = arr[i];
			idx = i;
		} //최소 위치를 초기화.
	}
	int a=method1(idx);
	int b = method2(idx);
	int c = method3(idx);
	cout << min(a, min(b, c))<<endl;
	input.close();
	return 0;


}