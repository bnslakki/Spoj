#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
 
namespace mp = boost::multiprecision;
using namespace std;
using namespace mp;
cpp_int dp[160];
 
cpp_int catalan_no(int n)
{
	dp[0]=1;
	dp[1]=1;
	for (int i=2; i<=n; i++)
    {
        dp[i] = 0;
        for (int j=0; j<i; j++)
            dp[i] += dp[j] * dp[i-j-1];
    }
	return dp[n];
}
 
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)
			break;
		cout<<catalan_no(n)<<'\n';	
	}
	return 0;
} 
