/*************************************************************************
	> File Name: cvs1202.cpp
	> Author:
	> Mail:
	> Created Time: 2016年12月04日 星期日 11时55分36秒
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
#include <functional>
#include <iomanip>
#include <cstdlib>
#define X first
#define Y second
#define LL long long
#define INF 0x3f3f3f3f
#define N 150005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

int n,a,SUM;

int main()
{
    cin>>n;
    SUM=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        SUM+=a;
    }
    cout<<SUM<<endl;

    return 0;
}

