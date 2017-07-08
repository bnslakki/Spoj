#include<stdio.h>
long long mul(long long a,long long b,long long c){
    long long x=0,y=a%c;
    while(b>0){
        if(b%2==1){
            x=(x+y)%c;
        }
        y=(y*2)%c;
        b/=2;
    }
    return x%c;
}

int main()
{
	const long long int m=109546051211;
	long long int n,i,t=1,p=1;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		t=mul(t,i,m);
		p=mul(p,t,m);
		if(t==0||p==0)
		{
			break;
		}
	}
	printf("%lld",p);
	return 0;
}  
