#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int cnt = 0;
int N, target;

void go(int *arr,int start, int index, long long int sum) //index는 시작이되는 
{
	if (start == N)
		return; 
	if ( sum > target)       //
	{
		if(start+1<=N)
		  go(arr, start + 1, start + 1, arr[start+1]);
	}
	else if (sum==target)
	{
		cnt++;
		if (start + 1 <= N)
			go(arr, start + 1, start + 1, arr[start + 1]);
	}
	else
	{
		if(index+1<=N)
		   go(arr, start, index + 1, sum + arr[index + 1]);
	}
	return;
}
int main()
{
	//ifstream input("a.inp");
	cin >> N >> target;
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	go(arr, 0, 0, arr[0]);
	cout << cnt << endl;
	delete[] arr;
	//input.close();
	return 0;
}