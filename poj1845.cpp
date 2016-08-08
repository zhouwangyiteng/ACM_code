/*************************************************************************
	> File Name: poj1845.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月08日 星期一 10时27分36秒
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
#define N 10005
#define MOD 9901
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

bool prime[N];
int p[N];
int cnt;

void isprime()
{
    cnt = 0;
    memset(prime,true,sizeof(prime));
    for(int i=2; i<N; i++)
    {
        if(prime[i])
        {
            p[cnt++] = i;
            for(int j=i+i; j<N; j+=i)
                prime[j] = false;
        }
    }
}

LL power(LL a,LL b)
{
    LL ans = 1;
    a %= MOD;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % MOD;
            b--;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}

LL sum(LL a,LL n)
{
    if(n == 0) return 1;
    LL t = sum(a,(n-1)/2);
    if(n & 1)
    {
        LL cur = power(a,(n+1)/2);
        t = (t + t % MOD * cur % MOD) % MOD;
    }
    else
    {
        LL cur = power(a,(n+1)/2);
        t = (t + t % MOD * cur % MOD) % MOD;
        t = (t + power(a,n)) % MOD;
    }
    return t;
}

void Solve(LL A,LL B)
{   
    LL ans = 1;
    for(int i=0; p[i]*p[i]<= A; i++)
    {
        if(A % p[i] == 0)
        {
            int num = 0;
            while(A % p[i] == 0)
            {
                num++;
                A /= p[i];
            }
            ans *= sum(p[i],num*B) % MOD;
            ans %= MOD;
        }
    }

    if(A>1){
        ans*=sum(A,B);
        ans%=MOD;
    }
   
    cout<<ans<<endl;
}

int main()
{
    LL A,B;
    isprime();
    while(cin>>A>>B)
        Solve(A,B);
    return 0;
}
