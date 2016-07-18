#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 30

int g[MAXN][MAXN];
int vis[MAXN];
char word[100];
int flag;

void dfs(int x)
{
	if(x==(int)('m'-'a'))
	{
		flag=1;
		return;
	}
	for(int i=0;i<25;i++)
	{
		if(!flag&&!vis[i]&&g[x][i])
		{
			vis[i]=1;
			dfs(i);
			vis[i]=0;
		}
	}
	return;
}

int main()
{
	flag=0;
	memset(g,0,sizeof(g));
	memset(vis,0,sizeof(vis));
    while(scanf("%s",word)!=EOF)
    {
		if(strlen(word)==1&&word[0]=='0')
		{
			if(vis[1])
				dfs(1);
			if(flag)
				cout<<"Yes."<<endl;
			else
				cout<<"No."<<endl;
			flag=0;
			memset(g,0,sizeof(g));
			memset(vis,0,sizeof(vis));
		}
		else
		{
			int nlen=strlen(word);
			char a=word[0],b=word[nlen-1];
			int x=(int)(a-'a'),y=(int)(b-'a');
			if(!g[x][y])
				g[x][y]=1;
			if(a=='b')
				vis[1]=1;
		}
	}
    
	return 0;  
}    
