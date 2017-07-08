#include<bits/stdc++.h>
using namespace std;
int main()
{
	int cp,tp,cbs,ws;
	char wd;
	cin>>cp>>tp>>cbs>>ws>>wd;
	//scanf("%d%d%d%d%c",&cp,&tp,&cbs,&ws,&wd);
	//gets(wd);
	if(cp==tp)
	{
		printf("0.000000");
	}
	else
	{
		
		if(cp<tp&&wd=='L')
		{
			int relspd=cbs-ws;
			if(relspd<=0)
			{
				printf("Impossible");
			}
			else
			{
				int dis=tp-cp;
				double time=(dis+0.0)/relspd;
				printf("%lf",time);
			}
		}
		else if(cp<tp&&wd=='R')
		{
			int relspd=cbs+ws;
				int dis=tp-cp;
				double time=(dis+0.0)/relspd;
				printf("%lf",time);
		}
		else if(cp>tp&&wd=='L')
		{
			int relspd=cbs+ws;
				int dis=cp-tp;
				double time=(dis+0.0)/relspd;
				printf("%lf",time);
		}
		else if(cp>tp&&wd=='R')
		{
			int relspd=cbs-ws;
			if(relspd<=0)
			{
				printf("Impossible");
			}
			else
			{
				int dis=tp-cp;
				double time=(dis+0.0)/relspd;
				printf("%lf",time);
			}
		}
	}
	return 0;
} 
