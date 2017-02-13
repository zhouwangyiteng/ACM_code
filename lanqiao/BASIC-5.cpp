/*************************************************************************
	> File Name: BASIC-5.cpp
	> Author:
	> Mail:
	> Created Time: 2017年02月13日 星期一 19时06分39秒
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
#define N 1005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

int a[N];
int n;
int num;
int ans;

int main()
{
    cin>>n;
    ans = -1;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>num;
    for(int i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            ans=i+1;
            break;
        }
    }
    cout<<ans<<endl;


    return 0;
}

