#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
vector <int> pl;
vector <int> mi;
//예외상황1. 음수가 마지막에 하나 남았는데 0이 입력에 있다면 0으로 중화시켜줘야함
//예외상황2. 양수에서 묶어서 곱한다고 다 큰게 아닌 1 1이 연속으로 있다면 묶어서 곱하는거 보다 더하는게 더 큰 
bool desc(vector <int> a, vector <int> b)
{
	if (a > b)
		return true;
	else
		return false;
}

int main()
{
	ifstream input("a.inp");
	int N, tmp;
	bool zero = false;
	long long int MAX = 0;
    long long int cnt=0;
	input >> N;
	for (int i = 0; i < N; i++)
	{
		input >> tmp;
		if (tmp > 0)
			pl.push_back(tmp);
		else if (tmp < 0)
			mi.push_back(tmp);
		else //0이라면
			zero = true;

		//0이 들어온다면 버린다.
	}
	sort(pl.begin(), pl.end());   //plus는 내림차순으로 정렬하고
	reverse(pl.begin(), pl.end());
	sort(mi.begin(), mi.end()); // minus는 오름차순으로 정렬을 한다.
	for (int i = 0; i < (int)pl.size();)
	{
		if (i + 1 < (int)pl.size()) //범위내라서 묶을 수 있다면
		{
			if (pl[i] + pl[i + 1] < pl[i] * pl[i + 1])  //곱한경우가 크다면
				cnt = cnt + (pl[i] * pl[i + 1]); //두개를 곱해서 다 더하고
			else
				cnt = cnt + pl[i] + pl[i + 1];
			i = i + 2;                     //인덱스는 2를 옮겨줌
		}
		else                          //뒤에 아무것도 없다면
		{
			cnt = cnt + pl[i];        //하나만 더하고
			i = i + 1;                //인덱스는 1을 옮겨줌
		}
		MAX += cnt;
		cnt = 0;
	}
	for (int i = 0; i < (int)mi.size();)
	{
		if (i + 1 < (int)mi.size()) //범위내라서 묶을 수 있다면
		{
			cnt = cnt + (mi[i] * mi[i + 1]); //두개를 곱해서 다 더하고
			i = i + 2;                     //인덱스는 2를 옮겨줌
		}
		else                          //뒤에 아무것도 없다면(마지막 하나가 남은거니까...
		{
			if(zero==false) //0이 없으면
			    cnt = cnt + mi[i];        //하나만 더하고
			//0이 있으면 걍 넘어간다.
			i = i + 1;                //인덱스는 1을 옮겨줌
		}
		MAX += cnt;
		cnt = 0;
	}
	cout << MAX;
	input.close();
	return 0;
}