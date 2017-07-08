#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int arr[1000],arr2[1000],i,a,b,j,sum=0,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	scanf("%d",&arr2[i]);
	for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (arr[i]>arr[j])
            {
                a= arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (arr2[i]>arr2[j])
            {
                b= arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = b;
            }
        }
    }
    for(i=0;i<n;i++)
    {
    	sum=sum+arr[i]*arr2[i];
	}
	printf("%d\n",sum);
	}
	return 0;
} 
