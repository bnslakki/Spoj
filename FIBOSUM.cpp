#include<bits/stdc++.h>
#define mod 1000000007
/////////////////////////
long long int mul(long long int mat1[2][2],long long int mat2[2][2])
{
	long long int a=((mat1[0][0]%mod*mat2[0][0]%mod)%mod+(mat1[0][1]%mod*mat2[1][0]%mod)%mod)%mod;
	long long int b=((mat1[0][0]%mod*mat2[0][1]%mod)%mod+(mat1[0][1]%mod*mat2[1][1]%mod)%mod)%mod;
	long long int c=((mat1[1][0]%mod*mat2[0][0]%mod)%mod+(mat1[1][1]%mod*mat2[1][0]%mod)%mod)%mod;
	long long int d=((mat1[1][0]%mod*mat2[0][1]%mod)%mod+(mat1[1][1]%mod*mat2[1][1]%mod)%mod)%mod;
	mat1[0][0]=a;
	mat1[0][1]=b;
	mat1[1][0]=c;
	mat1[1][1]=d;
	return (mat1[0][0])%mod;
}
/////////////////////////
long long int power(long long int mat[2][2],long long int m)
{
	if(m==0||m==1)
	return 1;
	else
	{
	long long int temp[2][2]={{1,1},{1,0}};
	long long int ans;
	power(mat,m/2);
	ans=mul(mat,mat);
	if(m%2!=0)
	ans=mul(mat,temp);
	return ans;
	}
}
/////////////////////////
long long int fib(long long int n)
{
	long long int mat[2][2]={{1,1},{1,0}};
	return power(mat,n-1);
}
////////////////////////
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,tm,tm2,tm3,la;
		scanf("%lld%lld",&n,&la);
		if(n==0&&la==0)
		printf("0\n");
		if(n==la&&n!=0&&la!=0)
		printf("%lld\n",fib(n)%mod);
		else if(n!=0||la!=0)
		{
		tm=(fib(n+1));
		tm2=(fib(la+2));
		tm3=(tm2-tm+mod)%mod;
		printf("%lld\n",tm3);
		}
	}
	return 0;
} 
