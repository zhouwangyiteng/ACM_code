/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-11-02 14:28:07

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
#define N 25
#define M 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,icase,flag;
int w[N];
int c,c2;
int x[N],bestx[N];
int cw,bestw,r;

void backtrack1(int i)
{
    if(i>n)
    {
        if(cw>bestw)
            bestw=cw;
        return;
    }
    r-=w[i];
    if(cw+w[i]<=c)
    {
        x[i]=1;
        cw+=w[i];
        backtrack1(i+1);
        cw-=w[i];
    }
    if(cw+r>bestw)
    {
        x[i]=0;
        backtrack1(i+1);
    }
    r+=w[i];
}

void backtrack2(int i)
{
    if(flag)
        return;
    if(i>n)
    {
        if(cw==bestw)
        {
            for(int j=1;j<=n;j++)
                bestx[j]=x[j];
            flag=1;
        }
        return;
    }
    r-=w[i];
    if(cw+w[i]<=c)
    {
        x[i]=1;
        cw+=w[i];
        backtrack2(i+1);
        cw-=w[i];
    }
    x[i]=0;
    backtrack2(i+1);
    r+=w[i];
}

int main()
{
    icase=0;
    while(cin>>n)
    {
        r=0;
        for(int i=1;i<=n;i++)
        {
            cin>>w[i];
            r+=w[i];
        }
        cin>>c>>c2;
        bestw=-1;
        backtrack1(1);
        flag=0;
        cw=0;
        CLR(x,0);
        backtrack2(1);

        printf("Case %d\n",++icase);
        if(r-bestw>c2)
            cout<<"No"<<endl;
        else
        {
            cout<<bestw<<' ';
            for(int i=1;i<=n;i++)
                cout<<bestx[i];
            cout<<endl;
        }
    }

    return 0;
}

