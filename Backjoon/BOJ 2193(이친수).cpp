#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
long long int arr[91][2];

void init()
{
	arr[1][1] = 1;
	arr[1][0] = 0;
	for (int i = 2; i < 91; i++)
	{
		arr[i][0] = arr[i - 1][1] + arr[i - 1][0];
		arr[i][1] = arr[i - 1][0];
	}
}
int main() {
	
	init();
	int N;
	long long int sum = 0;
	cin >> N;
	sum = arr[N][0] + arr[N][1];
	cout << sum<< endl;
	return 0;
}