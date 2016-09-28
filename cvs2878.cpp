/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-09-28 09:53:49

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
#define N 10000000
#define M 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

LL a,b;

int main()
{
    scanf("%lld%lld",&a,&b);
    if(a%5==0||b%5==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}

