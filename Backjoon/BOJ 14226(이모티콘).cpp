#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;
int dp[1001][1001];
int main() {
	int n;  //목표하는 이모티콘 갯수
	cin >> n;  //입력을 받고
	memset(dp, -1, sizeof(dp)); //d의 모든 인덱스를 -1로 초기화.
	queue<pair<int, int>> q;  //큐를 생성하는데 pair로 생성함.
		q.push(make_pair(1, 0));  //큐에 맨처음 생성하는 큐를 만든다. 현재 화면에 1개,클립보드 0개
	dp[1][0] = 0; //그리고 시간에는 0을 집어넣느다.
	while (!q.empty()) {  //큐가 다 비어질때까지.
		int s, c;    
		s = q.front().first; //현재 화면과 클립보드의 상태를 받는다. 
                         c=q.front().second; 
 		q.pop();     //큐에서는 정보를 이미 받아왔으니 빼버린다.
		if (dp[s][s] == -1) {  // 현재에서 1번 연산을 했을떄 그게 아직 방문한게 아니라면
			dp[s][s] = dp[s][c] + 1;   //전 시간에서 1을 더해주고
			q.push(make_pair(s, s));  //큐에 넣어준다.
		}
		if (s + c <= n && dp[s + c][c] == -1) {  //현재에서 2번 연산을 했을때 그게 아직 방문한게 아니고 둘이 더한게 목표를 넘지 않는다면
			dp[s + c][c] = dp[s][c] + 1;  //기존에서 1을  더해주고
			q.push(make_pair(s + c, c));  //큐에 넣어준다.
		}
		if (s - 1 >= 0 && dp[s - 1][c] == -1) {  //현재에서 3번 연산을 하고 그게 0보다 작아지지않는다면(0보다 작아지는거 생각못함)
			dp[s - 1][c] = dp[s][c] + 1;         //기존에서 1을 더해주고.
			q.push(make_pair(s - 1, c));       //큐에 넣어준다.
		}
	}
	int ans = -1;
	for (int i = 0; i <= n; i++) {
		if (dp[n][i] != -1) {
			if (ans == -1 || ans > dp[n][i]) {
				ans = dp[n][i];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}