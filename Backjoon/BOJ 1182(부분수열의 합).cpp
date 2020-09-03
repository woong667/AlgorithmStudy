#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[20];
int n, m;
int ans = 0;

void go(int i, int sum)
{
	if (i == n)
	{
		if (m == sum) {
			ans += 1;
		}
		return;
	}
	go(i + 1, sum + arr[i]);
	go(i + 1, sum);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	go(0, 0);
	if (m == 0) ans -= 1; //공집합일때 0을 만족시킬수있기떄문에
	cout << ans<<endl;
	return 0;
}