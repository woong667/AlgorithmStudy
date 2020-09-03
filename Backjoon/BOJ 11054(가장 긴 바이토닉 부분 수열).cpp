#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[1001];
int mi[1001];
int pl[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 1; i--) {
		mi[i] = 1;
		for (int j = i + 1; j <= n; j++) {
			if (a[i] > a[j] && mi[i] < mi[j] + 1) {
				mi[i] = mi[j] + 1;
			}
		}
	} //여기까지 가장 긴 감소수열을 얻었고.

	for (int i = 1; i<=n; i++) {
		pl[i] = 1;
		for (int j = 1; j<i; j++) {
			if (a[j] < a[i] && pl[i] < pl[j] + 1) {
				pl[i] = pl[j] + 1;
			}
		}
	} //여기까지 가장 긴 증가수열을 얻었다.
	int ans = mi[1]+pl[1];
	for (int i = 2; i <= n; i++) {
		if (ans < mi[i]+pl[i]) {
			ans = mi[i]+pl[i];
		}
	}
	cout << ans-1 << endl;
	return 0;
}