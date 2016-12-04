/*************************************************************************
	> File Name: cvs1201.cpp
	> Author:
	> Mail:
	> Created Time: 2016年12月04日 星期日 11时50分36秒
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

int n,a,nmax,nmin;

int main()
{
    cin >> n;
    cin>>nmax;
    nmin = nmax;
    for(int i=1;i<n;i++)
    {
        cin>>a;
        if(a>nmax)
            nmax = a;
        if(a<nmin)
            nmin = a;
    }
    cout<<nmin  << ' '<<nmax<<endl;

    return 0;
}

