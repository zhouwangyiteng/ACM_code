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
	struct trieNode* next[26];
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

void trieInsert(Trie root,char *word)
{
	Trie node=root;
	char *p=word;
	int id;
	while(*p)
	{
		id=*p-'a';
		if(node->next[id]==NULL)
			node->next[id]=creatTrieNode();
		node=node->next[id];
		++p;
		node->count+=1;
	}
	node->exist=true;
}

int trieSearch(Trie root,char* word)
{
	Trie node=root;
	char *p=word;
	int id;
	while(*p)
	{
		id=*p-'a';
		node=node->next[id];
		++p;
		if(node==NULL)
			return 0;
	}
	return node->count;
}

int main()
{
    Trie root=creatTrieNode();
    char str[12];
    bool flag=false;
    while(gets(str))
    {
		if(flag)
			cout<<trieSearch(root,str)<<endl;
		else
			if(strlen(str)!=0)
				trieInsert(root,str);
			else
				flag=true;
	}
    
	return 0;  
}    
