/*************************************************************************
	> File Name: poj1852.cpp
	> Author:
	> Mail:
	> Created Time: 2017年03月25日 星期六 21时16分04秒
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
#define N 1000005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

int n, t, len;
int maxn, minn;
int a[N];

int main()
{
    cin>>t;
    while(t--){
        cin>>len>>n;
        maxn=-1;
        for(int i=0;i<n;i++){
            scanf("%d",a+i);
            if(a[i]>maxn)
                maxn=a[i];
            if(len-a[i]>maxn)
                maxn=len-a[i];
        }
        sort(a,a+n);
        minn = INF;
        for(int i=0;i<n-1;i++){
            if(a[i]<minn && len-a[i+1]<minn)
                minn = max(a[i], len-a[i+1]);
        }
        if(a[n-1]<minn)
            minn=a[n-1];
        cout<<minn<<" "<<maxn<<endl;
    }

    return 0;
}

