
void getNext()
{
	int j=-1;
	next[0]=-1;
	for(int i=0;i<n;)
		if(j==-1||str[i]==str[j])
			next[++i]=++j;
		else
			j=next[j];
}
