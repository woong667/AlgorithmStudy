#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;
int arr[1001];
int main()
{
	int N;
	arr[1] = 1;
	arr[2] = 3;
	arr[3] = 5;
	for (int i = 4; i < 1001; i++)
	{
		arr[i] = (arr[i - 1] + (arr[i - 2] * 2)) % 10007;
	}
	cin >> N;
	cout << arr[N];
	return 0;
}