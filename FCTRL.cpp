#include<bits/stdc++.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long int n,sum=0;
		scanf("%ld",&n);
		
		while(n>1)
		{
			n=n/5;
			sum=sum+n;
			
		}
		printf("%ld\n",sum);
	}
	return 0;
} 
