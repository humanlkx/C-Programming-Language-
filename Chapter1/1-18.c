#include<stdio.h>
#define MAXLINES 1000 /* maximum input line length */

int getlines(char line[], int maxline);
int deletes(char source[], int length);

int main()
{
	int len; /*current line length*/
	int count;/* count the num of the line-length */
	char line[MAXLINES]; /* current input line */
	count = 0;

	while((len = getlines(line, MAXLINES)) > 0 )
	{
		count = deletes(line, len - 2);
		if (count > 0)
		{
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

/* delete: delete space of 's'  */
int deletes(char s[], int length)
{
	while (length >= 0)
	{
		if (s[length] == ' ' || s[length] == '\t')
		{
			s[length] = s[length + 1];
			s[length + 1] = '\0';
			length--;
		}
		else
			break;
	}
	return length + 1;
}