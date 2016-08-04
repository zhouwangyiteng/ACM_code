#include<stdio.h>
#include<queue>
#include<iostream>
#include<string.h>
using namespace std;

struct Map
{
	int x,y,step;
}s;
int m,n;
bool visit[21][21];
priority_queue<Map>q;
char map[21][21];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

bool operator< (Map n1,Map n2)
{ 
    return n1.step>n2.step; 
}

int judge(Map p)
{
	if(p.x<0 || p.x>=m || p.y<0 || p.y>=n || map[p.x][p.y]=='*')
		return 1;
	return 0;
}

int direction(Map now,Map next)
{//判断方向，需要与上面写的方向一致
	int re;
	if(map[next.x][next.y]=='|')
		re=1;
	else
		re=0;
	re+=now.step%2;
	return re%2;
}

int BFS()
{
	Map now,next;
	while(!q.empty())
	{
		now=q.top();
		q.pop();
		int i;
		if(map[now.x][now.y]=='T')
			return now.step;
		for(i=0;i<4;i++)
		{
			next.x=now.x+dir[i][0];
			next.y=now.y+dir[i][1];
			next.step=now.step+1;
			if(judge(next) || visit[next.x][next.y])
				continue;
			else if(map[next.x][next.y]=='.' || map[next.x][next.y]=='T')
			{
				visit[next.x][next.y]=1;
				q.push(next);
				continue;
			}
			else
			{
				if(direction(now,next)!=(i%2))
					next.step++;
				next.x+=dir[i][0];
				next.y+=dir[i][1];
				if(judge(next) || visit[next.x][next.y])
					continue;
				else
				{
					visit[next.x][next.y]=1;
					q.push(next);
				}
			}
		}
	}
	return 0;
}

int main()
{
	int i,j;
	while(~scanf("%d%d",&m,&n))
	{
		while(!q.empty())
			q.pop();
		getchar();
		memset(visit,0,sizeof(visit));
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%c",&map[i][j]);
				if('S'==map[i][j])
				{
					s.x=i;
					s.y=j;
					s.step=0;
					q.push(s);
				}
			}
			getchar();
		}
		printf("%d\n",BFS());
	}
	return 0;
}