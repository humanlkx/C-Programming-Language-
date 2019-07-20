#include<stdio.h>
int main()
{
	int nSpace, nTap, nn;
	int ch;
	nSpace = nTap = nn = 0;
	while((ch = getchar()) != EOF)
	{
		if( ch == ' ')
			nSpace++;
		if( ch == '\t')
			nTap++;
		if( ch == '\n')
			nn++;
	}
	printf("%d %d %d\n",nSpace, nTap, nn );
	return 0;
}