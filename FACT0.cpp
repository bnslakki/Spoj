#include<stdio.h>
#include<math.h>
void prime(long long int n)
{
	long long int i,temp=0,count=0,count2=0;
    while (n%2 == 0)
    {
    	count2++;
    	temp=1;
        
        n=n/2;
    }
    if(temp==1)
    {
    	printf("2^%lld ",count2);
	}
    for(i=3;i<=sqrt(n);i=i+2)
    {
    	if(n%i==0)
    	{
    	count=0;
        while (n%i==0)
        {
        	count++;
            n=n/i;
        }
        if(temp==1)
        {
        printf("%lld^%lld\n", i,count);
    	}
    	else if(temp==0)
        {
        printf("%lld^%lld ", i,count);
    	}
    }
    }
    if (n>2)
        printf("%lld^1\n", n);
}
int main()
{
	long long int n;
	while(scanf("%lld",&n))
	{
		if(n==0)
		{
			break;
		}
		prime(n);
	}
		return 0;
} 
