/*************************************************************************
	> File Name: cvs1029.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年10月10日 星期一 22时21分29秒
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
#define N 30
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int n;
string pre,back;

int main()
{
	cin>>pre;
	cin>>back;
	n=0;
	for(int i=1;i<pre.size();i++)
		for(int j=0;j<back.size()-1;j++)
			if(pre[i]==back[j]&&pre[i-1]==back[j+1])
				n++;
	cout<<(1<<n)<<endl;

	return 0;
}

