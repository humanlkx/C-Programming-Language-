#include<stdio.h>

#define IN 0 /* in the word*/
#define OUT 1 /* out the word*/

int main()
{
	int flag;/*in or out the word*/
	int ch;
	flag = IN;
	while((ch = getchar()) != EOF)
	{
		if(ch == ' ' || ch == '\n' || ch == '\t')
		{
			if(flag == IN)
				putchar('\n');
			flag = OUT;
		}
		else
		{
			flag = IN;
			putchar(ch);
		}
	}
	return 0;
}