#include<stdio.h>
int main()
{
	float fahr, celsius;		/*farh is the fahrenheit,celsius is the celsius*/
	float lower, upper, step;
	lower = -150;
	upper = 150;
	step = 20;
	celsius = lower;
	printf("Celsius-Fahrenheit table\n");
	while(celsius <= upper)
	{
		fahr = celsius * ( 9.0/5.0) + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}