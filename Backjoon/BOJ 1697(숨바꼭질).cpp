#include <iostream>
#include <queue>
using namespace std;
int main()
{
	bool check[100001] = { false, };
	int dist[100001] = { 0, }; //이게 뭐든 변수들을 초기화하는 코드.
	int count = 1;
	queue <int> q;
	int N, K;  //N이 수빈이 위치 K가 동생 위치.
	cin >> N >> K;
	check[N] = true;
	if (N - 1 >=0 ) {
		q.push(N - 1);
		check[N - 1] = true;
		dist[N - 1] = 1;
	}
	if (N + 1 <= 100000) {
		q.push(N + 1);
		dist[N + 1] = 1;
		check[N + 1] = true;
	}
	if (N!=0&&N * 2 <= 100000) {
		q.push(N * 2);
		check[N * 2] = true;
		dist[N * 2] = 1;
	}
	while (check[K] == false)  //동생이 true이 되기전까지.
	{
		int a = q.front(); //맨 앞자리 값.
		if (a - 1 >= 0) {
			if (check[a - 1] == false)
			{
				check[a - 1] = true; //트루로 바꾸고.
				dist[a - 1] = dist[a] + 1; //+1을 한값을 준다.
				q.push(a - 1);
			}
		}
		if (a + 1 <= 100000) {
			if (check[a + 1] == false)
			{
				check[a + 1] = true;
				dist[a + 1] = dist[a] + 1;
				q.push(a + 1);
			}
		}
		if (a * 2 <= 100000) {
			if (check[a * 2] == false)
			{
				check[a * 2] = true;
				dist[a * 2] = dist[a] + 1;
				q.push(a * 2);
			}
		}
		q.pop();
	}
	cout << dist[K];
	return 0;
}