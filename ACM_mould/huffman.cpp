/*************************************************************************
	> File Name: huffman.cpp
	> Author:
	> Mail:
	> Created Time: 2016年11月01日 星期二 13时34分48秒
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
#define N 52
#define M 120
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

struct htnode
{
	int weight;
	int lchild, rchild;
};
struct node
{
	int num;
	int weight;
	friend bool operator < (node a, node b)
	{
	 	if(a.weight==b.weight)
	 		return a.num<b.num;
	 	else
	 		return a.weight>b.weight;
	 }
};
htnode tree[M];
priority_queue<node> que;
node p1,p2,p;
int t,n;
string strSet[N];

void buildTree(int root, string pat)
{
	if(tree[root].lchild==0&&tree[root].rchild==0)
	{
		strSet[root]=pat;
		return;
	}
	if(tree[root].lchild>0)
		buildTree(tree[root].lchild, pat+"0");
	if(tree[root].rchild>0)
		buildTree(tree[root].rchild, pat+"1");

}

int main()
{
	int icase=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		CLR(tree,0);
		while(!que.empty())
			que.pop();
		for(int i=1;i<=n;i++)
		{
			cin>>p.weight;
			p.num=i;
			que.push(p);
			tree[i].weight=p.weight;
		}
		int root = n;
		while(que.size()>1)
		{
			p1=que.top();
			que.pop();
			p2=que.top();
			que.pop();
			p.num=++root;
			p.weight=p1.weight+p2.weight;
			que.push(p);
			tree[root].weight=p.weight;
			tree[root].lchild=p2.num;
			tree[root].rchild=p1.num;
		}
		string sss="";
		buildTree(root, sss);
		printf("Case %d\n", ++icase);
		for(int i=1;i<=n;i++)
			cout<<tree[i].weight <<' '<<strSet[i]<<endl;
		cout<<endl;
	}

	return 0;
}

