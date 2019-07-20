#include<stdio.h>

int main()
{
	int flag;/*if has space the flag = 1;*/
	int ch;
	flag = 0;
	while( (ch = getchar()) != EOF)
	{
		if( ch == ' ' && flag == 0)
		{
			flag = 1;
			putchar(ch);
		}
		if( ch != ' ')
		{
			flag = 0;
			putchar(ch);
		}
	}
	return 0;
}