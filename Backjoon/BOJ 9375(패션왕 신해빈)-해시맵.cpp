#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
using namespace std;
int main()
{
	//ifstream input("a.inp");
             ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int Test,typ;
	int sum=1;
	string purpose,name;
	cin >> Test;
	while (Test--)
	{
		map <string, int> m; //옷의 종류와 그 종류의 갯수
		cin >> typ;
		for (int i = 0; i < typ; i++)
		{
			cin >> name >> purpose; //여기서 name은 사실상 필요없음
			m[purpose]++;             //옷의 종류에 ++
		}
		for (auto i = m.begin(); i != m.end(); i++) //map의 처음부터 끝까지 돌면서 auto 는 iterator 형식으로 포인터이다. 객체이기 때문에 포인터로 가르켜야함
		{
			sum = sum * ((*i).second + 1); //각 옷의 종류에게 투명옷이 하나더 있다고 생각하고 한개씩 넣어줌
		} 
		sum -= 1;    //종류별로 다 투명일때->알몸일때를 -1해준다
		cout << sum << endl;
		sum = 1;
	}	
	return 0;
}