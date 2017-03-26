/*************************************************************************
    > File Name: D.cpp
    > Author:
    > Mail:
    > Created Time: 2017年03月26日 星期日 13时34分45秒
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
#define N 150005
#define M 10007
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

int t,n, num;
LL a[25];
LL cnt;

int main()
{
    a[1]=1;
    a[2]=2;
    a[3]=4;
    for(int i=4;i<21;i++){
        a[i]=a[i-1]+a[i-2]+a[i-3];
        a[i]%=M;
    }
    cin>>t;
    while(t--){
        cnt=1;
        cin>>n;
        for(int i=1;i<n;i++){
            scanf("%d",&num);
            cnt=(cnt * a[num])%M;
        }
        cout<<cnt%M<<endl;
    }

    return 0;
}

