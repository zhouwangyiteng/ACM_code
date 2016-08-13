/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-08-13 22:29:03

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
#define N 2500
#define M 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
    int val,x,y;
    node(){};
    node(int a,int b,int c):val(a),x(b),y(c){};
};

node nut[N];
int m,n,k,cnt,p;

bool cmp(node a,node b)
{
    return a.val>b.val;
}

int dist(node a,node b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        p=1;
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&cnt);
                if(cnt>0)
                    nut[p++]=node(cnt,i,j);
            }
        cnt=0;
        sort(nut+1,nut+p,cmp);
        nut[0]=node(0,0,nut[1].y);
        for(int i=1;i<p;i++)
        {
            if(k>=1+dist(nut[i],nut[i-1])+dist(nut[i],node(0,0,nut[i].y)))
            {
                cnt+=nut[i].val;
                k=k-1-dist(nut[i],nut[i-1]);
            }
            else
                break;
        }
        cout<<cnt<<endl;
    }


    return 0;
}

