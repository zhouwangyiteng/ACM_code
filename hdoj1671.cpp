/*************************************************************************
	> File Name: hdoj1671.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月26日 星期二 10时42分08秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 65536

typedef struct trieNode
{
	int count;
	struct trieNode* next[10];
	bool exist;
}TrieNode,*Trie;

TrieNode* creatTrieNode()
{
	TrieNode* node=(TrieNode*)malloc(sizeof(TrieNode));
	node->count=0;
	node->exist=false;
	memset(node->next,0,sizeof(node->next));
	return node;
}

bool trieInsert(Trie root,char *word)
{
	Trie node=root;
	char *p=word;
	int id;
	bool flag=1;
	while(*p)
	{
		id=*p-'0';
		if(node->next[id]==NULL)
		{
			flag=0;
			node->next[id]=creatTrieNode();
		}
		node=node->next[id];
		if(node->exist)
			return false;
		++p;
		node->count+=1;
	}
	node->exist=true;
	if(flag)
		return false;
	return true;
}

int delTrie(trieNode *root)
{
	int i;
	if(root==NULL)
		return 0;
	for(i=0;i<10;i++)
	{
		if(root->next[i]!=NULL)
			delTrie(root->next[i]);
	}
	free(root);
	return 0;

}

int t,n;
char str[15];
int flag;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
    	Trie root=creatTrieNode();
    	flag=1;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			if(flag)
				flag=trieInsert(root,str);
		}
		delTrie(root);
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}
    
    
	return 0;  
}    
