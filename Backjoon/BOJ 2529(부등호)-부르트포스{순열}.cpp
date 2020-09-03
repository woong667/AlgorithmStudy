#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	//ifstream input("a.inp");
	//ofstream output("a.out");
	int N;
	string MAX_STR = "";
	string MIN_STR = "";
	long long int cached = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cached *= 10;
	}
	char *crr = new char[N];
	int *max_arr = new int[N + 1];
	int *min_arr = new int[N + 1];
	long long int su=0;
	long long int MAX = 0, MIN = 9999999999;
	bool flag = true;
	for (int i = 0; i <N;i++)
	{
		cin >> crr[i];
	}
	if (N == 9)         //N이 9일때
	{
		for (int i = 0; i < 10; i++)
		{
			max_arr[i] = i;
		}
		do {
			for (int i = 0; i < N; i++)
			{
				if (crr[i] == '>')
				{
					if (max_arr[i] < max_arr[i + 1])
					{
						flag = false;
						break;
					}
				}
				else
				{
					if (max_arr[i] > max_arr[i + 1])
					{
						flag = false;
						break;
					}
				}
			}
			if (flag) // 부등호 검사를 무사히 마쳤다면.
			{
				for (int i = 0; i <= N; i++)
				{
					su *= 10;
					su += max_arr[i];
				}
				if (MAX < su)
					MAX = su;
				if (MIN > su)
					MIN = su;
			}
			flag = true;
			su = 0;
		} while (next_permutation(max_arr, max_arr + (N+1))); //N이 9일때 MAX,MIN 둘 다 구하기 위한 do-whlie문
	}
	else
	{
		int k = 0;
		for (int i = 10-(N+1); i<10; i++)
		{
			max_arr[k] = i;
			k++;
		}
		for (int i = 0; i <= N; i++)
		{
			min_arr[i] = i;
		}
		do {
			for (int i = 0; i < N; i++)
			{
				if (crr[i] == '>')
				{
					if (max_arr[i] < max_arr[i + 1])
					{
						flag = false;
						break;
					}
				}
				else
				{
					if (max_arr[i] > max_arr[i + 1])
					{
						flag = false;
						break;
					}
				}
			}
			if (flag) // 부등호 검사를 무사히 마쳤다면.
			{
				for (int i = 0; i <= N; i++)
				{
					su *= 10;
					su += max_arr[i];
				}
				if (MAX < su)
					MAX = su;
			}
			flag = true;
			su = 0;
		} while (next_permutation(max_arr, max_arr + (N+1))); //MAX값을 구하는 do-while문

		do {
			for (int i = 0; i < N; i++)
			{
				if (crr[i] == '>')
				{
					if (min_arr[i] < min_arr[i + 1])
					{
						flag = false;
						break;
					}
				}
				else
				{
					if (min_arr[i] > min_arr[i + 1])
					{
						flag = false;
						break;
					}
				}
			}
			if (flag) // 부등호 검사를 무사히 마쳤다면.
			{
				for (int i = 0; i <= N; i++)
				{
					su *= 10;
					su += min_arr[i];
				}
				if (MIN > su)
					MIN = su;
			}
			flag = true;
			su = 0;
		} while (next_permutation(min_arr, min_arr + (N+1))); //MIN값을 구하는 do-while문
	}
	if (MAX / cached == 0) {
		MAX_STR = "0" + to_string(MAX);
		cout << MAX_STR << endl;
	}
	else
	{
		MAX_STR = to_string(MAX);
		cout << MAX_STR << endl;
	}

	if (MIN / cached == 0) {
		MIN_STR = "0" + to_string(MIN);
		cout << MIN_STR << endl;
	}
	else {
		MIN_STR = to_string(MIN);
		cout << MIN_STR << endl;
	}
	delete[] crr;
	delete[] max_arr;
	delete[] min_arr;
	//input.close();
	//output.close();
	return 0;
}