/*************************************************************************
	> File Name: ICPC2016beijing/A.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月24日 星期六 12时40分18秒
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

typedef struct node
{
	string name;
	int num;
	struct node *child[35];
}Node;
Node *root;
vector<string> str;
string chs;

Node *createNew(string str)
{
    Node *p=new Node;
    p->name=str;
    for(int i=0;i<31;i++)
    {
        p->child[i]=NULL;
    }
    p->num=0;
    return p;
}

void Insert()
{
	Node *p=root;
	int n=str.size();
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=1;j<=p->num;j++)
			if(p->child[j]->name==str[i])
				break;
		if(j>p->num||(i<n-1&&p->child[j]->num==0)||(i==n-1&&p->child[j]->num>0))
		{
			p->num++;
			p->child[p->num]=createNew(str[i]);
			j=p->num;
		}
		p=p->child[j];
	}
}

int dealNode(Node* T)
{
    int i;
    if(T==NULL)
        return 0;
    for(i=0;i<=T->num;i++)
    {
        if(T->child[i]!=NULL)
            dealNode(T->child[i]);
    }
    free(T);
    return 0;
}

bool cmp(Node *a,node *b)
{
	if(((a->num>0)&&(b->num>0))||((a->num==0)&&(b->num==0)))
		return (a->name)<(b->name);
	else
		return (a->num)>(b->num);
}

void showchild(Node *t,int sp)
{
	if(t==NULL)
		return;
	for(int i=0;i<4*sp;i++)
		printf(" ");
	cout<<t->name<<endl;
	int n=t->num;
	sort((t->child)+1,(t->child)+1+n,cmp);
	for(int i=1;i<=n;i++)
		showchild(t->child[i],sp+1);
}
void show()
{
	sort((root->child)+1,(root->child)+1+root->num,cmp);
	for(int i=1;i<=root->num;i++)
		showchild(root->child[i],0);
}

vector<string> split(string str,string pattern)  
{  
    string::size_type pos;  
    vector<string> result;  
    str+=pattern; 
    int size=str.size();  
  
    for(int i=0; i<size; i++)  
    {  
        pos=str.find(pattern,i);  
        if(pos<size)  
        {  
            string s=str.substr(i,pos-i);  
            result.push_back(s);  
            i=pos+pattern.size()-1;  
        }  
    }  
    return result;  
}  

int main()
{
	int icase=0;
	string chss;
	root=createNew("");
	while(getline(cin,chss))
	{
		if(chss.size()==1&&chss[0]=='0')
		{
			printf("Case %d:\n",++icase);
			show();
			dealNode(root);
			root=createNew("");
			continue;
		}
		chs="";
		for(int i=0;i<chss.size();i++)
			if(chss[i]!=' ')
				chs+=chss[i];
		str.clear();
		str=split(chs,string("/"));
		Insert();
	}
	
	return 0;
}

