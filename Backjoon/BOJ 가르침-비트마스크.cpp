#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int N, K;
bool learn[26];

int count(vector <string> &words)
{
	int cnt = 0;
	for (string word : words)
	{
		bool flag = true;
		for (char x : word)
		{
			if (!learn[x - 'a'])
			{
				flag = false;
				break;
			}
		}
		if (flag) //flag가 참이면
			cnt++;
	}
	return cnt;
}

int go(int index, int k, vector <string> &words) //아에 벡터를 받앗는건가
{
	if (k < 0) return 0;
	if (index == 26) return count(words); //몇개의 단어를 읽을 수 잇는지 확인하는 함수
	int ans = 0;
	int t1;
	if (learn[index] == false) {
		learn[index] = true;
		t1= go(index + 1, k - 1, words);
		learn[index] = false;
		if (ans < t1)
			ans = t1;
	}
	t1 = go(index + 1, k, words);
	if (ans < t1) ans = t1;
	
	return ans;

}


void init()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}

int main()
{
	//ifstream input("a.inp");
	init();
	learn['a' - 'a'] = true;
	learn['n' - 'a'] = true;
	learn['t' - 'a'] = true;
	learn['i' - 'a'] = true;
	learn['c' - 'a'] = true;
	cin>> N >> K;
	vector <string> words(N);
	for (int i = 0; i < N; i++)
	{
		cin >> words[i];
	}
	K = K - 5;
	cout << go(0, K, words);
 	//input.close();
	return 0;
}