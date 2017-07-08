#include<stdio.h>
int main()
{
	int t,temp=0;
	scanf("%d",&t);
	while(t--)
	{
		int a;
		scanf("%d",&a);
		temp=temp^a;
	}
	printf("%d\n",temp);
	return 0;
} 
