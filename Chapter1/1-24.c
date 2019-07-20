#include<stdio.h>
#define MAXLINES 10000 /* maximum input program length */
#define IN 1/*in the space list*/
#define OUT 0 /*out the space list*/

/* the parathese, brackets, braces, sQuotes, dQuotes, comments restory these matches,
	if they matches, they still equal 0,*/
int paretheses, brackets, braces, sQuotes, dQuotes, comments;

int GetProgram(char line[], int maxline);
void check(char s[]);/* check the error*/

int main()
{
	int len; /*current program length*/
	char program[MAXLINES]; /* current input line */

	extern int paretheses, brackets, braces, sQuotes, dQuotes, comments;
	paretheses = braces = brackets = sQuotes = dQuotes = comments = 0;

	if((len = GetProgram(program, MAXLINES)) > 0 )
		check(program);
	if (paretheses != 0)
		printf("error !  paretheses unmatch!\n");
	if (brackets != 0)
		printf("error !  brackets unmatch!\n");
	if (braces != 0)
		printf("error !  braces unmatch!\n");
	if (sQuotes != 0) 
		printf("error !  sQuotes  unmatch!\n");
	if (dQuotes != 0)
		printf("error !  dQuotes unmatch!\n");
	if (comments != 0)
		printf("error !  comments unmatch!\n");
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

/* check: check the syntax error  */
void check(char s[])
{	
	extern int paretheses, brackets, braces, sQuotes, dQuotes, comments;
	int state, flag;
	int i;
	flag = OUT;
	state = OUT;
	for ( i = 0 ; s[i] != '\0' ; ++i)
	{
		if (s[i] == '\"' && flag == OUT)/*check the dQuotes*/
		{
			flag = IN;
			dQuotes++;
		}
		else if(s[i] == '\"' && flag == IN)
		{
			flag = OUT;
			dQuotes--;
		}
		else if (s[i] == '\'' && flag == OUT)/*check the sQuotes*/
		{
			if (s[i + 1] == '\\' )
				{
					if(s[i+2] != 't' || s[i+2] != 'a' || s[i+2] != 'b' || s[i+2] != 'n' && s[i + 3] != '\'')
			 			sQuotes++;
				}
			else if (s[i + 2] != '\'')
				sQuotes++;
		}
		else if( s[i] == '/' && s[i + 1] == '*' && flag == OUT)/*check the comments*/
			comments++;
		else if( s [i] == '*' && s[i + 1] == '/' && flag == OUT)
			comments--;
		else if (s[i] == '{')/* check the parentheses brackets braces*/
			paretheses++;
		else if (s[i] == '}')
			paretheses--;
		else if (s[i] == '[')
			brackets++;
		else if (s[i] == ']')
			brackets--;
		else if (s[i] == '(')
			braces++;
		else if (s[i] == ')')
			braces--;
	}
}