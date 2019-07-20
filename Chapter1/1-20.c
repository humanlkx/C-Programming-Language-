#include<stdio.h>
#define MAXLINES 1000 /* maximum input line length */
#define N 8/*the c's of the tap*/

int getlines(char line[], int maxline);
void detap(char source[]);

int main()
{
	int len; /*current line length*/
	char line[MAXLINES]; /* current input line */

	while((len = getlines(line, MAXLINES)) > 0 )
	{
			detap(line);
			printf("%s", line);
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

/* detap: detap 's'  */
void detap(char s[])
{	
	char result[MAXLINES];
	int i = 0;
	int j = 0;
	while( (result[i] = s[i]) != '\0')
		i++;
	i =0;
	int count = 0;/*count the num of c*/
	while( result[i] != '\0' && j < MAXLINES)
	{
		if (result[i] != '\t')
		{
			s[j] = result[i];
			j++;
			count++;
			if (count >= 8)
			{
				count = 0;
			}
		}
		else
		{
			count = N - count;
			for ( ; count > 0; count--)
			{
				s[j] = ' ';
				j++;
			}
		}
		i++;
	}
	s[j] = result[i];
	if (j >= MAXLINES)
	{
		s[MAXLINES] = '\0';
	}
}