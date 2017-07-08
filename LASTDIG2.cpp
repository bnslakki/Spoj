#include<iostream>
#include<cstring>
using namespace std;
int u(string s){int c=0;while(s[c]!='\0')c++;return c;}int main(){int T;cin>>T;while(T--){long long int f,g,b,t,a,p[10][4]={{0,0,0,0},{1,1,1,1},{2,4,8,6},{3,9,7,1},{4,6,4,6},{5,5,5,5},{6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1},};string s;cin>>s;char l;l=s[u(s)-1];t=l;if(l=='1')a=t-48;if(l=='2')a=t-48;if(l=='3')a=t-48;if(l=='4')a=t-48;if(l=='5')a=t-48;if(l=='6')a=t-48;if(l=='7')a=t-48;if(l=='8')a=t-48;if(l=='9')a=t-48;if(l=='0')a=t-48;cin>>b;if(b==0&&a!=0)cout<<"1"<<endl;else if(a==0&&b!=0)cout<<"0"<<endl;else{f=a%10;g=(b%100)%4;if(g==0)cout<<p[f][3]<<endl;else cout<<p[f][g-1]<<endl;}}return 0;} 
