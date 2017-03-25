/*************************************************************************
	> File Name: shuoj2023.cpp
	> Author:
	> Mail:
	> Created Time: 2017年03月25日 星期六 21时41分12秒
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
#define N 1000005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

int n,a,cnt,num;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(cnt==0){
            num=a;
            cnt++;
        }
        else{
            if(a==num)
                cnt++;
            else
                cnt--;
        }
    }
    printf("%d\n", num);

    return 0;
}

