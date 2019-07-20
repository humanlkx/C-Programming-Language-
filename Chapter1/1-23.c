#include<stdio.h>
#define MAXLINES 1000 /* maximum input program length */
#define IN 1/*in the \" or in the comment list*/
#define OUT 0 /*out the \" or out the comment list*/

int GetProgram(char line[], int maxline);
void DeleteComment(char source[]);

int main()
{
	int len; /*current program length*/
	char program[MAXLINES]; /* current input line */

	while((len = GetProgram(program, MAXLINES)) > 0 )
	{
			DeleteComment(program);
			printf("%s", program);
	}
	return 0;
}

/* getline: read a program into s, return length */
int GetProgram(char s[], int lim)
{
	int c, j;
	for (j = 0; j< lim - 1 && ( c = getchar()) != EOF; ++j)
		s[j] = c;
	s[j] = '\0';
	return j;
}

/* DeleteComment: delete 's' comments  */
void DeleteComment(char s[])
{	
	int i = 0;
	int j = 0;
	int flag;/* whether in the \"*/
	int state; /* whether in the comment*/
	state = OUT;
	flag = OUT;

	for ( ; s[i] != '\0' && j < MAXLINES; ++i)
	{
		/* in or out the \"" */
		if (s[i] == '\"' && flag == OUT)
		{
			flag = IN;
		}
		else if(s[i] == '\"' && flag == IN)
		{
			flag = OUT;
		}
		/* delete the comment */
		if( s[i] == '/' && s[i + 1] == '*' && flag == OUT)
			state = IN;
		if( s [i] == '*' && s[i + 1] == '/' && state == IN)
			{
				state = OUT;
				i += 2;
			}
		if( state == OUT)
		{
			s[j] = s[i];
			j++;
		}
	}
	s[j] = '\0';
}