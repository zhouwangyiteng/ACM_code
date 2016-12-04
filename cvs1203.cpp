/*************************************************************************
	> File Name: cvs1203.cpp
	> Author:
	> Mail:
	> Created Time: 2016年12月04日 星期日 12时01分44秒
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

double a,b;

int main()
{
    cin>>a>>b;
    if(abs(a-b)<=1e-8)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    return 0;
}

