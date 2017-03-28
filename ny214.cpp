/*************************************************************************
	> File Name: ny214.cpp
	> Author:
	> Mail:
	> Created Time: 2017年03月28日 星期二 21时33分55秒
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
#define N 100005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

int d[100001];
int a[100001];
int m;
void solve()
{
    fill(d, d + m, INF);
    for(int i = 0; i < m; ++i)
        *lower_bound(d, d + m, a[i]) = a[i];
    cout << lower_bound(d, d + m, INF) - d << endl;
}
int main()
{
    while(cin >> m){
        for(int i = 0; i < m; ++i)
            scanf("%d",a+i);
        solve();
    }
return 0;
}

