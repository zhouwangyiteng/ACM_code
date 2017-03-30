/*************************************************************************
	> File Name: cvs1536.cpp
	> Author:
	> Mail:
	> Created Time: 2017年03月30日 星期四 21时31分48秒
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

int dir[4][2]={0, 1, 1, 0, -1,0, 0, -1};

int r,c,cnt;
short m[N][N];
void dfs(int x,int y){
    m[x][y]=0;
    for(int i=0;i<4;i++){
        int dx=x+dir[i][0];
        int dy=y+dir[i][1];
        if(dx>=1&&dx<=r&&dy>=1&&dy<=c&&m[dx][dy]==1)
            dfs(dx,dy);
    }
}

int main()
{
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        getchar();
        for(int j=1;j<=c;j++){
            char ch;
            cin>>ch;
            // scanf("%c",&ch);
            if(ch=='#')
                m[i][j]=1;
            else
                m[i][j]=0;
        }
    }
    for(int i=1;i<=r;i++)
    {

        for(int j=1;j<=c;j++)

        {

            if(m[i][j]==0)

            {

                if(m[i+1][j]==1&&m[i][j+1]==1&&m[i+1][j+1]==1){cout<<"Bad placement."<<endl;return 0;}

                if(m[i+1][j]==1&&m[i][j-1]==1&&m[i+1][j-1]==1){cout<<"Bad placement."<<endl;return 0;}

                if(m[i-1][j]==1&&m[i][j+1]==1&&m[i-1][j+1]==1){cout<<"Bad placement."<<endl;return 0;}

                if(m[i-1][j]==1&&m[i][j-1]==1&&m[i-1][j-1]==1){cout<<"Bad placement."<<endl;return 0;}

            }

        }

    }
    cnt=0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(m[i][j]==1){
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<"There are "<<cnt<<" ships."<<endl;

    return 0;
}

