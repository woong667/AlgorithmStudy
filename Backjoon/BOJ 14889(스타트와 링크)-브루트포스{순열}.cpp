#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	//ifstream input("a.inp");
	//ofstream output("a.out");
	int N; //사람수.
	int a = 0, b = 0;
	int ans;
	int MIN = 99999999;
	cin >> N;
	int **arr = new int*[N];
	int *sub_arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		if (i <= (N / 2) - 1)
			sub_arr[i] = 0;
		else
			sub_arr[i] = 1;

	} //동적배열 할당완료.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	} //입력 완료.
	do {
		for (int i = 0; i < N-1; i++)
		{
			if (sub_arr[i] == 0) {
				for (int j = i + 1; j < N; j++)
				{
					if (sub_arr[j] == 0)
					{
						a += arr[i][j];
						a += arr[j][i];
					}
				}
			}
			else
			{
				for (int j = i + 1; j < N; j++)
				{
					if (sub_arr[j] == 1)
					{
						b += arr[i][j];
						b += arr[j][i];
					}
				}
			}
		}
		if (a - b < 0)
			ans = -(a - b);
		else
			ans = a - b;
		if (ans < MIN)
			MIN = ans;
		a = 0;
		b = 0;
	} while (next_permutation(sub_arr, sub_arr +N));
	for (int i= 0; i < N; i++)
	{
		delete[] arr[i];
	}
	cout << MIN << endl;
	delete[] arr;
	delete[] sub_arr;
	//input.close();
	//output.close();
	return 0;
}