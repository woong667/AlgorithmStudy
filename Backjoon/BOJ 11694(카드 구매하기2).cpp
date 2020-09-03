#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main() {
	
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> d(n + 1, -1);   //vector을 n+1개 만들고 -1로 모두 초기화.
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (d[i] == -1 || d[i] > d[i - j] + a[j]) {  //d[i]값이 아직 정해지지 않았고 
				d[i] = d[i - j] + a[j];
			}
		}
	}
	cout << d[n] << '\n';
	return 0;
}