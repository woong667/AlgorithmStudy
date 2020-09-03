#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
	
	int test;
	int N;
	cin >> test;
	while (test--)
	{
		cin >> N;
		int **arr = new int*[2];
		for (int i = 0; i < 2; i++)
		{
			arr[i] = new int[N];
		} // 이차원배열 동적할당 완료.
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];;
			}
		} // 스티커 값들을 입력을 받음.
		arr[0][1] = max(arr[0][1], arr[1][0] + arr[0][1]); //2번째 열까지는 인위적으로 계산
		arr[1][1] = max(arr[1][1], arr[0][0] + arr[1][1]); //2번째 열까지는 인위적으로 계산
		for (int i = 2; i < N; i++)
		{
			arr[0][i] = max(arr[0][i - 2] + arr[0][i], max(arr[1][i - 2] + arr[0][i], arr[0][i] + arr[1][i - 1]));
			arr[1][i] = max(arr[0][i - 2] + arr[1][i], max(arr[1][i - 2] + arr[1][i], arr[1][i] + arr[0][i - 1]));  //이 문제의 점화식.
		}
		cout << max(arr[0][N - 1], arr[1][N - 1]) << endl;;
		for (int i = 0; i < 2; i++)
		{
			delete[] arr[i];
		}
		delete[] arr; //동적배열 삭제 완료
	}
	return 0;
}
/*********나이따~~~~~~~~~~*/