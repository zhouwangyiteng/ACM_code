/*************************************************************************
	> File Name: BEGIN-4.cpp
	> Author:
	> Mail:
	> Created Time: 2017年02月13日 星期一 18时35分20秒
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

int n;
int ans;
int a1, a2, a3;

int main()
{
    cin>>n;
    a1 = a2 = a3 = 1;
    for(int i=3;i<=n;i++)
    {
        a3 = a2+a1;
        a1=a2%M;
        a2=a3%M;
    }
    cout<<a3%M<<endl;

    return 0;
}

