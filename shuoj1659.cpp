/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-11-02 08:34:45

 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <set>
#include <bitset>
using namespace std;
#define X first
#define Y second
#define LL long long
#define INF 0x3f3f3f3f
#define N 10
#define M 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
    int x,y,step;
    node(){};
    node(int a,int b,int c):x(a),y(b),step(c){};
};
queue<node> que;
int vis[N][N];
int dir[8][2]={1,2,2,1,-1,-2,-2,-1,1,-2,-1,2,2,-1,-2,1};
int sx,sy,ex,ey;
int n,ans;
string str1,str2;

void bfs()
{
    vis[sx][sy]=1;
    que.push(node(sx,sy,0));
    node q;
    while(!que.empty())
    {
        q=que.front();
        que.pop();
        if(q.x==ex&&q.y==ey)
        {
            ans=q.step;
            return;
        }
        for(int i=0;i<8;i++)
        {
            int tx=q.x+dir[i][0];
            int ty=q.y+dir[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=n&&!vis[tx][ty])
            {
                vis[tx][ty]=1;
                que.push(node(tx,ty,q.step+1));
            }
        }
    }
}

int main()
{
    while(cin>>str1>>str2)
    {
        sx=(int)(str1[0]-'a')+1;
        sy=(int)(str1[1]-'0');
        ex=(int)(str2[0]-'a')+1;
        ey=(int)(str2[1]-'0');
        n=8;
        CLR(vis,0);
        while(!que.empty())
            que.pop();
        ans=0;
        bfs();
        cout<<str1<<"==>"<<str2;
        printf(": %d moves\n",ans);
    }

    return 0;
}

