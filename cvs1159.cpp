/*************************************************************************
	> File Name: cvs1159.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月21日 星期三 22时18分56秒
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
#define LL long long
#define INF 0x3f3f3f3f
#define N 2005
#define M 4000000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int li[2001]={0},ri[2001]={0},hi[2001]={0},a[2001][2001]={0};

int main()
{
	int n,i,j,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	 	for(j=1;j<=n;++j)
	   		scanf("%d",&a[i][j]);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
	 		if(a[i][j]==0) 
	 			++hi[j];
	  		else 
	  			hi[j]=0;
	  		li[j]=ri[j]=j;
	    }
	    for(j=2;j<=n;++j)
	     	if(a[i][j]==0)
	        	while(hi[li[j]-1]>=hi[j])
	          		li[j]=li[li[j]-1];
		for(j=n-1;j>=1;--j)
	  		if(a[i][j]==0)
	        	while(hi[ri[j]+1]>=hi[j])
	          		ri[j]=ri[ri[j]+1];
	    for(j=1;j<=n;++j)
	     	if(a[i][j]==0)
	       		ans=max(ans,(ri[j]-li[j]+1)*hi[j]);
	}
	cout<<ans<<endl;

}

