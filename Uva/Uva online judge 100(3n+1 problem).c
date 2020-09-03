
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int main(void) {

	
	int a, b;
	long long int n;
	int top = 0;
	int count = 0;
	int *dp = (int*)malloc(sizeof(int) * 1000001);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < 1000001; i++)
	{
		n = i;
		if (dp[i] > 0)
			continue;
		else
		{
			while (n != 1)
			{
				if (n % 2 == 1)     //홀수일때
				{
					if ((3 * n) + 1 > 1000000)
					{
						count++;
						n = (3 * n) + 1;
					}
					else {

						if (dp[(3 * n) + 1] <= 0) //해당자리에 아무것도 없으면
						{
							count++;
							n = (3 * n) + 1;
						}
						else
						{
							dp[i] = ++count + dp[(3 * n) + 1];
							count = 0;
							break;
						}
					}
				}
				else                 //짝수일때
				{
					if (n / 2 > 1000000)
					{
						count++;
						n = n / 2;
					}
					else {
						if (dp[n / 2] <= 0) //해당자리에 아무것도 없으면
						{
							count++;
							n = n / 2;
						}
						else
						{
							dp[i] = ++count + dp[n / 2];
							count = 0;
							break;
						}
					}
				}
				if (n == 1)
					dp[i] = count;
			}
			count = 0;
		}
	}
	while (scanf("%d %d", &a, &b)!=EOF)
	{
		printf("%d %d", a, b);
		if (a > b)        //a가 b보다 커버릴때
		{
			int tmp;
			tmp = a;
			a = b; b = tmp;
		}
		for (int c = a; c <= b; c++)
		{
			if (dp[c] > top)
				top = dp[c];
		}
		printf(" %d\n", top);
		top = 0;
	}
	free(dp);
	return 0;

}
