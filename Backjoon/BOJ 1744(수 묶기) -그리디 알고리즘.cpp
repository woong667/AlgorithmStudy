#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
vector <int> pl;
vector <int> mi;
//두수를 묶어서 최대값을 만들어 주는 문제
//먼저 생각한거: 음수는 음수와 곱해주고 양수는 양수끼리 곱해주고 0은 버려버린다.
//고려해줘야 하는 상황 1. 음수가 마지막에 하나 남았는데 0이 입력에 있다면 0으로 중화시켜줘야함 => 0의 갯수를 카운트해줘서 음수를 없애버려야함
//고려해줘야 하는 상황 2. 양수에서 묶어서 곱한다고 다 큰게 아닌 1 1이 연속으로 있다면 묶어서 곱하는거 보다 더하는게 더 큰 
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
	bool zero = false; //0이 없는지 있는지 체크하는 변수
	long long int MAX = 0;
        long long int cnt=0;
	input >> N;
	for (int i = 0; i < N; i++)
	{
		input >> tmp;
		if (tmp > 0)
			pl.push_back(tmp);     //양수이면 양수 배열에
		else if (tmp < 0)
			mi.push_back(tmp);     //음수이면 음수 배열에
		else //0이라면
			zero = true;          //0이 있으면 zero변수 true

		
	}
	sort(pl.begin(), pl.end());   //plus는 내림차순으로 정렬하고  => 큰수들끼리 곱해줘야 수가 크니까
	reverse(pl.begin(), pl.end());
	sort(mi.begin(), mi.end()); // minus는 오름차순으로 정렬을 한다.
	for (int i = 0; i < (int)pl.size();)     //먼저 plus영역부터
	{
		if (i + 1 < (int)pl.size()) //범위내라서 묶을 수 있다면 (vector는 범위에 민감하기 때문에 미리 체크)
		{
			if (pl[i] + pl[i + 1] < pl[i] * pl[i + 1])  //둘이 더한것고 vs 둘이 곱한거
				cnt = cnt + (pl[i] * pl[i + 1]); // 곱한게 크면 두개를 곱해서 다 더하고
			else
				cnt = cnt + pl[i] + pl[i + 1];  //더한게 크면 더한걸 cnt에 더해주고
			i = i + 2;                     //묶었으니까 인덱스는 2를 옮겨줌 
		}
		else                          // 배열의 제일 마지막 숫자이면 뒤에 아무것도 없으니
		{
			cnt = cnt + pl[i];        //하나만 더하고
			i = i + 1;                //인덱스는 1을 옮겨줌
		}
		MAX += cnt;     // MAX값 갱신
		cnt = 0;        // cnt는 0으로 초기화
	}
	for (int i = 0; i < (int)mi.size();)   //이제 minus 영역
	{
		if (i + 1 < (int)mi.size()) //범위내라서 묶을 수 있다면 (묶을수 있다면 무조건 묶어야됨 음수는)
		{
			cnt = cnt + (mi[i] * mi[i + 1]); //두개를 곱해서 다 더하고
			i = i + 2;                     //인덱스는 2를 옮겨줌
		}
		else                          //맨 마지막 인덱스까지 왔을때
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
