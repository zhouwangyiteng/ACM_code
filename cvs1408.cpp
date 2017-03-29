/*************************************************************************
	> File Name: cvs1408.cpp
	> Author:
	> Mail:
	> Created Time: 2017年03月29日 星期三 21时04分18秒
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
#include <fstream>
#include <functional>
#include <iomanip>
#include <cstdlib>
#define X first
#define Y second
#define LL long long
#define INF 0x3f3f3f3f
#define N 3005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

int n,k;
int a[N],b[N];
int f[N],g[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        scanf("%d",b+i);
    for(int i=1;i<=n;i++){
        k=0;
        for(int j=1;j<=n;j++){
            if(a[i]==b[j])
                if(f[k]+1>f[j]){
                    f[j]=f[k]+1;
                    g[j]=k;
                }
            if(a[i]>b[j])
                if(f[k]<f[j])
                    k=j;
        }
    }
    k=0;
    for(int i=1;i<=n;i++)
        if(f[k]<f[i])
            k=i;
    cout<<f[k]<<endl;

    return 0;
}

