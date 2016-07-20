#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 3003

typedef struct trieNode
{
	int count;
	struct trieNode* next[26];
	bool exist;
	char trans[11];
}TrieNode,*Trie;

TrieNode* creatTrieNode()
{
	TrieNode* node=(TrieNode*)malloc(sizeof(TrieNode));
	node->count=0;
	node->exist=false;
	memset(node->next,0,sizeof(node->next));
	return node;
}

void trieInsert(Trie root,char *word,char *trans)
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
	strcpy(node->trans,trans);
}

char* trieSearch(Trie root,char* word)
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
	if(node->exist)
		return node->trans;
	else
		return NULL;
}

int main()
{
    Trie root=creatTrieNode();
    char str1[MAXN],str2[MAXN],str[MAXN],*p;
    int i,k;
    scanf("%s",str1);
    while(scanf("%s",str1)&&strcmp(str1,"END")!=0)
    {
		scanf("%s",str2);
		trieInsert(root,str2,str1);
	}
	getchar();
	gets(str1);
	k=0;
	while(gets(str1))
	{
		if(strcmp(str1,"END")==0)
			break;
		for(i=0;str1[i]!='\0';i++)
			if(str1[i]>='a'&&str1[i]<='z')
				str[k++]=str1[i];
			else
			{
				str[k]='\0';
				p=trieSearch(root,str);
				if(p)
					printf("%s",p);
				else
					printf("%s",str);
				k=0;
				cout<<str1[i];
			}
		cout<<endl;
	}
    
	return 0;  
}    
