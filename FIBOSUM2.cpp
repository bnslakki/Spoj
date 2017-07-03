#include <bits/stdc++.h>
using namespace std;
 #include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace mp;
#define ll long long
const int mod = 1000000007;
 
ll pre_mat[32780][2][2],pre_mat2[32780][2][2];
 
inline ll scan()
    {
        ll z=0;
        char c;
        do{ c=getchar_unlocked(); } while(c<'0');
        for(;c>='0';c=getchar_unlocked()) z = (z<<3) + (z<<1) + (c&15);
        return z;
    }
 inline void pf(int n) {
  char stack[20];
  int top = 0;
  if(n == 0) {
    putchar_unlocked('0');
  } else {
    while(n > 0) {
      stack[top++] = n % 10 + '0';
      n /= 10;
    }
    while(top > 0) {
      putchar_unlocked(stack[--top]);
    }
  }
  putchar_unlocked('\n');
}
 
inline void mul(ll mat1[2][2],ll mat2[2][2])
{
	
	ll res[2][2] = { { 0 } };
 
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
			{
				res[i][j] = (res[i][j] + (mat1[i][k] * mat2[k][j]));
				if (res[i][j] >= mod)
					res[i][j] %= mod;
			}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			mat1[i][j] = res[i][j];
}
inline void multi(ll mat1[][2][2],ll mat2[][2][2],int I)
{
	
	ll res[2][2] = { { 0 } };
 
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
			{
				res[i][j] = (res[i][j] + (mat1[I][i][k] * mat2[I][k][j]));
				if (res[i][j] >= mod)
					res[i][j] %= mod;
			}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			mat1[I][i][j] = res[i][j];
}
void pow(ll mat[2][2],ll n,ll matcp[2][2])
{
	if(!n){
		mat[0][0]=1,mat[0][1]=0,mat[1][0]=0,mat[1][1]=1;
		return ;
	}
	if(n==1)return ;
	ll mat2[2][2];
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			mat2[i][j]=matcp[i][j];
	pow(mat,n>>1,matcp);
	mul(mat,mat);
	if(n&1)mul(mat,mat2);
}
inline int mul(ll a,ll b)
{
	cpp_int t=(cpp_int)(a)*(cpp_int)(b);
	t%=mod;
	return (int)t;
}
 
int modulo(ll a,ll b)
{
	ll x=1,y=a;
	while(b>0){
		if(b&1)x=mul(x,y);
		y=mul(y,y);
		b>>=1;
	}
	return x;
}
inline int MMI(ll a,ll b)
{
	ll temp=modulo(b,mod-2);
	//printf("%lld\n",temp);
	temp=(mod+mul(a,temp));
	if(temp>=mod)temp%=mod;
	return temp;
}
void pre()
{
	ll A[2][2]={{1,1},{1,0}};
	ll B[2][2]={{1,1},{1,0}};
	pre_mat[0][0][0]=1;
	pre_mat[0][0][1]=0;
	pre_mat[0][1][0]=0;
	pre_mat[0][1][1]=1;
	
	pre_mat[1][0][0]=1;
	pre_mat[1][0][1]=1;
	pre_mat[1][1][0]=1;
	pre_mat[1][1][1]=0;
	for(int i=2;i<=32770;i++)
	{
		mul(B,A);
		pre_mat[i][0][0]=B[0][0];
		pre_mat[i][0][1]=B[0][1];
		pre_mat[i][1][0]=B[1][0];
		pre_mat[i][1][1]=B[1][1];
	}
	ll det=0;
	for(int i=0;i<32770;i++)
	{
		pre_mat2[i][0][0]=pre_mat[i][0][0]-1;
		pre_mat2[i][0][1]=(-1)*pre_mat[i][0][1];
		pre_mat2[i][1][0]=(-1)*pre_mat[i][1][0];
		pre_mat2[i][1][1]=pre_mat[i][1][1]-1;
		
		swap(pre_mat2[i][0][0],pre_mat2[i][1][1]);
		
		det=pre_mat2[i][0][0]*pre_mat2[i][1][1]-pre_mat2[i][0][1]*pre_mat2[i][1][0];
		
		if(det<0){
			det*=-1;
			pre_mat2[i][0][0]=MMI((-1)*pre_mat2[i][0][0],det);
			pre_mat2[i][0][1]=MMI((-1)*pre_mat2[i][0][1],det);
			pre_mat2[i][1][0]=MMI((-1)*pre_mat2[i][1][0],det);
			pre_mat2[i][1][1]=MMI((-1)*pre_mat2[i][1][1],det);
		}
		else{
			pre_mat2[i][0][0]=MMI(pre_mat2[i][0][0],det);
			pre_mat2[i][0][1]=MMI(pre_mat2[i][0][1],det);
			pre_mat2[i][1][0]=MMI(pre_mat2[i][1][0],det);
			pre_mat2[i][1][1]=MMI(pre_mat2[i][1][1],det);
		}
		
		multi(pre_mat2,pre_mat,i);
		
	}
}
int main()
{
	pre();
	//freopen("t.txt","r",stdin);
	int t;
	t=scan();
	while(t--)
	{
		int c,k;
		ll n;
		c=scan();
		k=scan();
		n=scan();
		ll B[2][2],C[2][2],D[2][2];
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
			{
				C[i][j]=pre_mat[c][i][j];
				D[i][j]=pre_mat[k][i][j];
				B[i][j]=pre_mat2[k][i][j];
			}
		
		pow(D,n,D);
		D[0][0]=(D[0][0]-1+mod);
		D[1][1]=(D[1][1]-1+mod);
		
		mul(C,D);
		mul(C,B);
		pf(C[1][0]);
	}
}  
