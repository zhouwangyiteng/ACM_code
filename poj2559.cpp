#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
struct Node
{
	int startPos;
	long long height;
}node;

stack<Node> stk;

int main()
{
	int n;
	while(scanf("%d", &n)==1)
	{
		long long a, ans=0;
		if(n==0) break;
		while(!stk.empty()) stk.pop();
		node.height=0;
		node.startPos=0;
		stk.push(node);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a);
			node.startPos=i;
			while(a<stk.top().height)
			{
				node=stk.top();
				stk.pop();
				long long temp=node.height*(i-node.startPos);
				if(temp>ans) ans=temp;
			}
			node.height=a;
			stk.push(node);
		}
		while(!stk.empty())
		{
			long long temp=stk.top().height*(n-stk.top().startPos);
			if(temp>ans) ans=temp;
			stk.pop();
		}
		cout<<ans<<endl;
		
	}    
    
	return 0;  
}    
