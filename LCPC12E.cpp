#include<bits/stdc++.h>
int main()
{
	int t,m=1;
//	freopen("t.txt","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		long double x1,y1,x2,y2,r1,l,r2,d,cl;
		scanf("%LF%LF%LF%LF%LF%LF",&x1,&y1,&x2,&y2,&r1,&l);
		r2=l/sqrt(2);
		d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		cl=sqrt((r1+r2+d)*(r1+r2-d)*(r1-r2+d)*(-r1+r2+d));
		cl/=d;
		if(d>=r1+r2)
		{
			printf("%d. No problem\n",m);
			m++;
		}
		
		else
		{
			printf("%d. %.3LF\n",m,cl);
			m++;
		}
		
	}
	return 0;
} 
