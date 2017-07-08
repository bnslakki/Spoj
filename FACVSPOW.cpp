#include<stdio.h>
#include<math.h>
double dp[4000007];
inline double fun(int n)
{
	double t;
	if (dp[n] != 0)
	{
	//	t = dp[n];
		return dp[n];
	}
	else
	{
		t = log(n);
//		dp[n] = t;
		return dp[n]=t + (1.837877066 + t) / (n << 1);
	}
	
}
int main()
{
	double a, temp;
	int n;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		a = 1 + log(n);
		//	printf("%lf\n", a);
		int initial = 4, end = 3000000, mid;
		mid = (initial + end) >> 1;
		temp = fun(mid);
		//	printf("%lf\n", temp);
		if (temp > a)
		{
			while (temp > a && end > initial)
			{
				end = mid;
				mid = (initial + end) >> 1;
				temp = fun(mid);
			}
			if (temp <= a)
			{
				initial = mid + 1;
				while (end > initial)
				{
					mid = (initial + end) >> 1;
					temp = fun(mid);
					if (temp > a)
					{
						end = mid;
					}
					else if (temp <= a)
					{
						initial = mid + 1;
					}
					if (end == initial)
					{
						mid = end;
						break;
					}
				}
			}
		//	printf("%d\n", mid);
		}
		else
		{
			while (temp < a && end > initial)
			{
				initial = mid;
				mid = (initial + end) >> 1;
				temp = fun(mid);
			}
			end = mid;
			while (end > initial)
			{
				mid = (initial + end) >> 1;
				temp = fun(mid);
				if (temp > a)
				{
					end = mid;
				}
				else if (temp <= a)
				{
					initial = mid + 1;
				}
				if (end == initial)
				{
					mid = end;
					break;
				}
			}
		
		}
		printf("%d\n", mid);
	}
	return 0;
} 
