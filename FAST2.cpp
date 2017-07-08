#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>
#define Q namespace
Q mp=boost::multiprecision;using Q mp;using Q std;
#define B cpp_int
B R[503];
int main()
{
	string a="1298074214633706835075030044377087";
	B s1(a),S;
	R[0]=1;
	for(int i=1;i<=501;i++)
	{
		R[i]=(2*R[i-1])%s1;
	}
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&n);
	S=0;
	for(int i=0;i<=n;i++)
	{
	S=(S+R[i])%s1;
	}
	cout<<S<<'\n';
	}
	return 0;
} 
