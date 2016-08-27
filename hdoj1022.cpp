/*************************************************************************
	> File Name: hdoj1022.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月27日 星期六 14时09分35秒
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

stack<char> stk;
string str1,str2,ans;
int n,yes;

int main()
{
	while(cin>>n>>str1>>str2)
	{
		while(!stk.empty())
			stk.pop();
		ans="";
		int j=0;
		for(int i=0;i<n;)
		{
			stk.push(str1[i++]);
			ans+="in\n";
			while(!stk.empty()&&stk.top()==str2[j])
			{
				stk.pop();
				ans+="out\n";
				j++;
			}
		}
		for(;j<n;j++)
		{
			if(stk.top()!=str2[j])
				break;
			ans+="out\n";
			stk.pop();
		}
		if(j<n)
			cout<<"No.\nFINISH\n";
		else
		{
			cout<<"Yes."<<endl;
			cout<<ans;
			cout<<"FINISH"<<endl;
		}
	}

	return 0;
}

