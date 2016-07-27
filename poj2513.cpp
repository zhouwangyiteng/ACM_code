/*************************************************************************
	> File Name: poj2513.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月27日 星期三 09时24分38秒
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
#define N 250005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

char w1[11],w2[11];
int d[2*N];
int p[2*N];
bool vis[2*N];
int cnt=0;

typedef struct trieNode
{
	struct trieNode* next[26];
	int id;
}TrieNode,*Trie;

TrieNode* creatTrieNode()
{
	TrieNode* node=(TrieNode*)malloc(sizeof(TrieNode));
	node->id=0;
	memset(node->next,0,sizeof(node->next));
	return node;
}

int trieInsert(Trie root,char *word)
{
	Trie node=root;
	char *p=word;
	int i;
	while(*p)
	{
		i=*p-'a';
		if(node->next[i]==NULL)
			node->next[i]=creatTrieNode();
		node=node->next[i];
		++p;
	}
	if(node->id==0)
		node->id=++cnt;
	return node->id;
}

int delTrie(trieNode *root)
{
	int i;
	if(root==NULL)
		return 0;
	for(i=0;i<26;i++)
	{
		if(root->next[i]!=NULL)
			delTrie(root->next[i]);
	}
	free(root);
	return 0;

}

int findp(int i)
{
	while(p[i]>=0)
		i=p[i];
	return i;
}

void Union(int i,int j)
{
	int pi=findp(i);
	int pj=findp(j);
	if(pi==pj)
		return;
	p[pj]=pi;
}


int main()
{
	CLR(vis,0);
	CLR(d,0);
	CLR(p,-1);
	Trie root=creatTrieNode();
	while(scanf("%s %s",w1,w2)!=EOF)
	{
		int i=trieInsert(root,w1);
		int j=trieInsert(root,w2);
		// cout<<i<<' '<<j<<' '<<cnt<<endl;
		Union(i,j);
		vis[i]=vis[j]=1;
		d[i]++;
		d[j]++;
	}
    int num=0;
  	int flag=0;
    for(int i=1;i<=cnt;i++)  
    {  
        if(d[i]%2==1)  
            num++;              
        if(num>2) 
        {  
            cout<<"Impossible"<<endl;  
            return 0;  
        }  
        if(p[i]<0&&vis[i])
        	flag++;
        if(flag>1)
        {
        	cout<<"Impossible"<<endl;  
            return 0;  
        }
    }  
    if(num==1) 
        cout<<"Impossible"<<endl;  
    else
        cout<<"Possible"<<endl; 

	return 0;
}

