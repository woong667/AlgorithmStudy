#include <iostream>
using namespace std;
int main()
{
	int p, q, r;
	int e = 1, s = 1, m = 1;
	cin >> p >> q >> r;
	for (int i = 1; i < 7981; i++)
	{
		e++;
		s++;
		m++;
		if (e == 16)
			e = 1;
		if (s == 29)
			s = 1;
		if (m == 20)
			m = 1;
		if (e == p && s == q && m == r)
		{
			if (i + 1 > 7980)
				i = 0;
			cout << i+1;
			break;
		}
	}
	return 0;	
}