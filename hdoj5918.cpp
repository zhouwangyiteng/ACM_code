/*************************************************************************
	> File Name: hdoj5918.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年10月06日 星期四 19时16分03秒
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
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

const int N = 1000005;  
const int M = 100005;  
const int inf = 1000000007;  
const int mod = 101;  
int c[N],s[N],s2[N],n,m,p;  
void getnext()  
{  
    int i=0,j=-1,l=m;  
    c[0]=-1;  
    while(i<l)  
        if(j==-1||s2[i]==s2[j])  
            c[++i]=++j;  
        else  
            j=c[j];  
}  
int kmp(int x)  
{  
    int i=x,j=0,k=0,len=n,l=m;  
    while(i<len)  
    {  
        if(j==-1|s[i]==s2[j])  
            i+=p,j++;  
        else  
            j=c[j];  
        if(j==l)  
            k++,j=c[j];  
    }  
    return k;  
}  
int main()  
{  
    int t,i,ans,k=1;  
    scanf("%d",&t);  
    while(t--)  
    {  
        ans=0;  
        scanf("%d%d%d",&n,&m,&p);  
        for(i=0;i<n;i++)  
            scanf("%d",&s[i]);  
        for(i=0;i<m;i++)  
            scanf("%d",&s2[i]);  
        getnext();  
        for(i=0;i<p&&i<n;i++)  
            ans+=kmp(i);  
        printf("Case #%d: %d\n",k++,ans);  
    }  
    return 0;  
}  