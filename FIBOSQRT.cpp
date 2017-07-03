#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
 
ll M;
void mul(ll mat1[3][3], ll mat2[3][3]){
	ll mat3[3][3];
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			mat3[i][j] = 0;
			for (int k=0;k<3;k++){
				mat3[i][j]=(mat3[i][j]+mat1[i][k]*mat2[k][j]+M)%M;
			}
		}
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			mat1[i][j] = mat3[i][j];
}
void power(ll mat[3][3],ll n){
	if (!n||n==1)return;
	ll temp[3][3]={{2,2,-1},{1,0,0},{0,1,0}};
	power(mat,n>>1);
	mul(mat,mat);
	if(n&1)mul(mat,temp);
}
ll solve(ll n,ll a0,ll a1,ll a2){
	if(!n)return a0%M;
	if(n==1)return a1%M;
	if(n==2)return a2%M;
	ll mat[3][3]={{2,2,-1},{1,0,0},{0,1,0}};
	power(mat,n-2);
	ll ans=(a2*mat[0][0]+a1*mat[0][1]+a0*mat[0][2]+M)%M;
	return (ll)ans;
}
int main(){
	//read("t.txt");
	int t;
	ll a0,a1,n,a2;
	for(scanf("%d",&t);t--;){
		scanf("%lld%lld%lld%lld",&a0,&a1,&M,&n);
		a2=(a0+a1+2*sqrt(3+a0*a1));
		if(a2>=M)a2%=M;
		if(M==1)printf("0\n");
		else
		printf("%lld\n",solve(n,a0,a1,a2));
	}
}  
