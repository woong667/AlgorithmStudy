#include <iostream>
#include <algorithm>
using namespace std;
int main() {

	int N;
	cin >> N;
	int **arr = new int*[N];
	int *in = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[3];
	} //이차원배열 동적할당 완료.
	for (int i = 0; i < N; i++)
	{
		cin >> in[i];
	}
	arr[0][0] = 0;
	arr[0][1] = in[0];
	arr[0][2] = in[0];
	for (int i = 1; i < N; i++)
	{
		
			arr[i][0] = max(arr[i - 1][0], max(arr[i - 1][1], arr[i - 1][2])); // 뒤에 0은 i번째 포도주를 마시지 않는경우(상관없음, 전텀에서 가장 max값을 가지고 오면된다. 
			arr[i][1] = arr[i - 1][0] + in[i]; // 뒤에 1은 i번째 포도주를 마시지만 이번이 연속 한번인 경우 (전텀에서 먹지않은 [i-1][0]에 이번 i번째 포도주를 더해준다.
			arr[i][2] = arr[i - 1][1] + in[i]; // 뒤에 1은 i번째 포도주를 마시고 이번이 연속 2번이 되는경우.(전텀에서도 마신 [i-1[1]에 이번 i번째 포도주를 더해준다.
		
	}
	cout << max(arr[N - 1][0], max(arr[N - 1][1], arr[N - 1][2])) << endl;
	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	delete[] in;
	return 0;
}
