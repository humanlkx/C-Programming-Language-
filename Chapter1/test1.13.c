#include<stdio.h>

#define IN 0
#define OUT 1

int main()
{
	int lenWord[10] = { 0 };/* 存储最多10个单词长度值*/
	char word[10][100] = { '\0' };/*每个单词不得长于100*/
	int ch, flag, nword;
	flag = OUT;
	nword = 0;
	int i = 0;
	while((ch = getchar()) != EOF)
	{
		if(ch == ' ' || ch == '\n' || ch == '\t')
		{
			if(flag == IN)
			{
				nword++;
				i = 0;
			}
			flag = OUT;
		}
		else
		{
			flag = IN;
			lenWord[nword]++;
			word[nword][i] = ch;
			i++;
		}
		if(nword > 9)
			break;
	}
	for(i = 0; i <= nword; i++)
	{
		int j = 0;
		printf("%s: ", word[i]);
		for (; j < lenWord[i]; ++j)
			printf("*");
		printf("\n");
	}
	return 0;
}