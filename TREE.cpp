#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
 
namespace mp = boost::multiprecision;
using namespace std;
using namespace mp;
 
cpp_int dp[35];
cpp_int power(cpp_int a,cpp_int b)
{
	cpp_int x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x*y);
		}
		y=(y*y);
		b=b/2;
	}
	return x;
}
int main()
{
	int n,d;
	while(scanf("%d%d",&n,&d)!=EOF)
	{
		if(n==0&&d==0)
		break;
		
		printf("%d %d ",n,d);
		if(d==0)
		{
			printf("1\n");
		}
		else
		{
			dp[0]=1;
			for(int i=1;i<=d;i++)
			{
				dp[i]=1+power(dp[i-1],n);
			}	
			cout<<dp[d]-dp[d-1]<<'\n';
		}
	}
	return 0;
}
 
