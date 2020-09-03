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
	arr[2] = 2;
	arr[3] = 3;
	for (int i = 4; i < 1001; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2])%10007;  //맨 끝에 한개짜리 두개짜리를 붙이는 방법 외에는 없다.
	}
	cin >> N;
	cout << arr[N];
	return 0;

}