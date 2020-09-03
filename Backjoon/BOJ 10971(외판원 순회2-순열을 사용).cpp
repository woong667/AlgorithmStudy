#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int flag = 0;
	int n;  //배열사이즈
	int sum = 0;
	int min = 10000001;
	cin >> n; //배열 사이즈 입력받고.
	vector <int> a(n); //벡터 만들어준다.   next_permutation이 벡터에 적용하는 건
	int **ptr = new int*[n+1];
	for (int i = 1; i < n+1; i++)
	{
		ptr[i] = new int[n+1];
	} //2차원배열 동적할당
	
	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < n+1; j++)
		{
			cin >> ptr[i][j];  //모든 비용들을 입력을 받고.
		}
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}   //순열먼저 만들고.
	do {
		for (int i = 0; i < n-1; i++)
		{
			if (ptr[a[i]][a[i + 1]] != 0)
				sum += ptr[a[i]][a[i + 1]];
			else   //가는길이 없으면 flag를 1로 놓고 break
			{
				flag = 1;
				break;
			}
		}
		if (ptr[a[n - 1]][a[0]] != 0)
			sum += ptr[a[n - 1]][a[0]];
		else   //마지막 다시 원위치로 돌아가는 것도 검사를 해준다.
			flag = 1;


		if (flag != 1) 
		{
			if (sum < min)
				min = sum;
		}
		sum = 0;
		flag = 0;
	} while (next_permutation(a.begin(), a.end()));
	cout << min << endl;
	return 0;
}