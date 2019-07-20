#include<stdio.h>
#define MAXLINES 1000 /* maximum input line length */

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len; /*current line length*/
	int count;/* count the num of the line-length > 80*/
	char line[MAXLINES]; /* current input line */
	char longs[MAXLINES][MAXLINES]; /* linelength > 80 line save here */

	count= 0;
	while((len = getlines(line, MAXLINES)) > 0 )
		if(len > 80)
		{
			copy(longs[count], line);
			count++;
		}
	if(count > 0) /*there was a line*/
		for (int i = 0; i < count; ++i)
			printf("%s", longs[i]);
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

/* copy: copy 'from' into 'to'; assume to this big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while( (to[i] = from[i]) != '\0')
		++i;
}