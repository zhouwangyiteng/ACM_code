#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define MAXN 65536
bool find0;
int front, rear;
int que[MAXN*2];
bool used[MAXN];
int step[MAXN];

void bfs(int p)
{
	find0 = false;
	step[p] = 0;
	if(p==0||p==65535)
	{
		cout << "0" << endl;
		find0 = true;
		return;
	}
	memset(used, false, sizeof(used));
	front = rear = 0;
	que[rear++] = p;
	used[p] = true;
	while(front<rear)
	{
		int tmp = que[front++];
		int t = tmp;
		for(int i=0; i<16; i++)
		{
			tmp = t;
			tmp^=1<<(15-i);
			if(i%4==0)
				tmp^=1<<(14-i);
			else if(i%4==3)
				tmp^=1<<(16-i);
			else
				tmp^=5<<(14-i);
			if(i<4)
				tmp^=1<<(11-i);
			else if(i>11)
				tmp^=1<<(19-i);
			else
			{
				tmp^=1<<(11-i);
				tmp^=1<<(19-i);
			}
			if(tmp==0||tmp==65535)
			{
				cout << step[t]+1 << endl;
				find0 = true;
				return;
			}
			if(used[tmp]==false)
			{
				que[rear++] = tmp;
				used[tmp] = true;
				step[tmp] = step[t] + 1;
			}
		}
	}
}

int main()
{
    int i,j;
	int id=0;
    char color;
    for(i=0; i<4; i++)
    	for(j=0; j<4; j++)
    	{
			cin >> color;
			id<<=1;
			if(color=='b')
				id += 1;
		}
	bfs(id);
	if(find0==false)
		cout << "Impossible" << endl;
    
	return 0;  
}    
 
