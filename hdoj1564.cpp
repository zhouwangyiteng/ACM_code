/*************************************************************************
	> File Name: hdoj1564.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月25日 星期四 16时54分46秒
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
#define N 100000
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int n;

int main()
{
	while(cin>>n,n)
	{
		if(n&1)
			cout<<"ailyanlu"<<endl;
		else
			cout<<"8600"<<endl;
	}

	return 0;
}

