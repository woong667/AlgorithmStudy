#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
			return 0;
		vector <int> a(n);
		vector <int> b(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i]; //a는 값을 입력받고
			if (i < 6)
				b[i] = 0;
			else
				b[i] = 1;
		}
		do {
			for (int i = 0; i < n; i++)
			{
				if (b[i] == 0)
					cout << a[i] << " ";
			}
			cout << endl;

		} while (next_permutation(b.begin(), b.end()));
		cout << endl;
	}
}