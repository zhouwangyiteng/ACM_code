#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
#define MAXN 65536
int front, rear;
int que[MAXN*2];
bool used[MAXN];
int step[MAXN];
int path[MAXN];
vector<int> stack;

void bfs(int p)
{
	step[p] = 0;
	if(p==0)
	{
		cout << "0" << endl;
		return;
	}
	memset(path, 0, sizeof(path));
	memset(used, false, sizeof(used));
	front = rear = 0;
	que[rear++] = p;
	used[p] = true;
	path[p] = -1;
	while(front<rear)
	{
		int tmp = que[front++];
		int t = tmp;
		for(int i=0; i<16; i++)
		{
			tmp = t;
			tmp ^= 1<<(15-i);
			switch(i/4)
			{
			case 0: tmp ^= 0xF000;break;
			case 1: tmp ^= 0xF00;break;
			case 2: tmp ^= 0xF0;break;
			case 3: tmp ^= 15;break;
			} 
			switch(i%4)
			{
			case 0: tmp ^= 0x8888;break;
			case 1: tmp ^= 0x4444;break;
			case 2: tmp ^= 0x2222;break;
			case 3: tmp ^= 0x1111;break;
			} 
			if(tmp==0)
			{
				cout << step[t]+1 << endl;
				while(t!=-1)
				{	
					int index = 0;
					int r = tmp^t;
					if(r>>12==15)
					{
						int k = r/0xFF;
						if(k==0xF9) index+=1;
						else if(k==0xF5) index+=2;
						else if(k==0xF3) index+=3;
						else index+= 4;
						index+=10;
					}
					else 
					{
						int k = r/0xFFF;
						if(k==8) index+=1;
						else if(k==4) index+=2;
						else if(k==2) index+=3;
						else index+=4;
						if((r>>8)%0x10==0xF) index+=20;
						else if((r>>4)%0x10==0xF) index+=30;
						else index+=40;
					}
					stack.push_back(index);
					tmp = t;
					t = path[t];
				}
				for(int k=stack.size()-1; k>=0; k--)
				{
					cout << stack[k]/10 << ' ' << stack[k]%10 << endl;
				}
				return;
			}
			if(used[tmp]==false)
			{
				que[rear++] = tmp;
				used[tmp] = true;
				step[tmp] = step[t] + 1;
				path[tmp] = t;
			}
		}
	}
}

int main()
{
    int i,j;
	int id=0;
    char handle;
    for(i=0; i<4; i++)
    	for(j=0; j<4; j++)
    	{
			cin >> handle;
			id<<=1;
			if(handle=='+')
				id += 1;
		}
	bfs(id);
	return 0;  
}    
 
