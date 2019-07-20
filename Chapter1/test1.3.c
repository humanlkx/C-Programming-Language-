#include<stdio.h>
int main()
{
	float fahr, celsius;		/*farh is the fahrenheit,celsius is the celsius*/
	float lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	printf("Fahrenheit-Celsius inv-table\n");
	while(fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}