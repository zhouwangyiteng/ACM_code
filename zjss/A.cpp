/*************************************************************************
	> File Name: A.cpp
	> Author:
	> Mail:
	> Created Time: 2017年04月22日 星期六 13时35分31秒
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
#define N 150005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
using namespace std;

int a[2];
int t,n;

int main()
{
	cin>>t;
	while(t--){
		CLR(a,0);
		cin>>n;
		for(int i=0;i<n;i++){
			int tmp;
			cin>>tmp;
			if(tmp==1){
				a[0]++;
			}
			else if(tmp==2){
				a[1]++;
			}
			else if(tmp==3){
				a[0]++;
				a[1]++;
			}
			else{
				a[0]--;
				a[1]--;
			}
		}
		if(a[0]>a[1]){
			cout<<"Kobayashi"<<endl;
		}
		else if(a[1]>a[0]){
			cout<<"Tohru"<<endl;
		}
		else
			cout<<"Draw"<<endl;
	}

    return 0;
}

