#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	
	int N;
	int count = 0;
	int arr[4];
	int max_dap=-2000000000, min_dap=2000000000;
	int sum;
	cin>> N;
	vector <int> a(N);

	for (int i = 0; i < N; i++) {
		cin>> a[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
		count += arr[i];
	}
	vector <int> op(count);
	count = 0;
	sum = a[0];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			op[count] = i;
			count++;
		}
	}
	do {
		for (int i = 1; i < N; i++)
		{
			if (op[i-1] == 0)
			{
				sum += a[i];
			}
			else if (op[i-1] == 1)
			{
				sum -= a[i];
			}
			else if (op[i-1] == 2)
			{
				sum *= a[i];
			}
			else
			{
				sum /= a[i];
			}
		}
		if (sum > max_dap)
		{
			max_dap = sum;
		}
		if (sum < min_dap)
		{
			min_dap = sum;
		}
		sum = a[0];
	} while (next_permutation(op.begin(), op.end()));
	cout << max_dap << endl;
	cout << min_dap << endl;
	return 0;
}