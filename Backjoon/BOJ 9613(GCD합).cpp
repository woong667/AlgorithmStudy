#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	while (b != 0)
	{
		int n = a % b;
		a = b;
		b = n;
	}
	return a;
}
int main()
{
	
	int test, n;
	cin >> test;
	while (test--)
	{
		long long count = 0;
		cin >> n;
		int *ptr = new int[n]; //배열 동적할당
		for (int k = 0; k<n; k++)
		{
			cin >> ptr[k];
		} //입력을 받고
		for (int k = 0; k<n; k++)
		{
			for (int l = k + 1; l<n; l++)
			{
				int y = gcd(ptr[k], ptr[l]);
				count += y;			
			}
		}
			cout << count << endl;
	}
	return 0;
}