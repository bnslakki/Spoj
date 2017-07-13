#include "bits/stdc++.h"
using namespace std;
 
const int MAXSIEVE = 1000006;
const int MAXSIEVEHALF = MAXSIEVE / 2;
const int MAXSQRT = 500;
 
char a[(MAXSIEVE>>4) + 2]; 
 
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7)))
 
int pr[78507];
 
void sieve(){ 
	memset(a, 255, sizeof(a)); 
	a[0] = 0xFE; 
	for(int i = 1; i < MAXSQRT; i++) 
		if (a[i>>3] & (1<<(i&7))) 
			for(int j = i+i+i+1;j < MAXSIEVEHALF; j += i+i+1) 
				a[j>>3] &= ~(1<<(j&7));
	int ct = 1;
	pr[0] = 2;
	for(int i = 3; i< MAXSIEVE; i+=2){
		if(isprime(i)){
			pr[ct++] = i;
		}
	}
}
int rem(char* s, int n){
	int ret = 0;
	for(int i = 0; s[i]; i++){
		ret = (ret * 10 + s[i] - '0') % n;
	}
	return ret;
}
int main(){
	//freopen("t.txt", "r", stdin);
	sieve();
	char s[110];
	int n, i;
	while(scanf("%s %d", s, &n)){
		if(s[0] == '0' && !n)break;
		for(i = 0; pr[i] < n; i++){
			if(!rem(s, pr[i]))break;
		}
		if(pr[i] >= n)printf("GOOD\n");
		else printf("BAD %d\n", pr[i]);
	}
} 
