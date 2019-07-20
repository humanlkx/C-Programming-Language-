//
// Created by csu on 19-4-27.
//
// this only print the alpha-fre >= 1
#include<stdio.h>
int main()
{
    int alpha[128]; /* the ascii has 128 char*/
    int ch;
    int i, j;
    for( i = 0 ; i <= 128; i++ )
    {
        alpha[i] = 0;
    }
    while( (ch = getchar()) != EOF)
    {
        alpha[ch]++;
    }
    for ( i = 0; i <=128 ; ++i)
    {
        if(alpha[i] >0)
	{	
        putchar(i);
		for ( j = 1; j <= alpha[i] ; ++j)
        	{
            	printf("*");
        	}
        printf("\n");
    }
    }
    return 0;

}
