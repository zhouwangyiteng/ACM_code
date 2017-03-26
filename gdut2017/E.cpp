/*************************************************************************
	> File Name: E.cpp
	> Author:
	> Mail:
	> Created Time: 2017年03月26日 星期日 14时01分43秒
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
#define N 50
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

int t,k,n;

int log2(int a){
    float tmp = log(a) / log(2);
    return (int)tmp;
}

int main()
{
    cin>>t;
    while(t--){
        cin>>n>>k;
        k--;
        while(k--){
            int tmp = log2(n);
            n = n-pow(2,tmp);
            if(n==0)
                break;
        }
        int tmp = log2(n);
        int ans;
        if(pow(2,tmp)==n)
            ans=0;
        else
            ans=pow(2,(tmp+1))-n;
        cout<<ans<<endl;
    }

    return 0;
}

