/*************************************************************************
	> File Name: hdoj1286.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月22日 星期五 22时15分10秒
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
#define ll long long
#define INF 0x3f3f3f
#define MAXN 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int t,n;

int Euler(int n){  
    int res = n,i;  
  
    for(i=2;i * i <= n;i++)  
    if(n%i == 0){  
        n /=i ;  
        res = res - res/i;  
        while(n % i ==0)  
            n/=i;  
    }  
  
    if (n > 1)     
        res = res - res/n;   
    return res;  
}  

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<Euler(n)<<endl;
	}

	return 0;
}

