#include<stdio.h>
#define MAXLINES 1000 /* maximum input line length */
#define N 8/*the c's of the tap*/
#define IN 1/*in the space list*/
#define OUT 0 /*out the space list*/

int getlines(char line[], int maxline);
void entap(char source[]);

int main()
{
	int len; /*current line length*/
	char line[MAXLINES]; /* current input line */

	while((len = getlines(line, MAXLINES)) > 0 )
	{
			entap(line);
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

/* entap: entap 's'  */
void entap(char s[])
{	
	char result[MAXLINES];
	int i = 0;
	int j = 0;
	while( (result[i] = s[i]) != '\0')
		i++;
	i =0;
	int count = 0;/*count the num of c*/
	int temp = 0; /*story the index of the first space*/
	int flag;
	flag = OUT;

	while( result[i] != '\0')
	{
		if (result[i] != ' ' )
		{	
			flag = OUT;
			s[j] = result[i];
			count++;
			temp = j + 1;/*temp is always story the first space*/
			if (count >= 8 || s[j] == '\t')
			{
				count = 0;
			}
		}
		else
		{
			count++;
			flag = IN;
			s[j] = result[i];
		}
		if (count >= 8 && flag == IN)
		{
			flag = OUT;
			count = 0;
			j = temp;
			s[j] = '\t';
		}
		j++;
		i++;
	}
	s[j] = '\0';
}