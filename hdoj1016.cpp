#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 25
int primeNum[12]={2,3,5,7,11,13,17,19,23,29,31,37};
bool vis[MAXN];
vector<int> stk;
int n;

bool isPrime(int n)
{
	for(int i=0;i<12;i++)
		if(n==primeNum[i])
			return true;
	return false;
}

void dfs(int pre,int next)
{
	if(!isPrime(pre+next))
		return;
	if(stk.size()==n-1&&isPrime(next+1))
	{
		for(int i=0;i<n-1;i++)
			printf("%d ",stk[i]);
		cout<<next<<endl;
		return;
	}
	stk.push_back(next);
	vis[next]=true;
	for(int i=2;i<=n;i++)
		if(!vis[i])
			dfs(next,i);
	stk.pop_back();
	vis[next]=false;
	
}

int main()
{
	int icase=0;
	while(cin>>n)
	{
		cout<<"Case "<<++icase<<":"<<endl;
		if(n==1)
		{
			cout<<1<<endl<<endl;
			continue;
		}
		if(n&1)
		{
			cout<<endl;
			continue;
		}
		while(!stk.empty())
			stk.pop_back();
		memset(vis,false,sizeof(vis));
		stk.push_back(1);
		vis[1]=true;
		for(int i=2;i<=n;i++)
			dfs(1,i);
		cout<<endl;
	}    
    
	return 0;  
}    
