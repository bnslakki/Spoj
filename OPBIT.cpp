#include "bits/stdc++.h"
using namespace std;
int arr[1005];
void pre()
{
	for(int i=1;i<=1000;i++)
	{
		arr[i]=i*i;
	}
}
int main()
{
	pre();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int st=sqrt(a);
		int en=sqrt(b);
	//	printf("%d %d\n",st,en);
		int s1[1005],k=0;
		for(int i=st;i<en;i++)
		{
			s1[k]=abs(arr[i]-arr[i+1]);
			k++;
		}
		int f1=s1[0],f2=0;
		for(int i=0;i<k;i++)
		{
			f1=f1&s1[i];
			f2=f2^s1[i];
		}
	//	printf("%d %d\n",f1,f2);
		printf("%d\n",f1&f2);
	}
} 
