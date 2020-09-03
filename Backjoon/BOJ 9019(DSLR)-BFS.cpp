#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	
	int T;
	cin >> T;
	int a, b;
	while (T--)
	{
		queue <int> q;
		stack <char> st;
		bool check[10000] = { false , };
		char from_char[10000];
		int from[10000];
		cin >> a >> b;
		check[a] = true;
		from_char[a] = 'E'; //End라는 뜻.
		q.push(a);
		int re = 1000;
		while (!q.empty())
		{
			int num = q.front();
			/////////////////////////////////////
			/************레지스터 D*************/
			if (check[(num * 2) % 10000] == false)     //레지스터 D
			{
				check[(num * 2) % 10000] = true;
				from_char[(num * 2) % 10000] = 'D';       //D 레지스터 썻다고 기억
				from[(num * 2) % 10000] = num;
				q.push((num * 2) % 10000);
			}
			/**********************************/
			////////////////////////////////////
			/************레지스터 S************/
			if (num - 1 >= 0) {                //num-1이 0이 아닐때        
				if (check[(num - 1)] == false)
				{
					check[(num - 1)] = true;
					from_char[(num - 1)] = 'S';
					from[(num - 1)] = num;
					q.push((num - 1));
				}
			}
			else                              //num-1이 0일때
			{
				if (check[9999] == false)
				{
					check[9999] = true;
					from_char[9999] = 'S';
					from[9999] = num;
					q.push(9999);
				}
			}
			/**********************************/
			////////////////////////////////////
			/************레지스터 L************/
			int sub = ((num * 10) / 10000) + ((num * 10) % 10000);
			if (check[sub] == false)
			{
				check[sub] = true;
				from_char[sub] = 'L';
				from[sub] = num;
				q.push(sub);
			}
			/**********************************/
			////////////////////////////////////
			/************레지스터 R************/
			sub = (num / 10) + ((num % 10) * 1000);
			if (check[sub] == false) {
				check[sub] = true;
				from_char[sub] = 'R';
				from[sub] = num;
				q.push(sub);
			}
			/**********************************/
			///////////////////////////////////
			if (check[b] == true)
				break;
			q.pop();
		}


		char e = from_char[b];
		int f = from[b];
		while (e != 'E')
		{
			st.push(e);
			e = from_char[f];
			f = from[f];
		}
		while (!st.empty())
		{
			cout << st.top();
			st.pop();
		}
		cout << endl;

	}
	return 0;
}