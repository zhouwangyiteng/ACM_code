/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-09-01 09:56:08

 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define ll long long
#define inf 0xfffff
#define MAX 25500
int p[510],n,m,s,kk,flag;
struct e
{
    int a,b,c;
};
e path[MAX];
bool cmp(const e &a, const e &b)
{
	return a.c<b.c;
}

int find(int x)
{
    while(p[x]!=x)
        x=p[x];
    return x;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&kk);
        for(int i=1;i<=n;i++)
        p[i]=i;

        int aa,bb,cc;
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&path[i].a,&path[i].b,&path[i].c);

        for(int i=0;i<kk;i++)
        {
            int op,st,te;
            scanf("%d",&op);
            scanf("%d",&st);
            for(int j=1;j<op;j++)
            {
                scanf("%d",&te);
                p[find(te)]=p[find(st)];
                st=te;
            }
        }

        int sum=0;flag=0;

        for(int i=1;i<=n;i++)
        {if(p[i]==i) flag++; //通过判断是几个祖先
        }
        sort(path+1,path+m+1,cmp);

        for(int i=1;i<=m&&flag>1;i++)  //如果c==1则已经生成
        {
            int dx=find(path[i].a);
            int dy=find(path[i].b);
            if(dx!=dy)
            {
                sum+=path[i].c;
                p[dx]=dy;
                flag--;
            }

        }

    if(flag==1)
        printf("%d\n",sum);
    else
         printf("-1\n");
    }
}