#include <iostream>
#include <algorithm>
#include <functional>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool check(string password)
{
	int j_count = 0;
	int m_count = 0;
	for (int i = 0; i < (int)password.length(); i++)
	{
		if (password[i] == 'a' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u' || password[i] == 'e')
			m_count++;
		else
			j_count++;
	}
	if (m_count < 1 || j_count < 2)
		return false;
	else
		return true;

}

void go(int n,vector <char> &alpha,string password,int i)
{
	if ((int)password.length() == n) //요구라는 자릿수 만큼의 길이가되면
	{
		if (check(password)) //check 함수는 따로 지정.
		{
			cout << password << endl;
		}
		return;   //void 형태에서 함수 빠져나가는것은 return 만 적어줌.
	}
	if (i >= (int)alpha.size())
		return;
	go(n, alpha, password + alpha[i], i + 1);   //해당 문자열을 집어넣고 한칸 넘기는 경우
	go(n, alpha, password, i + 1);  //해당 문자열을 집어넣지 않고 한칸 넘기는경우
}

int main()
{
	
	int num, inp;
	string password = "";
	cin >> num >> inp;
	vector <char> ptr(inp);
	for (int i = 0; i < inp; i++)
	{
		cin >> ptr[i];  //알파벳들 입력을 받는다.
	}
	sort(ptr.begin(), ptr.end()); //알파벳 순서대로 정렬을 시키고. 
	//이중에서 이제 num개의 갯수만큼 이루어진 알파벳 조합들을 만들어야한다.
	go(num,ptr, password, 0);
	return 0;
	
}