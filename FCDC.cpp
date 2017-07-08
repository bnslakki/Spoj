#include<bits/stdc++.h>
using namespace std;
int a[30],k=0;
void factor(int n)
{
    k=0;
//	printf("%d\n",n);
	if(n==1)
	{
		a[k]=1;
		k++;
		return;
	}
	if(n%2==0)
	{
	//	printf("fg");
		a[k]=2;
		k++;
		while(n%2==0)
		{
			n=n/2;
		}
	}
	for(int i=3;i<=sqrt(n);i=i+2)
	{
		if(n%i==0)
		{
			a[k]=i;
			k++;
			while(n%i==0)
			{
				n=n/i;
			}
		}
	}
	if(n>2)
	{
		a[k]=n;
		k++;
	}
}
int main()
{
//	freopen("t.txt","r",stdin);
	int A,B;
	scanf("%d%d",&A,&B);
	factor(B);
	int max1=-1;
	int max2=-1;
	for(int i=0;i<k;i++)
	{
		if(a[i]>=max1)
		{
	//		printf("%d ",a[i]);
			max1=a[i];
		}
	}
//	printf("\n");
	factor(A);
	for(int i=0;i<k;i++)
	{
		if(a[i]>=max2)
		{
	//		printf("%d ",a[i]);
			max2=a[i];
		}
	}
//	printf("\n");
///	if(max2>max)
//	printf("0\n");
//	else
	printf("%d\n",max(0,max1-max2));
	
