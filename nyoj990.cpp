/*************************************************************************
	> File Name: nyoj990.cpp
	> Author:
	> Mail:
	> Created Time: 2017年03月27日 星期一 22时09分43秒
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
#define N 55
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

int n,cnt;
int a[N];

int main()
{
    while(cin>>n){
        cnt=0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        if(a[0]<0){
            for(int i=1;i<n;i++){
                if(a[i]>0&&(a[i]<-a[0]))
                    cnt++;
            }
            if(cnt>0){
                for(int i=0;i<n;i++)
                    if(a[i]<0&&(a[i]<a[0]))
                        cnt++;
            }
        }
        else{
            for(int i=1;i<n;i++){
                if(a[i]<0&&(-a[i]>a[0]))
                    cnt++;
            }
            if(cnt>0){
                for(int i=0;i<n;i++)
                    if(a[i]>0&&(a[i]<a[0]))
                        cnt++;
            }
        }
        cout<<++cnt<<endl;
    }

    return 0;
}

