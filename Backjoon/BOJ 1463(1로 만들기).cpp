#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
int arr[1000000];


void init()
{
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	for (int i = 4; i <= 1000000; i++)
	{
		int min= 1000000;
		if (i % 2 == 0) //2로 나뉘어떨어지면?
		{
			int a;
			a = arr[i / 2] + 1;
			if (a < min)
				min = a;

		}
		if (i % 3 == 0) //3으로 나뉘어 떨어지면?
		{
			int b;
			b = arr[i / 3] + 1;
			if (b < min)
				min = b;
		}
		int c = arr[i - 1]+1; // 마지막으로 1을 뺐을때의 값.
		if (c < min)
			min = c;
		arr[i] = min;
		
	}
}
int main()
{
	init();
	int n;
	cin >> n;
	cout << arr[n];
	return 0;
	
}