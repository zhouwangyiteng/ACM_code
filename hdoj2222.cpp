/*************************************************************************
	> File Name: hdoj2222.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月28日 星期四 10时49分55秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
#define X first
#define Y second
#define ll long long
#define INF 0x3f3f3f3f
#define N 500010
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct Trie
{
	int next[N][26],fail[N],end[N];
	int root,L;
	int newnode()
	{
		for(int i=0;i<26;i++)
			next[L][i]=-1;
		end[L++]=0;
		return L-1;
	}
	void init()
	{
		L=0;
		root=newnode();
	}
	void insert(char buf[])
	{
		int len=strlen(buf);
		int now=root;
		for(int i=0;i<len;i++)
		{
			if(next[now][buf[i]-'a']==-1)
				next[now][buf[i]-'a']=newnode();
			now=next[now][buf[i]-'a'];
		}
		end[now]++;
	}
	void build()
	{
		queue<int> Q;
		fail[root]=root;
		for(int i=0;i<26;i++)
			if(next[root][i]==-1)
				next[root][i]=root;
			else
			{
				fail[next[root][i]]=root;
				Q.push(next[root][i]);
			}
		while(!Q.empty())
		{
			int now=Q.front();
			Q.pop();
			for(int i=0;i<26;i++)
				if(next[now][i] == -1)
	                next[now][i] = next[fail[now]][i];
	            else
	            {
	                fail[next[now][i]] = next[fail[now]][i];
	                Q.push(next[now][i]);
	            }
		}
	}
	int query(char buf[])
	{
		int len=strlen(buf);
		int now=root;
		int res=0;
		for(int i=0;i<len;i++)
		{
			now=next[now][buf[i]-'a'];
			int temp=now;
			while(temp!=root)
			{
				res+=end[temp];
				end[temp]=0;
				temp=fail[temp];
			}
		}
		return res;
	}
	void debug()
    {
        for(int i = 0;i < L;i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],end[i]);
            for(int j = 0;j < 26;j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }
};
 
char buf[1000010];
Trie ac;

int main()
{
	int T;
	int n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ac.init();
		for(int i=0;i<n;i++)
		{
			scanf("%s",buf);
			ac.insert(buf);
		}
		ac.build();
		scanf("%s",buf);
		printf("%d\n",ac.query(buf));
	}

	return 0;
}

