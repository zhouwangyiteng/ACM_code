/*************************************************************************
	> File Name: A.cpp
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

int a,b,c,t;

int main()
{
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        cout<<(a/2-c/4+b)<<endl;
    }

    return 0;
}

