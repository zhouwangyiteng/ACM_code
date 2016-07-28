/*************************************************************************
	> File Name: 1011.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月28日 星期四 12时10分21秒
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
#define N 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

map<string,int> dict;

char a[][31]={"Cleveland Cavaliers","Golden State Warriors","San Antonio Spurs",
"Miami Heat","Miami Heat","Dallas Mavericks","L.A. Lakers","L.A. Lakers","Boston Celtics",
"San Antonio Spurs","Miami Heat","San Antonio Spurs","Detroit Pistons","San Antonio Spurs",
"L.A. Lakers","L.A. Lakers","L.A. Lakers","San Antonio Spurs","Chicago Bulls","Chicago Bulls",
"Chicago Bulls","Houston Rockets","Houston Rockets","Chicago Bulls","Chicago Bulls","Chicago Bulls",
"Detroit Pistons","Detroit Pistons","L.A. Lakers","L.A. Lakers","Boston Celtics","L.A. Lakers","Boston Celtics",
"Philadelphia 76ers","L.A. Lakers","Boston Celtics","L.A. Lakers","Seattle Sonics","Washington Bullets","Portland Trail Blazers",
"Boston Celtics","Golden State Warriors","Boston Celtics","New York Knicks","L.A. Lakers","Milwaukee Bucks",
"New York Knicks","Boston Celtics","Boston Celtics","Philadelphia 76ers","Boston Celtics","Boston Celtics",
"Boston Celtics","Boston Celtics","Boston Celtics","Boston Celtics","Boston Celtics","Boston Celtics",
"St. Louis Hawks","Boston Celtics","Philadelphia Warriors","Syracuse Nats","Minneapolis Lakers","Minneapolis Lakers",
"Minneapolis Lakers","Rochester Royals","Minneapolis Lakers","Minneapolis Lakers","Baltimore Bullets","Philadelphia Warriors"};

int t;
char word[35];

int main()
{
	int i=0;
	while(strlen(a[i])>0)
	{
		dict[a[i]]++;
		i++;
	}
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;i++)
	{
		gets(word);
		cout<<"Case #"<<i+1<<": ";
		cout<<dict[word]<<endl;
	}


	return 0;
}

