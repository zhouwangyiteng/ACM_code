#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>//sortËùÔÚ¿â£¬ÅÅÐòÓÃ
using namespace std;
#define MAXN 110
int stack[MAXN];
char str[MAXN];
int p,q,r,s,t;

void tryIt()
{
	int a, b, top=0;
	int len=strlen(str);
	for(int i=len-1;i>=0;i--)
	{
		switch(str[i])
		{
		case 'p':stack[top++]=p;break;
		case 'q':stack[top++]=q;break;
		case 'r':stack[top++]=r;break;
		case 's':stack[top++]=s;break;
		case 't':stack[top++]=t;break;
		case 'K':
			a=stack[--top];
			b=stack[--top];
			stack[top++]=a&&b;
			break;
		case 'A':
			a=stack[--top];
			b=stack[--top];
			stack[top++]=a||b;
			break;
		case 'C':
			a=stack[--top];
			b=stack[--top];
			stack[top++]=(!a)||b;
			break;
		case 'N':
			a=stack[--top];
			stack[top++]=(!a);
			break;
		case 'E':
			a=stack[--top];
			b=stack[--top];
			stack[top++]=(a&&b)||(!a&&!b);
		}
	}
}
bool solve()
{
	for(p=0;p<2;p++)
		for(q=0;q<2;q++)
			for(r=0;r<2;r++)	
				for(s=0;s<2;s++)
					for(t=0;t<2;t++)
					{
						tryIt();
						if(stack[0]==0) return false;
					}
	return true;	
}

int main()
{
    while(cin>>str)
    {
		if(str[0]=='0') break;
		if(solve()) cout<<"tautology"<<endl;
		else cout<<"not"<<endl;
	}
    
	return 0;  
}    
