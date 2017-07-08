#include<bits/stdc++.h>
int main() 
{
int t;
scanf("%d",&t);
while(t--)
{
long long int t1,t2,arr[10][4]={
{0,0,0,0},
{1,1,1,1},
{2,4,8,6},
{3,9,7,1},
{4,6,4,6},
{5,5,5,5},
{6,6,6,6},
{7,9,3,1},
{8,4,2,6},
{9,1,9,1},
};
long long int a,b;
scanf("%lld%lld",&a,&b);
if(b==0&&a==0)
printf("1\n");
else if(b==0&&a!=0)
printf("1\n");
else if(a==0&&b!=0)
printf("0\n");
else
{
t1=a%10;
t2=(b%100)%4;
if(t2==0)
{
printf("%lld\n",arr[t1][3]);
}
else printf("%lld\n",arr[t1][t2-1]);
}
}return 0;
} 
