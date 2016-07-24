/*************************************************************************
	> File Name: hdoj1025.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月24日 星期日 20时43分43秒
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
#define N 500005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N],b[N];

//用二分查找的方法找到一个位置，使得num>b[i-1] 并且num<b[i],并用num代替b[i]
int Search(int num,int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(num>=b[mid])  low=mid+1;
        else   high=mid-1;
    } 
    return low;   
}    
int DP(int n)
{
    int i,len,pos;
    b[1]=a[1];
    len=1;
    for(i=2;i<=n;i++)
    {
        if(a[i]>=b[len])//如果a[i]比b[]数组中最大还大直接插入到后面即可
        {
            len=len+1;
            b[len]=a[i];
        }    
        else//用二分的方法在b[]数组中找出第一个比a[i]大的位置并且让a[i]替代这个位置
        {
            pos=Search(a[i],1,len);
            b[pos]=a[i];
        }    
    }    
    return len;
}    
int main()
{
    
    int n;
    int iCase=0;
    int i,j;
    int x,y;
    while(scanf("%d",&n)!=EOF)
    {
        iCase++;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            a[x]=y;
        }    
        int res=DP(n);
        printf("Case %d:\n",iCase);
        if(res==1)
        {
            printf("My king, at most 1 road can be built.\n\n");
        }   
        else 
            printf("My king, at most %d roads can be built.\n\n",res);
    }
    return 0;    
}
