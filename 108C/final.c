#include <stdio.h>
int fn(int,int);
int main (void)
{
	int a=3, b=3, c=0;
	c = fn(a,b);
	printf("\n\nc is %d",c);
	return 0;
}
int fn (int a, int b)
{
	if (b==1)
		return b;
	else
		return (a * fn(a, b-1));
}
