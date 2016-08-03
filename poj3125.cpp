/*************************************************************************
	> File Name: poj3125.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月03日 星期三 21时13分25秒
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
#define N 105
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int que[N];
int ipos,imax,ihead,cnt,iposmax,inum;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d %d",&inum,&ipos);
		cnt=0;
		iposmax=-1;
		for(int i=0;i<inum;i++)
			scanf("%d",que+i);
		while(iposmax!=ipos)
		{
			ihead=(iposmax+1)%inum;
			imax=que[ihead];
			iposmax=ihead;
			for(int i=(ihead+1)%inum;i!=ihead;i=(i+1)%inum)
				if(que[i]>imax)
				{
					imax=que[i];
					iposmax=i;
				}
			cnt++;
			que[iposmax]=0;
		}
		cout<<cnt<<endl;
	}

	return 0;
}

