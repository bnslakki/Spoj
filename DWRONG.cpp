#include<bits/stdc++.h>
int gcd(int a,int b )
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
int main()
{
	long double b;
	long double n;
	while(scanf("%llf%llf",&b,&n))
	{
		if(b==0&&n==0)
		{
			break;
		}
	long long int k=gcd(b,n);
	long long int temp=n/k;
	long double t1,t2;
	for(long long int m=2*n;m>=temp;m=m-temp)
	{
		long long int a;
		a=(2*m*n*b-m*m*b)/(n*n);
	//	printf("%lld\n",a);
		t1=(b*m-a*n);
		t2=(m*m-m*n);
		if(t1<0)
		t1=t1*(-1);
		if(t2<0)
		t2=t2*(-1);
	//	printf("%lld\n",t2);
	//	printf("%Lf %Lf\n",t1,t2);
		 
		 long double t3;
		 if(t2!=0)
		t3=(t1+0.0)/t2;
		
		//printf("%Lf\n",t3);
		if(a!=b&&n!=m)
		{
		if(t3==b/n)
		printf("%lld/%lld ",a,m);
		}
	}
	printf("\n");
	}
	// 8 560484
	//printf("%d",c);
	return 0;
} 
