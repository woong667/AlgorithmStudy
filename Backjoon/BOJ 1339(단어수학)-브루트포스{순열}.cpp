#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
char alpha[256];
int calc(vector<string> &a, vector<char> &letters, vector<int> &d) {
	int m = letters.size(); //알파벳 벡터의 사이즈를 얻어옴.
	int sum = 0; 
	for (int i = 0; i < m; i++) {
		alpha[letters[i]] = d[i]; //이게 map이나 set에서 쓰는 방법이다. char과 int를 pair시키는것.
	}
	for (string s : a) {
		int now = 0;
		for (char x : s) {
			now = now * 10 + alpha[x];
		}
		sum += now;
	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	vector<string> a(n); //string 배열
	vector<char> letters;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (char x : a[i]) {
			letters.push_back(x);   //vector에 push하고
		}
	}
	sort(letters.begin(), letters.end()); //정렬을 시킨다음
	letters.erase(unique(letters.begin(), letters.end()), letters.end()); //중복되는 요소는 제거를 해버린다.
	int m = letters.size(); //사이즈를 얻어와서
	vector<int> d; 
	for (int i = 9; i > 9 - m; i--) {
		d.push_back(i); //알파벳 벡터 사이즈만큼 새로운 벡터 d에 push를 해준다. 얘는 이제 숫자임.
	}
	sort(d.begin(), d.end()); //이것도 다시 정렬을 해줌.
	int ans = 0;
	do {
		int now = calc(a, letters, d); //매개변수로 단어들이 들어있는 string벡터와 구성된 알파벳들의 벡터 순열된 수 벡터를 전달해줌.
		if (ans < now) {       //최댓값이면 now로 바꿔줌.
			ans = now;
		}
	} while (next_permutation(d.begin(), d.end()));  //숫자 순열을 구해준다.
	cout << ans << '\n';
	return 0;
}