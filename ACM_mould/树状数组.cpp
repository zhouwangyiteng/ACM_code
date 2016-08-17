//数组下标为1~n
int b[N];
int n;

int lowbit(int i)
{
	return i&-i;
}

int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=b[i];
		i-=lowbit(i);
	}
	return s;
}

void add(int i,int x)
{
	while(i<=n)
	{
		b[i]+=x;
		i+=lowbit(i);
	}
}
