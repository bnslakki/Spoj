#include "bits/stdc++.h"
using namespace std;
 
char arr[10][10];
char s[82];
inline bool issafe(int r,int c,char num){
	for(int i=0;i<9;i++){
		if(arr[i][c]==num)return 0;
		if(arr[r][i]==num)return 0;
	}
	for(int row=r/3*3;row<(r/3+1)*3;row++)
        for (int col=c/3*3;col<(c/3+1)*3;col++)
            if(arr[row][col]==num)return 0;
	return 1;
}
inline bool solve() {
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(arr[i][j]=='.'){
				for(char k='1';k<='9';k++){
					if(issafe(i,j,k)){
						arr[i][j]=k;
						if(solve())return 1;
						arr[i][j]='.';
					}
				}
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	//freopen("t.txt","r",stdin);
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%s",s);
		int c=0;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				arr[i][j]=s[c++];
			}
		}
		solve();
		printf("Y\n");
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				printf("%c",arr[i][j]);
			}
		}
		printf("\n");
	}
} 
