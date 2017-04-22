/*************************************************************************
	> File Name: B.cpp
	> Author:
	> Mail:
	> Created Time: 2017年04月22日 星期六 14时09分26秒
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
#define N 105
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

int t,n;
int a[N];

int main()
{
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        if(n<10 || n>13 || a[0]!=1){
            cout<<"No"<<endl;
            continue;
        }
        int f3=0;
        int f4=1;
        for(int i=0;i<n-1;i++){
            if(a[i]==1)
                f3++;
            if(a[i+1]-a[i]>2&&i!=n-2)
                f4=0;
        }
        if(a[n-1]==1)
            f3++;
        if(f3>=2&&f4)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}

