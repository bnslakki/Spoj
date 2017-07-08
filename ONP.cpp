#include<bits/stdc++.h>
char arr[500];
char res[500];
 
int top=0,k=0;
char temp;
void push(char n)
{
	arr[top]=n;
	top++;
}
void pop()
{
	 temp=arr[top-1];
	top--;
}
bool pri(char c1,char c2)
{
	if((c2=='*'||c2=='/')&&(c1=='+'||c1=='-'))
	return true;
	else if((c2=='^')&&(c1=='+'||c1=='-'||c1=='*'))
	return true;
	else
	return false;
}
bool isempty()
{
	if(top==0)
	return true;  // true when stack is empty 
	else
	return false;
}
/*void print()
{
	for(int i=0;i<=top;i++)
	{
		printf("%c ",arr[i]);
	}
	printf("\n");
}*/
//////////////////
void convert(char arr1[])
{
	int f=0;
	int ln=strlen(arr1);
	for(int i=0;i<ln;i++)
	{
		if(arr1[i]>='a'&&arr1[i]<='z')
		{
			res[k]=arr1[i];
			k++;
		}
		else if(arr1[i]=='+'||arr1[i]=='-'||arr1[i]=='*'||arr1[i]=='/'||arr1[i]=='^')
		{
			while(isempty()==false&&pri(arr[top-1],arr1[i])==false&&arr[top-1]!='(')
			{
				pop();
				res[k]=temp;
				k++;
			}
			push(arr1[i]);
		}
		else if(arr1[i]=='(')
		{
			push(arr1[i]);
		}
		else if(arr1[i]==')')
		{
			while(isempty()==false&&arr[top-1]!='(')
			{
				pop();
				res[k]=temp;
				k++;
			}
			pop();
		}
	}
	while(isempty()==false)
	{
		pop();
		res[k]=temp;
		k++;
	}
}
//////////////////
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int f=0;
	char arr1[500];
	scanf("%s",arr1);
 	convert(arr1);
 	for(int i=0;i<k&&res[i]!=0;i++)
 	printf("%c",res[i]);
 	printf("\n");
 	for(int i=0;i<k;i++)
     res[i]=0;
     top=0;
     k=0;
 	}
	return 0;
} 
