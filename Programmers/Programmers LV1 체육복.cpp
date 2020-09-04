#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {


	n = n - (int)lost.size();
	for (int i = 0; i < reserve.size(); i++)
	{
		for (int j = 0; j < lost.size(); j++)
		{
			if (reserve[i] == lost[j])
			{
				n++;
				lost[j] = lost[j] + 30;
				reserve[i] = reserve[i] - 31;
				break;
			}
		}
	}
	for (int i = 0; i < reserve.size(); i++)
	{
		for (int j = 0; j < lost.size(); j++)
		{
			if (reserve[i] - 1 == lost[j] || reserve[i] + 1 == lost[j])
			{
				n++;
				lost[j] = lost[j] + 30;
				break;
			}
		}
	}
	return n;
}