/*

POJ 2632
模拟
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
const int MAXN=110;
int map[MAXN][MAXN];
struct Node
{
    int x,y;
    int dir;//0,1,2,3:N,W,S,E
}rob[MAXN];
int move[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
int main()
{
 //   freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdo);
    int T;
    int A,B;
    int N,M;
    char str[10];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&A,&B);
        scanf("%d%d",&N,&M);
        memset(map,0,sizeof(map));
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d",&rob[i].x,&rob[i].y);
            map[rob[i].x][rob[i].y]=i;
            scanf("%s",&str);
            if(str[0]=='N') rob[i].dir=0;
            else if(str[0]=='W') rob[i].dir=1;
            else if(str[0]=='S') rob[i].dir=2;
            else if(str[0]=='E') rob[i].dir=3;
        }
        int t1,t2;
        bool flag=false;
        while(M--)
        {
            scanf("%d%s%d",&t1,&str,&t2);
            if(flag)continue;//第一次相撞已经记录完了
            if(str[0]=='L')
            {
                rob[t1].dir+=t2;
                rob[t1].dir%=4;

            }
            else if(str[0]=='R')
            {
                rob[t1].dir-=t2;
                rob[t1].dir%=4;
                rob[t1].dir=(rob[t1].dir+4)%4;//化为正的
            }
            else
            {
                int x=rob[t1].x;
                int y=rob[t1].y;
                while(t2--)
                {
                    x=rob[t1].x;
                    y=rob[t1].y;
                    x+=move[rob[t1].dir][0];
                    y+=move[rob[t1].dir][1];
                    if(x<=0||x>A||y<=0||y>B)
                    {
                        printf("Robot %d crashes into the wall\n",t1);
                        flag=true;
                        break;
                    }
                    else if(map[x][y]!=0)
                    {
                        printf("Robot %d crashes into robot %d\n",t1,map[x][y]);
                        flag=true;
                        break;
                    }
                    else
                    {
                        map[x][y]=t1;
                        map[rob[t1].x][rob[t1].y]=0;
                        rob[t1].x=x;
                        rob[t1].y=y;
                    }
                }
            }

        }
        if(!flag)printf("OK\n");
    }
    return 0;
}
