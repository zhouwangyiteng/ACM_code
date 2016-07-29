/*************************************************************************
	> File Name: poj1200.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月29日 星期五 19时56分06秒
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
#define N 16000005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int hash[N];
int n,nc,cnt;
char str[1000000];
map<char,int> ch;
ll num;


int main()
{
	while(scanf("%d %d",&n,&nc)!=EOF)
	{
		scanf("%s",str);
		ch.clear();
		CLR(hash,0);
		int type=1;
		cnt=0;
		int len=strlen(str);
		for(int i=0;i<=len-n;i++)
		{
			num=0;
			for(int j=i+n-1;j>=i;j--)
			{
				if(ch[str[j]])
					num+=ch[str[j]]-1;
				else
				{
					ch[str[j]]=type;
					num+=type-1;
					type++;
				}
				num*=nc;
			}
			num/=nc;
			if(!hash[num])
			{
				cnt++;
				hash[num]=1;
			}
		}
		cout<<cnt<<endl;
	}

	return 0;
}

