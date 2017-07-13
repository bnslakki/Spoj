#include <stdio.h>
#include <math.h>
 
void solve(int x, int y){
	if(y > x)printf("0\n");
	else if(!x && !y)printf("-1\n");
	else if(x == y)printf("-1\n");
	else{
		int ans = 0;
		int n = x - y;
		for(int i = 1; i <= sqrt(n); i++){
			if(n % i == 0){
				if(n / i == i){
					if(i > y)
					ans++;
				}
				else {
					if(i > y)ans++;
					if(n / i > y)ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}
int main(){
	int t, x, y;
	for(scanf("%d", &t); t--;){
		scanf("%d %d",&x,&y);
		solve(x, y);
	}
} 
