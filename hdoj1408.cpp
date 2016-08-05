/*************************************************************************
	> File Name: hdoj1408.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月05日 星期五 10时13分01秒
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
using namespace std;
#define X first
#define Y second
#define ll long long
#define INF 0x3f3f3f3f
#define N 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))


int main(){
    double vul,d;
    while(cin>>vul>>d){
        double step=vul/d;
        int add;
        if(step-(int)step<1e-6)  
            add=0;
        else
            add=1;
        int v=(int)step+add;
        int i=1,sum=0;
        int stop=0;
        while(sum<v){
            sum+=i;
            i++;
            if(sum<v)
                stop++;
        }
        cout<<v+stop<<endl;
    }
    return 0;
}

