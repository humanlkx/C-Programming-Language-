#include<stdio.h>

float TemTran(float ceil);

int main()
{
	float falh;
	falh = 0.0;
	float upper, lower;
	int step;
	upper = 300.0;
	step = 20;
	for (lower = 0;  lower <= upper; lower += step)
	{
		falh = TemTran(lower);
		printf("%3.0f  \t %6.1f\n",lower, falh );
	}
	return 0;
}
float TemTran(float ceil)
{
	float falh;
	falh = ceil * 9.0 / 5.0 + 32.0;
	return falh;
}