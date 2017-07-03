#include<bits/stdc++.h>
int main()
{
	double v,h;
	while(scanf("%lf%lf",&v,&h))
	{
		if(v==-1&&h==-1)
		break;
		printf("%lf\n",(v/9.8)*sqrt((v*v)+(2*9.8*h)));
	}
	return 0;
} 
