/*************************************************************************
	> File Name: shuoj1584.cpp
	> Author:
	> Mail:
	> Created Time: 2017年02月13日 星期一 20时32分50秒
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

int n;
LL ans;

int main()
{
    while(cin>>n)
    {
        ans = (pow(n, 10) + 5 * pow(n, 6) + 4 * pow(n, 2)) / 10;
        cout<<ans<<endl;
    }

    return 0;
}

