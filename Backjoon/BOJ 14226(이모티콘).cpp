#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;
int d[1001][1001];
int main() {
	int n;  //목표하는 이모티콘 갯수
	cin >> n;  //입력을 받고
	memset(d, -1, sizeof(d)); //d의 모든 인덱스를 -1로 초기화.
	queue<pair<int, int>> q;  //큐를 생성하는데 pair로 생성함.
		q.push(make_pair(1, 0));  //큐에 맨처음 생성하는 큐를 만든다. (1,0) 이 처음 
	d[1][0] = 0; //그리고 시간에는 0을 집어넣느다.
	while (!q.empty()) {  //큐가 다 비어질때까지.
		int s, c;    
		tie(s, c) = q.front(); //현재 화면과 클립보드의 상태를 받는다.  #include <tuple> 을 해야지 생성가능.
 		q.pop();     //큐에서는 정보를 이미 받아왔으니 빼버린다.
		if (d[s][s] == -1) {  // 현재에서 1번 연산을 했을떄 그게 아직 방문한게 아니라면
			d[s][s] = d[s][c] + 1;   //전 시간에서 1을 더해주고
			q.push(make_pair(s, s));  //큐에 넣어준다.
		}
		if (s + c <= n && d[s + c][c] == -1) {  //현재에서 2번 연산을 했을때 그게 아직 방문한게 아니고 둘이 더한게 목표를 넘지 않는다면
			d[s + c][c] = d[s][c] + 1;  //기존에서 1을  더해주고
			q.push(make_pair(s + c, c));  //큐에 넣어준다.
		}
		if (s - 1 >= 0 && d[s - 1][c] == -1) {  //현재에서 3번 연산을 하고 그게 0보다 작아지지않는다면
			d[s - 1][c] = d[s][c] + 1;         //기존에서 1을 더해주고.
			q.push(make_pair(s - 1, c));       //큐에 넣어준다.
		}
	}
	int ans = -1;
	for (int i = 0; i <= n; i++) {
		if (d[n][i] != -1) {
			if (ans == -1 || ans > d[n][i]) {
				ans = d[n][i];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}