#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int count = 0;
	bool flag = true;
	int n;  //배열사이즈
	cin >> n; //배열 사이즈 입력받고.
	vector <int> a(n); //벡터 만들어준다.   next_permutation이 벡터에 적용하는 건가봐...
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	do {
		for (int i = 0; i < n; i++)
		{
			if (i + 1 == a[i]) //자리수와 그 해당 넘버가 같으면
				flag = false; 
		}
		if (flag == true)
		{
			count++;
			for (int i = 0; i < n; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}
		flag = true;
	} while (next_permutation(a.begin(), a.end()));
	cout << count<<endl;
	return 0;
}