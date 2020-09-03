#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int N;
	int max;
	int sum=0;
	int target;
	cin >> N;   //민규가 구매하려고 하는 카드의 갯수.
	int **arr = new int*[N+2];
	int *price = new int[N+1];
	for (int i = 0; i < N+2; i++)
	{
		arr[i] = new int[N+2];
	} //2차원배열 동적할당.
	for (int i = 1; i < N + 1; i++)
	{
		cin >> price[i]; //팩당 가격을 입력을 받는다.
	}
	//첫번째줄을 먼저 초기화
	arr[1][1] = price[1];
	for (int i = 2; i < N + 1; i++)
	{
		arr[1][i] = 0;
	}
	arr[1][N + 1] = price[1];
	arr[0][N + 1] = 0;
	//첫번째 줄 초기화완료.
	for (int i = 2; i < N + 1; i++)
	{
		target = i;
		for (int j = 1; j < N + 1; j++)
		{
			if (target >= j) {
				sum += price[j];
				target -= j;
				sum += arr[target][N + 1];
				arr[i][j] = sum;
				sum = 0;
				target = i; //다시 target을 i값을 주고 반복
			}

		}
		//이제 한바퀴돌았으면 여기서 max값을 구해서 N+1 자리에 넣어준다.
		max = arr[i][1];
		for (int k = 2; k < N + 1; k++)
		{
			if (arr[i][k] > max)
				max = arr[i][k];
		}  //max값을 찾았으면은.
		arr[i][N + 1] = max; //max값을 맨 끝열에 넣어준다.
	}
	cout << arr[N][N + 1]<<endl;
	for (int i = 0; i < N + 2; i++)
	{
		delete[] arr[i];
	}
	delete[] price;
	return 0;
}