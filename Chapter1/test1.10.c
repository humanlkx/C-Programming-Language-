#include<stdio.h>

int main()
{
	int ch;
	while( (ch = getchar()) != EOF)
	{
		if( ch == '\t')
		{
			putchar('\\');
			putchar('t');
		}
		else if( ch == '\b')
		{
			putchar('\\');
			putchar('b');
		}
		else if( ch == '\\')
		{
			putchar('\\');
			putchar('\\');
		}
		else
			putchar(ch);
	}
	return 0;
}