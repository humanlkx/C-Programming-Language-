#include<stdio.h>
#define MAXLINES 1000 /* maximum input line length */

int getlines(char line[], int maxline);
void reverse(char source[]);

int main()
{
	int len; /*current line length*/
	char line[MAXLINES]; /* current input line */

	while((len = getlines(line, MAXLINES)) > 0 )
	{
		if (len > 0)
		{
			reverse(line);
			printf("%s", line);
		}
	}
	return 0;
}

/* getline: read a line into s, return length */
int getlines(char s[], int lim)
{
	int c, j;
	for (j = 0; j< lim - 1 && ( c = getchar()) != EOF && c != '\n'; ++j)
		s[j] = c;
	if(c == '\n')
	{
		s[j] = c;
		++j;
	}
	s[j] = '\0';
	return j;
}

/* reverse: reverse 's'  */
void reverse(char s[])
{
	char temp[MAXLINES];
	int i, j;
	i = j = 0;
	while( (temp[i] = s[i]) != '\n' )
	{
		i++;
	}
	for ( ; j < i; i--, j++)
	{
		s[j] = temp[i - 1];
		s[i - 1] = temp[j];
	}
}