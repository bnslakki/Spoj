#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("t.txt","r",stdin);
	int t1,t2,t3;
	t1=16,t2=20,t3=18;
	map<char,int >a;
	for(int i=97;i<=122;i++)
	{
		if(i>=97&&i<=109)
		{
			a[i]=t1;
			t1++;
		}
		else if(i>=110&&i<=116)
		{
			a[i]=t2;
			t2++;
		}
		else
		{
			a[i]=t3;
			t3++;
		}
	}
	char arr[30];
	while(scanf("%s",arr)!=EOF)
	{
		int count=0;
		int len=strlen(arr);
		if(len<=3)
		{
			break;
		}
		for(int i=0;i<len;i++)
		{
			int ans=a[arr[i]];
			if(ans>=24)
			{
				count++;
			}
		    printf("%d ",ans);
	    }
	    printf("\n");
	    if(!count)
	    printf("no one.\n");
	    else
	    printf("%d\n",count);
	}
	
	return 0;
} 
